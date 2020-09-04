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
#deinfe stop_timer HAL_TIM_Base_Stop_IT
mySerial Serial2;
modbus modbus1;

void setup() {
	Serial2.begin(&huart2, 23169, 34476, data_received2);
	modbus1.begin(&huart3, modbus_received);
}

void loop() {
	Serial2.looping2();
	//modbus1.looping();

}

void data_received2(byte* data_buffer, int length) {
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	modbus1.request_handler1(data_buffer, length);
}

void modbus_received(byte* data_buffer, int length) {
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    Serial2.send_packet(12345, 34567, data_buffer, length);
}

void UART_CallBack(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2)
		Serial2.buffer_overflow();
	else if(huart->Instance == USART3){
		HAL_UART_AbortReceive_IT(huart);
		byte* temp1;
		int* temp2;
		modbus1.get_data(temp1, temp2);
		Serial2.send_modbus_packet(temp1, *temp2);
		//modbus1.buffer_overflow();
	}
		
}



