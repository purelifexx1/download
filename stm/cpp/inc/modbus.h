

#ifndef INC_MODBUS_H_
#define INC_MODBUS_H_
#include "main.h"
#include "string.h"
#define byte uint8_t
#define uart_dma HAL_UART_Receive_DMA
#define uart_send HAL_UART_Transmit_DMA
#define uart_receive_abort HAL_UART_AbortReceive_IT
#define receive_modbus void(*callback)(byte*,int)

#define buffer_length 256
class modbus
{
	private:
		receive_modbus;
		bool overflow_flag = false;
		bool sync_status = false;
		bool fixed_receive_length = false;
		byte write_pointer, read_pointer;
		byte receive_length;
		byte packet_id;
		byte sync_number = 3;
		byte header[2];
		byte footer[2];
		int temper_length;
		UART_HandleTypeDef* uart;
	public:

		modbus();
		void begin(UART_HandleTypeDef* uart, receive_modbus);
		void CRC_16(byte* input, byte length, byte* output);
		void request_handler(byte* input, int length);
		void request_handler1(byte* input, int length);
		void get_data(byte* temp1, int* temp2);
		void looping();
		void buffer_overflow();
};
extern byte data_buffer[300];

#endif
