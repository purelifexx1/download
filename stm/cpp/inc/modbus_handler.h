#ifndef INC_MODBUS_HANDLER_H_
#define INC_MODBUS_HANDLER_H_
#include "main.h"
#include "request_type.h"
#include "mySerial.h"
#define uart_send HAL_UART_Transmit_DMA
#define uart_dma HAL_UART_Receive_DMA
#define byte uint8_t
class modbus_handler
{
    private:
        byte current_request_number;
    public:
        modbus_handler();
        byte number_of_request;
        void request_packet_handler(byte* data_packet, int length);
        void receive_handler(UART_HandleTypeDef *huart);
};

extern request_type* array_of_request;
#endif