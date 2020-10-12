#ifndef INC_MODBUS_HANDLER_H_
#define INC_MODBUS_HANDLER_H_
#include "main.h"
#include "request_type.h"
#include "mySerial.h"
#define uart_send HAL_UART_Transmit_DMA
#define uart_dma HAL_UART_Receive_DMA
//#define start_timer HAL_TIM_Base_Start_IT
//#define stop_timer HAL_TIM_Base_Stop_IT
#define IDLE_receive false
#define IDLE_transmit true
#define On_received true
#define On_transmit false
#define byte uint8_t
class modbus_handler
{
    private:
		byte header_chunk[2];
		byte footer_chunk[2];

    public:
		bool first_start = true;
		void begin(uint16_t header, uint16_t footer);
		byte current_request_number;
        modbus_handler();
        byte total_byte = 0;
        byte number_of_request;
        byte reply_packet[64];
        void request_packet_handler(byte* data_packet, int length);
        void receive_handler(UART_HandleTypeDef *huart);
        void package_data();
        void timeout_handler();

};

extern request_type* array_of_request;
extern modbus_handler modbus;
#endif
