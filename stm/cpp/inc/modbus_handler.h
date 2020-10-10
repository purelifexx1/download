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

    public:
		byte current_request_number;
        modbus_handler();
        byte total_byte = 0;
        byte number_of_request;
        byte testing[64];
        void request_packet_handler(byte* data_packet, int length);
        void receive_handler(UART_HandleTypeDef *huart);
        void package_data();

};

extern request_type* array_of_request;
extern modbus_handler modbus;
#endif
