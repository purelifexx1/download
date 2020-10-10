#include "modbus_handler.h"

modbus_handler::modbus_handler()
{

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
    
}

void modbus_handler::receive_handler(UART_HandleTypeDef *huart)
{
	HAL_UART_AbortReceive_IT(huart);
    if (current_request_number < number_of_request - 1)
    {
        //request the next one
        current_request_number++;
        uart_dma(&huart3, array_of_request[current_request_number].response_packet, array_of_request[current_request_number].response_length);
        uart_send(&huart3, array_of_request[current_request_number].request_packet, array_of_request[current_request_number].request_length);
    }else //done
    {
        package_data();
    }
}
void modbus_handler::package_data()
{
	total_byte = 0;
	byte current_pos = 4;
	for(byte i = 0; i < number_of_request; i++){
		if(array_of_request[i].is_data_valid()) {
			array_of_request[i].packet_encoding();
			memcpy(&testing[current_pos], array_of_request[i].encoded_packet, array_of_request[i].encode_length);
			current_pos += array_of_request[i].encode_length;
		}
		total_byte += array_of_request[i].encode_length;
	}
	//byte *temper_packet = new byte[total_byte + 6];
	testing[2] = total_byte + 1;
	testing[3] = number_of_request;


	testing[0] = 0x30;
	testing[1] = 0x39;
	testing[total_byte + 6 - 2] = 0x87;
	testing[total_byte + 6 - 1] = 0x07;
	uart_send(&huart2, testing, total_byte+6);
	//Serial.send_mul_modbus_packet(12345, 34567, testing, total_byte + 5);
	//delete[] temper_packet;
	delete[] array_of_request;
}
modbus_handler modbus;
