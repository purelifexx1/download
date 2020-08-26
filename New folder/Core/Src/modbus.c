#include "modbus.h"

uint8_t get_receive_length(uint8_t* packet, uint8_t length)
{
	uint8_t output;
	switch(packet[1]) {
		case 1:
			uint16_t number_of_coil = (packet[4] << 8) ^ packet[5];
			uint8_t number_of_data = number_of_coil/8;
			return (number_of_data + 6);// number of coil round up +1, +5 address and function code and length and CRC, 
		break;
			
		case 4:
			uint16_t number_of_register = (packet[4] << 8) ^ packet[5];
			return (number_of_register*2 + 5);
		break;
		
		case 5:
			return 8;
		break;
	}
}