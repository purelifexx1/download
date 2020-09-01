#ifndef INC_MODBUS_
#define INC_MODBUS_
#include "mySerial.h"
#include <PubSubClient.h>
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
    bool packet_handler(byte* packet, byte Length);
    void modbus_request(byte slave_id, byte function_code, byte* register_address, uint16_t register_count, byte data_code);
    void modbus_write_scoil(byte slave_id, byte function_code, uint16_t register_address, byte write_status, byte data_code);
    void CRC_16(byte* input, byte Length, byte* output);
};

extern modbus Modbus;
extern PubSubClient client;
#endif
