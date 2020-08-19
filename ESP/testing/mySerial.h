#ifndef INC_MYSERIAL_
#define INC_MYSERIAL_
#include <Arduino.h>
#include "schedule.h"
#define Callback void(*callback_function)(byte*,int)
class mySerial 
{
  private:
    Callback;   
    int pointer = 0;
    byte data_buffer[255];
    byte sync_header[4] = {84, 26, 78, 254};
    byte sync_end[4] = {1, 26, 27, 55};
    byte sync_flag, sync_pointer, data_pointer, byte_number;
  public:
    mySerial();
    void Begin(long Baudrate);
    void Print(String input);
    void Send(uint8_t* Buffer, int Length);
    void set_callback(Callback);
    void Receive_CallBack(int th_byte);//in loop
    void Receive_Package();   //in loop
    void Receive(byte*Buffer, int* Length);
    void Pointer_Reset();
    void testing();
};
extern void timer_runout();
extern mySerial mSerial;
#endif
