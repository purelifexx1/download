#include "request_type.h"

request_type::request_type(byte *data_format, int length)
{
    switch (data_format[0]) {
        case 0x01:
            function_01_handler(&data_format[1], length-1)
        break;
        case 0x04:
            function_04_handler(&data_format[1], length-1)
        break;
        case 0x05:
            function_05_handler(&data_format[1], length-1)
        break;
        case 0x10:

        break;
        case 0x03:

        break;
        case 0x06:

        break;
    }
}

void request_type::function_01_handler(byte *data, int length) //read coil status
{
    //receive format:  [register_address: 2 bytes] [number of register: 1 byte]
    //total 3 bytes
    request_packet[0] = modbus_address;
    request_packet[1] = 0x01;
    request_packet[2] = data[0];
    request_packet[3] = data[1];
    request_packet[4] = 0x00; //just in this case, the total of register cant overcome 255
    request_packet[5] = (byte)data[2];
    CRC_16(request_packet, 6, &request_packet[6]);
    request_length = 8;
    //calculate response length
    response_length = (byte)(data[2] >> 3) + 5; //divive for 8 and plus 5
}
void request_type::function_04_handler(byte *data, int length) //read input register
{
    //receive format:  [register_address: 2 bytes] [number of register: 1 byte]
    //total 3 bytes
    request_packet[0] = modbus_address;
    request_packet[1] = 0x04;
    request_packet[2] = data[0];
    request_packet[3] = data[1];
    request_packet[4] = 0x00; //just in this case, the total of register cant overcome 255
    request_packet[5] = (byte)data[2];
    CRC_16(request_packet, 6, &request_packet[6]);
    request_length = 8;
    //calculate response length
    response_length = (byte)(data[2] << 2) + 5; //multiple for 2 and plus 5
}
void request_type::function_05_handler(byte *data, int length) //read coil status
{
    //receive format:  [register_address: 2 bytes] [value of register: 1 byte(0 or 255)]
    //total 3 bytes
    request_packet[0] = modbus_address;
    request_packet[1] = 0x05;
    request_packet[2] = data[0];
    request_packet[3] = data[1];
    request_packet[4] = data[2]; 
    request_packet[5] = 0x00;
    CRC_16(request_packet, 6, &request_packet[6]);
    request_length = 8;
    //calculate response length
    response_length = 8;
}
void request_type::CRC_16(byte* input, byte Length, byte* output)
{
	uint16_t reg_crc = 0xffff;
	for(byte i = 0; i< Length; i++) {
		reg_crc ^= input[i];
		for(byte j = 0; j < 8; j++) {
			if((reg_crc & 0x0001) == 1) reg_crc = (uint16_t)((reg_crc >> 1) ^ 0xA001);
			else reg_crc = (uint16_t)(reg_crc >> 1);
		}
	}
	output[1] = (byte)((reg_crc >> 8) & 0xff);
	output[0] = (byte)(reg_crc & 0xff);	
}