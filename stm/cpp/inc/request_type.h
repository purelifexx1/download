#ifndef INC_REQUEST_TYPE_H_
#define INC_REQUEST_TYPE_H_
#include "main.h"
#include "string.h"
#define modbus_address 0x01
#define byte uint8_t
class request_type
{
    private:
        void function_01_handler(byte *data, int length);
        void function_03_handler(byte *data, int length);
        void function_04_handler(byte *data, int length);
        void function_05_handler(byte *data, int length);
        void function_10_handler(byte *data, int length);
        void CRC_16(byte* input, byte Length, byte* output);
    public:
        void begin_configure(byte *data_format, int length);
        byte request_number;
        byte request_packet[30];
        byte response_packet[64];
        byte request_length;
        byte response_length;
        request_type();
};
#endif
