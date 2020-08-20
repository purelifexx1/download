#include "modbus.h"

modbus::modbus()
{
  
}

void modbus::CRC_16(byte* input, byte Length, byte* output)
{
  uint16_t reg_crc = 0xffff;
  for(byte i = 0; i < Length; i++) {
    reg_crc ^= input[i];
    for(byte j = 0; j < 8; j++) {
      if((reg_crc & 0x0001) == 1) reg_crc = (uint16_t)((reg_crc >> 1) ^ 0xA001);
      else reg_crc = (uint16_t)(reg_crc >> 1);
    }
  }
  output[1] = (byte)((reg_crc >> 8) & 0xff);
  output[0] = (byte)(reg_crc & 0xff);
}

void modbus::modbus_request(byte slave_id, byte function_code, byte* register_address, uint16_t register_count, byte* CRC)
{
  request_frame[0] = slave_id;
  request_frame[1] = function_code;
  request_frame[2] = register_address[0];
  request_frame[3] = register_address[1];
  request_frame[4] = (byte)((register_count >> 8) & 0xff);
  request_frame[5] = (byte)(register_count & 0xff);
  CRC_16(request_frame, 6, &request_frame[6]);
  mySerial.Send_packet(request_frame, 8, 23169, 34476);
}

bool modbus::check_valid_package(byte* packet, byte Length, byte* data_frame)
{
  if(packet[2] == Length - 5) {

    return 1;
  }else
    return 0;
}
