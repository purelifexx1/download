/*
 * mySerial.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Admin
 */

#include "mySerial.h"
mySerial::mySerial()
{

}

void mySerial::begin(UART_HandleTypeDef* uart, uint16_t header, uint16_t footer, uart_received)
{
	this->header[0] = (byte)(header>>8 & 0xff);
	this->header[1] = (byte)(header & 0xff);
	this->footer[0] = (byte)(footer>>8 & 0xff);
	this->footer[1] = (byte)(footer & 0xff);
	this->uart = uart;
	this->callback = callback;
	uart_dma(this->uart, data_buffer, buffer_length);
}

void mySerial::looping()
{
	write_pointer = buffer_length - (byte)(uart->hdmarx->Instance->CNDTR);
	if(sync_status == false && (byte)(write_pointer - read_pointer) >= 3) {
		if(data_buffer[read_pointer++] == header[0] && data_buffer[read_pointer++] == header[1]) {
			receive_length = data_buffer[read_pointer++];
			sync_status = true;
		}else{
			read_pointer++;
		}
		overflow_flag = false;
	}else if(sync_status == true && (byte)(write_pointer - read_pointer) >= receive_length + 2) {
		if(data_buffer[(byte)(write_pointer-2)] == footer[0] && data_buffer[(byte)(write_pointer-1)] == footer[1]){
			sync_status = false;
			if(overflow_flag == true)
				memcpy(&data_buffer[256], data_buffer, write_pointer);
			this->callback(&data_buffer[read_pointer], receive_length);
			read_pointer+=(receive_length + 2);
			overflow_flag = false;
		}else{
			//error handle packet format
			sync_status = false;
			overflow_flag = false;
		}
	}
}

void mySerial::looping2()
{
	if(receive_complete_flag == On_received) {
		write_pointer = buffer_length - (byte)(uart->hdmarx->Instance->CNDTR);
		if(data_buffer[read_pointer] == header[0] && data_buffer[(byte)(read_pointer+1)] == header[1] && data_buffer[(byte)(write_pointer-2)] == footer[0] && data_buffer[(byte)(write_pointer-1)] == footer[1]){
			if(data_buffer[(byte)(read_pointer+2)] == ((byte)(write_pointer - read_pointer) - 5)) {
				if(overflow_flag == true)
					memcpy(&data_buffer[256], data_buffer, write_pointer);
				//length_error_integral = 0; head_foot_error_integral = 0;
				overflow_flag = false;
				packet_id = data_buffer[(byte)(read_pointer+3)];
				this->callback(&data_buffer[(byte)(read_pointer+3)], data_buffer[(byte)(read_pointer+2)]);				
				read_pointer = write_pointer;
				return;
			}else{
				//packet length error
				error_debug_buffer[0] = write_pointer;
				error_debug_buffer[1] = read_pointer;
				error_debug_buffer[2] = data_buffer[(byte)(read_pointer+2)];
				error_debug_buffer[3] = (byte)(uart->hdmarx->Instance->CNDTR);
				receive_complete_flag = IDLE_receive;
				length_error_integral++;
				overflow_flag = false;
				read_pointer = write_pointer;
			}
		}else{
			//header footer error
			error_debug_buffer[0] = write_pointer;
			error_debug_buffer[1] = read_pointer;
			error_debug_buffer[2] = data_buffer[read_pointer];
			error_debug_buffer[3] = data_buffer[(byte)(read_pointer+1)];
			error_debug_buffer[4] = data_buffer[(byte)(write_pointer-2)];
			error_debug_buffer[5] = data_buffer[(byte)(write_pointer-1)];
			receive_complete_flag = IDLE_receive;
			head_foot_error_integral++;
			overflow_flag = false;
			read_pointer = write_pointer;			
		}
	}
	
}

void mySerial::send_packet(uint16_t header, uint16_t footer, byte* data, int length)
{
	byte *temper_packet;
	temper_packet = new byte[length + 6];
	temper_packet[0] = (byte)(header >>8 & 0xff);
	temper_packet[1] = (byte)(header & 0xff);
	temper_packet[2] = length + 1;
	temper_packet[3] = packet_id;
	memcpy(&temper_packet[4], data, length);
	temper_packet[length+4] = (byte)(footer >>8 & 0xff);
	temper_packet[length+5] = (byte)(footer & 0xff);
	transmit_complete_flag = 0;
	uart_send(this->uart, temper_packet, length+6);
	delete[] temper_packet;
}

void mySerial::send_modbus_packet(uint16_t header, uint16_t footer, byte* data, int length)
{
	byte *temper_packet;
	byte temper_length = (data[1] <= 4)?length - 5:4;
	temper_packet = new byte[temper_length + 6];
	temper_packet[0] = (byte)(header >> 8 & 0xff);
	temper_packet[1] = (byte)(header & 0xff);
	temper_packet[2] = temper_length + 1;
	temper_packet[3] = packet_id;
	memcpy(&temper_packet[4], &data[length-temper_length-2], temper_length);
	temper_packet[temper_length+4] = (byte)(footer >> 8 & 0xff);
	temper_packet[temper_length+5] = (byte)(footer & 0xff);
	if(receive_status == On_received) {
		memcpy(backup_buffer, temper_packet, temper_length + 6);
		backup_length = temper_length + 6;
	}else{	
		transmit_complete_flag = On_transmit;
		uart_send(this->uart, temper_packet, temper_length + 6);
	}	
	delete[] temper_packet;
}

void mySerial::buffer_overflow()
{
	overflow_flag = true;
}
byte length_error_integral;
byte head_foot_error_integral;


