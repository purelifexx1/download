#ifndef INC_MYSERIAL_
#define INC_MYSERIAL_
#include "stm32f1xx.h"
#define byte uint8_t
#define HAL_UART_Receive_DMA UART_Receive
#define HAL_UART_AbortReceive_IT halt_receive
#define HAL_TIM_Base_IT_Start start_timer
#define HAL_TIM_Base_Stop_IT stop_timer
#define uart->hdmarx->Instance->CNDTR buffer_pointer

#define Callback void(*callback_function)(byte*,int)
class mySerial
{
  private:
	Callback;
	UART_HandleTypeDef* uart;
	TIM_HandleTypeDef* tim;
	byte temper_pointer;
	byte header_sync[2];
	byte footer_sync[2];
	byte sync_buffer[3];
	byte data_buffer[125];
	byte length;
	bool sync_status = false;
	bool sync_flag = false;
	bool complete_flag = false;
  public:
	mySerial(UART_HandleTypeDef current_uart, TIM_HandleTypeDef current_tim);
	void begin(uint16_t header, uint16_t footer, Callback);
	void header_sync_interrupt();
	void packet_sync_interrupt();
	void uart_interrupt(); // put this in uart cpltcallback with the coresponding uart
	void timeout(); // put this in timer interrupt;
	void looping(); // put this in loop;
};


#endif