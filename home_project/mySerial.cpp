#include "mySerial.h"

mySerial::mySerial(UART_HandleTypeDef current_uart, TIM_HandleTypeDef* current_tim)
{
	uart = &current_uart;
	tim = &current_tim;
}

void mySerial::begin(uint16_t header, uint16_t footer, Callback) 
{
	tim->ARR = 111;
	this->callback_function = callback_function;
	header_sync[0] = (byte)(header>>8 & 0xff);
	header_sync[1] = (byte)(header & 0xff);
	footer_sync[0] = (byte)(footer>>8 & 0xff);
	footer_sync[1] = (byte)(footer & 0xff);
	UART_Receive(uart, sync_buffer, 3);
}

void mySerial::looping()
{
	if(buffer_pointer < 3 && sync_status == false) {
		//start timeout 250us			
		start_timer(tim);
		sync_status = true;
	}
	if(complete_flag == true) {
		complete_flag = false;
		this->callback_function(data_buffer, length);
	}
}

void mySerial::header_sync_interrupt()
{
	stop_timer(tim);
	tim->CNT = 0;
	if(sync_buffer[0] == header_sync[0] && sync_buffer[1] == header_sync[1]) {
		halt_receive(uart);
		length = sync_buffer[2];
		UART_Receive(uart, data_buffer, length + 2);
		sync_flag = true;
		sync_status = true;
	}else{
		sync_status = false;
	}	
}

void mySerial::packet_sync_interrupt()
{
	if(data_buffer[length] == footer[0] & data_buffer[length+1] == footer[1]) {
		halt_receive(uart);
		UART_Receive(uart,sync_buffer, 3);
		sync_status = false;
		sync_flag = false;
		complete_flag = true;
	}else{
		//throw error packet format
		halt_receive(uart);
		UART_Receive(uart, sync_buffer, 3);
	}
}

void mySerial::uart_interrupt()
{
	if(sync_flag == false) {
		header_sync_interrupt();
	}else{
		packet_sync_interrupt();
	}
}

void mySerial::timeout()
{
	stop_timer(tim);
	tim->CNT = 0;
	buffer_pointer = 3;
}
