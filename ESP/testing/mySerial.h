#ifndef INC_MYSERIAL_
#define INC_MYSERIAL_
#include <Arduino.h>
#define Callback void(*callback_function)(byte*,int)
class mySerial 
{
  private:
    Callback;   
    int pointer = 0;
    byte data_buffer[255];
    byte sync_header[2];
    byte sync_end[2];
    byte sync_flag, sync_pointer, data_pointer, byte_number;
    unsigned long time_value;
    bool timeout_enable = false;
    HardwareSerial* mSerial;
  public:
    mySerial(bool selection, uint16_t header, uint16_t footer);
    void Print(String input);
    void Send(uint8_t* Buffer, int Length);
    void Send_packet(byte* Buffer, int Length, uint16_t header, uint16_t footer, byte command);
    void set_callback(Callback);
    void Receive_CallBack(int th_byte);//in loop
    void Receive_Package();   //in loop
    void Receive(byte*Buffer, int* Length);
    void Pointer_Reset();
    void timer_runout_function();
    void testing();
};
extern mySerial data_serial;
extern mySerial debug_configure_serial;
#endif
