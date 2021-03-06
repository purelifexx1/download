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

void modbus::modbus_request(byte slave_id, byte function_code, byte* register_address, uint16_t register_count, byte data_code)
{
  request_frame[0] = slave_id;
  request_frame[1] = function_code;
  request_frame[2] = register_address[0];
  request_frame[3] = register_address[1];
  request_frame[4] = (byte)((register_count >> 8) & 0xff);
  request_frame[5] = (byte)(register_count & 0xff);
  CRC_16(request_frame, 6, &request_frame[6]);
  data_serial.Send_packet(request_frame, 8, 23169, 34476, data_code);
}
void modbus::modbus_write_scoil(byte slave_id, byte function_code, uint16_t register_address, byte write_status, byte data_code)
{
  request_frame[0] = slave_id;
  request_frame[1] = function_code;
  request_frame[2] = (byte)((register_address >> 8) & 0xff);
  request_frame[3] = (byte)(register_address & 0xff);
  request_frame[4] = (write_status == 1)?0xff:0x00;
  request_frame[5] = 0;
  CRC_16(request_frame, 6, &request_frame[6]);
  data_serial.Send_packet(request_frame, 8, 23169, 34476, data_code);
}
bool modbus::packet_handler(byte* packet, byte Length)
{
  if(packet[0] == Length - 1) {

	  switch (packet[1]) {
		case 32:
      debug_configure_serial.Send(&packet[2], Length - 2);
		  client.publish("realtime_data", &packet[2], Length - 2);
		break;

		case 34:
		  client.publish("realtime_data", &packet[2], Length - 2);
		break;

		case 36:
		  client.publish("realtime_data", &packet[2], Length - 2);
		break;

		case 38:
		  client.publish("realtime_data", &packet[2], Length - 2);
		break;
	  }

  }else{
    //packet length error or format error
	debug_configure_serial.Print("received packet has invalid data length");
  debug_configure_serial.Print("receive packet length: ");
  debug_configure_serial.mSerial->println(Length);
  debug_configure_serial.Print("real packet length: ");
  debug_configure_serial.mSerial->println(packet[0]);
	client.publish("error", "1"); // length error
  }
}
modbus Modbus;
