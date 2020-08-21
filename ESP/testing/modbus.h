#ifndef INC_MODBUS_
#define INC_MODBUS_
#include <Arduino.h>
#include "mySerial.h"
#define read_coil 1
#define read_discrete 2
#define read_holding_register 3
#define read_input_register 4
#define write_coil 5
#define write_register 6
#define read_excep_status 7
#define diagnostic 8
#define get_comm_event_counter 11
#define get_comm_event_log 12
#define write_multiple_coil 15
#define write_multiple_register 16
#define report_slave_id 17
#define read_file_record 20
#define write_file_record 21
#define mask_write_register 22
#define read_write_mul_register 23
#define read_fifo_que 24
class modbus
{
  private:
    byte request_frame[8];
  public:
    modbus();
    bool check_valid_package(byte* packet, byte Length, byte* data_frame);
    void modbus_request(byte slave_id, byte function_code, byte* register_address, uint16_t register_count);
    void CRC_16(byte* input, byte Length, byte* output);
};


extern mySerial data_serial(false);
#endif
