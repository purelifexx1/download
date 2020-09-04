#include "modbus.h"

modbus::modbus()
{
	
}

void modbus::begin(UART_HandleTypeDef* uart, receive_modbus)
{
	this->uart = uart;
	this->callback = callback;
	uart_dma(this->uart, data_buffer, buffer_length);
}

void modbus::CRC_16(byte* input, byte Length, byte* output)
{
	uint16_t reg_crc = 0xffff;
	for(byte i = 0; i< Length; i++) {
		reg_crc ^= input[i];
		for(byte j = 0; j < 8; j++) {
			if((reg_crc & 0x0001) == 1) reg_crc = (uint16_t)((reg_crc >> 1) ^ 0xA001);
			else reg_crc = (uint16_t)(reg_crc >> 1);
		}
	}
	output[1] = (byte)((reg_crc >> 8) & 0xff);
	output[0] = (byte)(reg_crc & 0xff);	
}

void modbus::looping()
{
	write_pointer = buffer_length - (byte)(uart->hdmarx->Instance->CNDTR);
	if(sync_status == false && (byte)(write_pointer - read_pointer) >= sync_number) {
		if(data_buffer[read_pointer++] == header[0] && data_buffer[read_pointer++] == header[1]) {
			if(fixed_receive_length == true) receive_length = data_buffer[read_pointer++];
			sync_status = true;
		}else{
			read_pointer++;
		}
		overflow_flag = false;
	}else if(sync_status == true && (byte)(write_pointer - read_pointer) >= receive_length + 2) {
		if (fixed_receive_length == true) CRC_16(&data_buffer[read_pointer-3], receive_length + 3, footer);
		else CRC_16(&data_buffer[read_pointer-2], receive_length + 2, footer);
		
		if(data_buffer[(byte)(write_pointer-2)] == footer[0] && data_buffer[(byte)(write_pointer-1)] == footer[1]){
			sync_status = false;
			if(overflow_flag == true)
				memcpy(&data_buffer[256], data_buffer, write_pointer);
			this->callback(&data_buffer[read_pointer], receive_length);
			read_pointer+=(receive_length + 2);
			overflow_flag = false;
		}else{
			//error handle packet format
			overflow_flag = false;
		}
	}
}



void modbus::request_handler(byte* input, int length)
{
	packet_id = input[0];
	header[0] = input[1];
	header[1] = input[2];
	if(header[1] <= 4) {
		sync_number = 3;
		fixed_receive_length = true;
	}else {
		sync_number = 2;
		fixed_receive_length = false;
		receive_length = 4;
	}	
	transmit_complete_flag = 0;
	uart_send(this->uart, &input[1], length - 1);
}

void modbus::request_handler1(byte* input, int length)
{
	packet_id = input[0];
	uint16_t number_of_coil;
	uint16_t number_of_register;
	switch(input[2]) {
		case 1:
			number_of_coil = (packet[5] << 8) ^ packet[6];
			temper_length = (number_of_coil/8) + 6;// number of coil round up +1, +5 address and function code and length and CRC,
		break;
			
		case 4:
			number_of_register = (packet[5] << 8) ^ packet[6];
			temper_length = number_of_register*2 + 5;
		break;
		
		case 5:
			
			temper_length = 8;
		break;
	}
	uart_dma(this->uart, data_buffer, temper_length);
	transmit_complete_flag = 0;
	uart_send(this->uart, &input[1], length - 1);
	
}

void modbus::buffer_overflow()
{
	overflow_flag = true;
}

void modbus::get_data(byte* temp1, int* temp2)
{
	temp1 = data_buffer;
	temp2 = &temper_length;
}
byte data_buffer[300];
