/*
 * main.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Admin
 */

#include "main.h"
#include "mySerial.h"

mySerial Serial;
void setup() {
	Serial.begin(&huart2, 12345, 12345, data_received);
}

void loop() {
	Serial.looping();
}

void data_received(byte* data_buffer, int length) {
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	overflow_flag = false;
}

void UART_CallBack() {

	Serial.buffer_overflow();
}


