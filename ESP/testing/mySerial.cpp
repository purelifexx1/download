#include "mySerial.h"

mySerial::mySerial(bool selection, uint16_t header, uint16_t footer)
{
  sync_header[0] = (byte)(header>>8 & 0xff);
  sync_header[1] = (byte)(header & 0xff);
  sync_end[0] = (byte)(header>>8 & 0xff);
  sync_end[1] = (byte)(header & 0xff);
  if(selection == true) mSerial = &Serial; else mSerial = &Serial2;
  mSerial->begin(115200);
}

void mySerial::Send(byte* Buffer, int Length)
{
  mSerial->write(Buffer, Length);
}
void mySerial::Send_packet(byte* Buffer, int Length, uint16_t header, uint16_t footer, byte command)
{
  byte* temper_buffer;
  temper_buffer = new byte[Length + 6];
  temper_buffer[0] = (byte)((header >> 8) & 0xff);
  temper_buffer[1] = (byte)(header & 0xff);
  temper_buffer[2] = command;
  temper_buffer[3] = Length;
  memcpy(&temper_buffer[4], Buffer, Length);
  temper_buffer[4+Length] = (byte)((footer >> 8) & 0xff);
  temper_buffer[5+Length] = (byte)(footer & 0xff);
  Send(temper_buffer, Length + 6);
  delete[]temper_buffer;
}
void mySerial::Print(String input)
{
  mSerial->println(input);
}
void mySerial::Receive_CallBack(int th_byte)
{
  int number;
  while(number = mSerial->available())
    mSerial->readBytes(&data_buffer[(pointer+=number)-1], number);
  if(pointer >= th_byte) {
     number = pointer;
     pointer = 0;
     this->callback_function(data_buffer, number);     
  }
}

void mySerial::set_callback(Callback)
{
  this->callback_function = callback_function;
}
void mySerial::Pointer_Reset()
{
  pointer = 0;
}
void mySerial::Receive(byte* Buffer, int* Length)
{  
  int number;
  while(number = mSerial->available())
    mSerial->readBytes(&Buffer[(pointer+=number) - 1], number); 
  *Length = pointer;  
}
void mySerial::Receive_Package()
{
  while(mSerial->available()){
    byte temper_byte = mSerial->read();
    if(temper_byte == sync_header[sync_pointer] && sync_flag == 0) {
      sync_pointer++;
      if(sync_pointer == 2) {
        sync_pointer = 0;
        sync_flag = 1;
        data_pointer = 0;
        //start timer
        time_value = millis();
        timeout_enable = true;
      }
    }else if(temper_byte != sync_header[sync_pointer] && sync_flag == 0){
      sync_pointer = 0;
    }else if(sync_flag == 1){
      if(temper_byte == sync_end[sync_pointer]) {
        sync_pointer++;
        data_buffer[data_pointer++] = temper_byte;
        if(sync_pointer == 2) {
          sync_pointer = 0;
          sync_flag = 0;
          byte_number = data_pointer - 2;
          timeout_enable = false;
          this->callback_function(data_buffer, byte_number);
          return;
        }
      }
      else{
        sync_pointer = 0;
        data_buffer[data_pointer++] = temper_byte;
      }
    }
  }
  timer_runout_function();
}

void mySerial::timer_runout_function() 
{
  if(timeout_enable && (uint16_t)(millis() - time_value) > 50) {
    timeout_enable = false;
    data_pointer = 0;
    sync_flag = 0;
    sync_pointer = 0;
    //error handler after this
  }
}
void mySerial::testing()
{
  
}
