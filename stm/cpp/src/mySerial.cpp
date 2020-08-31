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


	write_pointer = buffer_length - (byte)(real_pointer);
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
			this->callback(&data_buffer[read_pointer+=(receive_length + 2)], receive_length);

		}else{
			//error handle packet format
		}
	}


}

void mySerial::buffer_overflow()
{
	overflow_flag = true;
}

bool overflow_flag;
bool sync_status;
byte write_pointer;
byte read_pointer;
