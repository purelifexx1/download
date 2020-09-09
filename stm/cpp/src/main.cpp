/*
 * main.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Admin
 */

#include "main.h"
#include "modbus.h"
#include "mySerial.h"
#define byte uint8_t
#define start_timeout HAL_TIM_Base_Start_IT
#define uart_send HAL_UART_Transmit_DMA
#define uart_dma HAL_UART_Receive_DMA
#define IDLE_receive false
#define IDLE_transmit true
#define On_received true
#define On_transmit false
mySerial Serial2;
modbus modbus1;
byte* temp1;
int* temp2;
bool transmit_complete_flag = IDLE_transmit;
bool receive_complete_flag = IDLE_receive;
bool receive_status = IDLE_receive;
void setup() {
	Serial2.begin(&huart2, 23169, 34476, data_received2);
	modbus1.begin(&huart3, modbus_received);
}

void loop() {
	Serial2.looping2();
	//modbus1.looping();
	if(backup_length != 0 && receive_status == IDLE_receive) {
		transmit_complete_flag = On_transmit;
		uart_send(&huart2, backup_buffer, backup_length);
		backup_length = 0;
	}
}

void data_received2(byte* data_buffer, int length) {
	//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	receive_complete_flag = IDLE_receive;
	modbus1.request_handler1(data_buffer, length);
}

void modbus_received(byte* data_buffer, int length) {
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    Serial2.send_packet(12345, 34567, data_buffer, length);
}

void UART_CallBack(UART_HandleTypeDef *huart) {
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	if (huart->Instance == USART2)
		Serial2.buffer_overflow();
	else if(huart->Instance == USART3){
		HAL_UART_AbortReceive_IT(huart);
		if(modbus1.request_type == false) {
			Serial2.send_modbus_packet(12345, 34567, modbus1.data_buffer, modbus1.temper_length);
		}else{
			if(modbus1.temper_length1 != -1) {
				uart_dma(huart, &modbus1.data_buffer[modbus1.request_length[modbus1.temper_length1+1]], modbus1.request_length[modbus1.temper_length1]);
				uart_send(huart, modbus1.temper_request, 8);
				modbus1.temper_request+=8;
				modbus1.temper_length1--;
			}
		}
		//modbus1.buffer_overflow();
	}		
}
void GPIO_Interrupt_Callback(uint16_t pin){
	if(pin == GPIO_PIN_1) {//RISING
		if(transmit_complete_flag == On_transmit) {
			transmit_complete_flag = IDLE_transmit;
		}else{
			receive_complete_flag = On_received;
			receive_status = IDLE_receive;
		}
	}else if(pin == GPIO_PIN_0) {//FALLING
		if(transmit_complete_flag == On_transmit) {
			// confuse if On_transmit before falling receive falling edge
		}else{
			receive_status = On_received;
		}
	}
}



