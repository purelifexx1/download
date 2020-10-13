#include "modbus_handler.h"

modbus_handler::modbus_handler()
{

}
void modbus_handler::begin(uint16_t header, uint16_t footer)
{
	header_chunk[0] = header >> 8 & 0xff;
	header_chunk[1] = header & 0xff;
	footer_chunk[0] = footer >> 8 & 0xff;
	footer_chunk[1] = footer & 0xff;
}

void modbus_handler::request_packet_handler(byte* data_packet, int length)
{
    number_of_request = data_packet[0];
    array_of_request = new request_type[number_of_request];
    byte pos_pointer = 1;
    for(byte i = 0; i < number_of_request; i++){
        array_of_request[i].begin_configure(&data_packet[pos_pointer+1], data_packet[pos_pointer]);
        array_of_request[i].request_number = i;
        pos_pointer += data_packet[pos_pointer]+1;
    }
    //request first element
    current_request_number = 0;
    uart_dma(&huart3, array_of_request[current_request_number].response_packet, array_of_request[current_request_number].response_length);
    uart_send(&huart3, array_of_request[current_request_number].request_packet, array_of_request[current_request_number].request_length);
    TIM2->CNT = 0;
    TIM2->ARR = 49999;
    first_start = 2;
    start_timer(&htim2);
}

void modbus_handler::receive_handler(UART_HandleTypeDef *huart)
{
	HAL_UART_AbortReceive_IT(huart);
	array_of_request[current_request_number].is_data_received = true;
    if (current_request_number < number_of_request - 1)
    {

    	stop_timer(&htim2);

        //request the next one
        current_request_number++;
        uart_dma(&huart3, array_of_request[current_request_number].response_packet, array_of_request[current_request_number].response_length);
        //uart_send(&huart3, array_of_request[current_request_number].request_packet, array_of_request[current_request_number].request_length);
        TIM2->CNT = 0;
		TIM2->ARR = 49999;
		first_start = 2;
		start_timer(&htim2); //start timer for next request
    }else //done
    {
    	stop_timer(&htim2);
        package_data();
    }
}
void modbus_handler::package_data()
{
	total_byte = 0;
	byte current_pos = 5;
	byte total_valid_request = 0;
	for(byte i = 0; i < number_of_request; i++){
		if(array_of_request[i].is_data_valid()) {
			array_of_request[i].packet_encoding();
			memcpy(&reply_packet[current_pos], array_of_request[i].encoded_packet, array_of_request[i].encode_length);
			current_pos += array_of_request[i].encode_length;
			total_byte += array_of_request[i].encode_length;
			total_valid_request++;
		}
	}
	reply_packet[3] = 38; //packet id for complete data modbus
	if(total_valid_request == 0) {
		delete[] array_of_request;
		Serial.send_error(12345, 34567, '9'); //no modbus packet detected
		return;
	}else if(total_valid_request < number_of_request){
		reply_packet[3] = 23; //packet id for non complete data modbus
	}
	//byte *temper_packet = new byte[total_byte + 6];
	reply_packet[2] = total_byte + 2;
	reply_packet[4] = number_of_request;

	reply_packet[0] = header_chunk[0];
	reply_packet[1] = header_chunk[1];
	reply_packet[total_byte + 7 - 2] = footer_chunk[0];
	reply_packet[total_byte + 7 - 1] = footer_chunk[1];
	transmit_complete_flag = On_transmit;
	uart_send(&huart2, reply_packet, total_byte+7);
	//Serial.send_mul_modbus_packet(12345, 34567, reply_packet, total_byte + 5);
	//delete[] temper_packet;
	delete[] array_of_request;
}
void modbus_handler::timeout_handler()
{
	HAL_UART_AbortReceive_IT(&huart3);
	if (current_request_number < number_of_request - 1){
		stop_timer(&htim2);
		current_request_number++;
		uart_dma(&huart3, array_of_request[current_request_number].response_packet, array_of_request[current_request_number].response_length);
		uart_send(&huart3, array_of_request[current_request_number].request_packet, array_of_request[current_request_number].request_length);
		TIM2->CNT = 0;
		TIM2->ARR = 49999;
		first_start = 3;
		start_timer(&htim2);
	}else{
		stop_timer(&htim2);
		package_data();
	}
}
void modbus_handler::next_request()
{
	stop_timer(&htim2);
	uart_send(&huart3, array_of_request[current_request_number].request_packet, array_of_request[current_request_number].request_length);
	TIM2->CNT = 0;
	TIM2->ARR = 49999;
	first_start = 3;
	start_timer(&htim2); //start timeout for next request
}
void modbus_timeout() //global from timer interrupt
{
	if (modbus.first_start == 0){
		modbus.timeout_handler();
	}else if(modbus.first_start == 2){
		modbus.first_start = 1;
	}else if(modbus.first_start == 1){
		modbus.next_request();
	}else if(modbus.first_start == 3){
		modbus.first_start = 0;
	}

}
modbus_handler modbus;
