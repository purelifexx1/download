#include "mySerial.h"

schedule Timer1(50); 
byte *sync_po;
byte *sync_fl;
byte *data_po; 
mySerial::mySerial()
{
  Timer1.set_callback(timer_runout);
  sync_po = &this->sync_pointer;
  sync_fl = &this->sync_flag;
  data_po = &this->data_pointer;
}
void mySerial::Begin(long Baudrate)
{
  Serial.begin(Baudrate);
}
void mySerial::Send(byte* Buffer, int Length)
{
  Serial.write(Buffer, Length);
}
void mySerial::Print(String input)
{
  Serial.println(input);
}
void mySerial::Receive_CallBack(int th_byte)
{
  int number;
  while(number = Serial.available())
    Serial.readBytes(&data_buffer[(pointer+=number)-1], number);
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
  while(number = Serial.available())
    Serial.readBytes(&Buffer[(pointer+=number) - 1], number); 
  *Length = pointer;  
}
void mySerial::Receive_Package()
{
  while(Serial.available()){
    byte temper_byte = Serial.read();
    if(temper_byte == sync_header[sync_pointer] && sync_flag == 0) {
      sync_pointer++;
      if(sync_pointer == 4) {
        sync_pointer = 0;
        sync_flag = 1;
        data_pointer = 0;
        //start timer
        Timer1.start_timer();
      }
    }else if(temper_byte != sync_header[sync_pointer] && sync_flag == 0){
      sync_pointer = 0;
    }else if(sync_flag == 1){
      if(temper_byte == sync_end[sync_pointer]) {
        sync_pointer++;
        data_buffer[data_pointer++] = temper_byte;
        if(sync_pointer == 4) {
          sync_pointer = 0;
          sync_flag = 0;
          byte_number = data_pointer - 4;
          Timer1.stop_timer();
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
  Timer1.looping();
}
void timer_runout()
{
  Timer1.stop_timer();
  *data_po = 0;
  *sync_fl = 0;
  *sync_po = 0;
  //error handler
}
void mySerial::testing()
{
  
}
mySerial mSerial;
