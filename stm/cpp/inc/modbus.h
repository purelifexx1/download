

#ifndef INC_MODBUS_H_
#define INC_MODBUS_H_
#include "main.h"
#define byte uint8_t
#define uart_dma HAL_UART_Receive_DMA
#define uart_send HAL_UART_Transmit_DMA
#define modbus_received void(*callback)(byte*, int)
#define buffer_length 256
class modbus
{
	private:
		modbus_received;
		bool overflow_flag = false;
		bool sync_status = false;
		byte write_pointer, read_pointer;
		byte receive_length;
		byte packet_id;
		byte header[2];
		byte footer[2];
		byte data_buffer[300];
		UART_HandleTypeDef* uart;
	public:
		modbus();
		void begin(UART_HandleTypeDef* uart, modbus_received);
		void CRC_16(byte* input, byte length, byte* output);
		void request_handler(byte* input, int length);
		void send_packet(uint16_t header, uint16_t footer, byte* data, int length);
		void looping();
		void buffer_overflow();
};


#endif