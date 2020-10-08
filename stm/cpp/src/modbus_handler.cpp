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
    current_request_number = 0;
    uart_dma(&huart3, array_of_request[current_request_number].response_packet, array_of_request[current_request_number].response_length);
    uart_send(&huart3, array_of_request[current_request_number].request_packet, array_of_request[current_request_number].request_length);
    
}

void modbus_handler::receive_handler(UART_HandleTypeDef *huart)
{
    HAL_UART_Abort_IT(huart);
    if (current_request_number < number_of_request - 1)
    {
        current_request_number++;
        uart_dma(&huart3, array_of_request[current_request_number].response_packet, array_of_request[current_request_number].response_length);
        uart_send(&huart3, array_of_request[current_request_number].request_packet, array_of_request[current_request_number].request_length);
    }else //done
    {
        byte total_byte = 0;
        for(byte i = 0; i < number_of_request; i++){
            total_byte += array_of_request[i].response_length;
        }
        byte *temper_packet = new byte[total_byte + 5];
        temper_packet[2] = total_byte;
        byte current_pos = 3;
        for(byte i = 0; i < number_of_request; i++) {
            memcpy(&temper_packet[current_pos], array_of_request[i].response_packet, array_of_request[i].response_length);
            current_pos += array_of_request[i].response_length;
        }
        Serial.send_mul_modbus_packet(23169, 34476, temper_packet, total_byte + 5);
        delete[] temper_packet;
        delete[] array_of_request;
    }
    
    
}