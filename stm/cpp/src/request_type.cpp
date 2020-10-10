#include "request_type.h"

request_type::request_type()
{
    
}
void request_type::begin_configure(byte *data_format, int length)
{
    switch (data_format[0]) {
        case 0x01:
            function_01_handler(&data_format[1], length-1);
        break;
        case 0x04:
            function_04_handler(&data_format[1], length-1);
        break;
        case 0x05:
            function_05_handler(&data_format[1], length-1);
        break;
        case 0x10:
            function_10_handler(&data_format[1], length-1);
        break;
        case 0x03:
            function_03_handler(&data_format[1], length-1);
        break;
    }
}
void request_type::packet_encoding(){
	switch (response_packet[1]) {
		case 0x01:

		break;
		case 0x04:
			encoded_packet[0] = 0x04;
			encoded_packet[1] = start_address[0];
			encoded_packet[2] = start_address[1];
			encoded_packet[3] = response_packet[2]; //number of data byte
			memcpy(&encoded_packet[4], &response_packet[3], response_length - 5);
			encode_length = response_length - 1;
		break;
		case 0x05:

		break;
		case 0x10:

		break;
		case 0x03:

		break;
	}
}
void request_type::function_01_handler(byte *data, int length) //read coil status
{
    //receive format:  [register_address: 2 bytes] [number of register: 1 byte]
    //total 3 bytes
    request_packet[0] = modbus_address;
    request_packet[1] = 0x01;
    request_packet[2] = data[0];	start_address[0] = data[0];
    request_packet[3] = data[1];    start_address[1] = data[1];
    request_packet[4] = 0x00; //just in this case, the total of register cant overcome 255
    request_packet[5] = (byte)data[2];
    CRC_16(request_packet, 6, &request_packet[6]);
    request_length = 8;
    //calculate response length
    response_length = (byte)(data[2] >> 3) + 5; //divive for 8 and plus 5
}
void request_type::function_03_handler(byte *data, int length) //read holding registers
{
    //receive format:  [register_address: 2 bytes] [number of register: 1 byte]
    //total 3 bytes
    request_packet[0] = modbus_address;
    request_packet[1] = 0x03;
    request_packet[2] = data[0];	start_address[0] = data[0];
    request_packet[3] = data[1];    start_address[1] = data[1];
    request_packet[4] = 0x00; //just in this case, the total of register cant overcome 255
    request_packet[5] = (byte)data[2];
    CRC_16(request_packet, 6, &request_packet[6]);
    request_length = 8;
    //calculate response length
    response_length = (byte)(data[2] << 1) + 5; //multiple for 2 and plus 5
}
void request_type::function_04_handler(byte *data, int length) //read input register
{
    //receive format:  [register_address: 2 bytes] [number of register: 1 byte]
    //total 3 bytes
    request_packet[0] = modbus_address;
    request_packet[1] = 0x04;
    request_packet[2] = data[0];	start_address[0] = data[0];
    request_packet[3] = data[1];	start_address[1] = data[1];
    request_packet[4] = 0x00; //just in this case, the total of register cant overcome 255
    request_packet[5] = (byte)data[2];
    CRC_16(request_packet, 6, &request_packet[6]);
    request_length = 8;
    //calculate response length
    response_length = (byte)(data[2] << 1) + 5; //multiple for 2 and plus 5
}
void request_type::function_05_handler(byte *data, int length) //read coil status
{
    //receive format:  [register_address: 2 bytes] [value of register: 1 byte(0 or 255)]
    //total 3 bytes
    request_packet[0] = modbus_address;
    request_packet[1] = 0x05;
    request_packet[2] = data[0];	start_address[0] = data[0];
    request_packet[3] = data[1];	start_address[1] = data[1];
    request_packet[4] = data[2]; 
    request_packet[5] = 0x00;
    CRC_16(request_packet, 6, &request_packet[6]);
    request_length = 8;
    //calculate response length
    response_length = 8;
}
void request_type::function_10_handler(byte *data, int length) //read coil status
{
    //receive format:  [register_address: 2 bytes] [number of register: 1 byte] [register value: number of registers x2 bytes]
    //total 3 bytes
    request_packet[0] = modbus_address;
    request_packet[1] = 0x10;
    request_packet[2] = data[0];	start_address[0] = data[0];
    request_packet[3] = data[1];  start_address[1] = data[1];
    request_packet[4] = 0x00; //just in this case, the total of register cant overcome 255
    request_packet[5] = (byte)data[2];
    byte number_of_bytes = (byte)(data[2] << 1);
    request_packet[6] = number_of_bytes; //number of content bytes = number of registers x 2
    memcpy(&request_packet[7], &data[3], number_of_bytes);
    CRC_16(request_packet, number_of_bytes + 7, &request_packet[7 + number_of_bytes]);
    request_length = number_of_bytes + 9;
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
bool request_type::is_data_valid()
{
	byte temper_check[2];
	CRC_16(response_packet, response_length, temper_check);
	return ((temper_check[0] == 0) && (temper_check[1] == 0))?true:false;
}
