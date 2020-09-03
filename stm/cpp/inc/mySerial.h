/*
 * mySerial.h
 *
 *  Created on: Aug 31, 2020
 *      Author: Admin
 */

#ifndef INC_MYSERIAL_H_
#define INC_MYSERIAL_H_
#include "main.h"
#include "string.h"
#define byte uint8_t
#define uart_dma HAL_UART_Receive_DMA
#define uart_received void(*callback)(byte*,int)
#define buffer_length 256
class mySerial
{
private:
	uart_received;
	bool overflow_flag = false;
	bool sync_status = false;
	bool fixed_receive_length = false;
	byte write_pointer, read_pointer;	
	byte receive_length;
	byte header[2];
	byte footer[2];
	byte data_buffer1[300];
	UART_HandleTypeDef* uart;
public:

	mySerial();
	void begin(UART_HandleTypeDef* uart, uint16_t header, uint16_t footer, uart_received);
	void looping();
	void buffer_overflow(); // put this function in coresponding complete callback uart
};


#endif /* INC_MYSERIAL_H_ */
