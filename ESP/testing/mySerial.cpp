#include "mySerial.h"

mySerial::mySerial(bool selection, uint16_t header, uint16_t footer)
{
  sync_header[0] = (byte)(header>>8 & 0xff);
  sync_header[1] = (byte)(header & 0xff);
  sync_end[0] = (byte)(footer>>8 & 0xff);
  sync_end[1] = (byte)(footer & 0xff);
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
  temper_buffer = new byte[Length + 5];
  temper_buffer[0] = (byte)((header >> 8) & 0xff);
  temper_buffer[1] = (byte)(header & 0xff);
  temper_buffer[2] = Length;
  //temper_buffer[3] = command;
  memcpy(&temper_buffer[3], Buffer, Length);
  temper_buffer[3+Length] = (byte)((footer >> 8) & 0xff);
  temper_buffer[4+Length] = (byte)(footer & 0xff);
  if(receive_status == true) {
    debug_configure_serial.Print("back up data");
	memcpy(backup_buffer, temper_buffer, Length + 5);
	backup_length = Length + 5;
  }else{
	transmit_complete_flag = false;
	Send(temper_buffer, Length + 5);
  }
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
      }
    }else if(temper_byte != sync_header[sync_pointer] && sync_flag == 0){
      sync_pointer = 0;
    }else if(sync_flag == 1){
  	  if(temper_lock == false) {
  		  timeout_enable = true; temper_lock = true; 
  		  standard_timeout = 8 + (int)(temper_byte*0.07);     
  	  }
      if(temper_byte == sync_end[sync_pointer]) {
        sync_pointer++;
        data_buffer[data_pointer++] = temper_byte;
        if(sync_pointer == 2) {
		      temper_lock = false;
          sync_pointer = 0;
          sync_flag = 0;
          byte_number = data_pointer - 3;
          timeout_enable = false;
          if (data_buffer[0] == byte_number)
            this->callback_function(&data_buffer[1], byte_number);
          else{
            receive_complete_flag = false;
            debug_configure_serial.Print("packet length error");
            client.publish("error", "5");
          }
          return;
        }
      }
      else{
        sync_pointer = (sync_pointer != 0 && temper_byte == sync_end[0])?1:0;
        data_buffer[data_pointer++] = temper_byte;
      }
    }
  }
  timer_runout_function();
}

void mySerial::packet_received()
{
	int number_of_byte = mSerial->available();
	if(number_of_byte) {
		mSerial->readBytes(data_buffer, number_of_byte);
    debug_configure_serial.mSerial->print("11111");
    debug_configure_serial.Send(data_buffer, number_of_byte);
    debug_configure_serial.Print("11111");
		if(data_buffer[0] == sync_header[0] && data_buffer[1] == sync_header[1] && data_buffer[number_of_byte-2] == sync_end[0] && data_buffer[number_of_byte-1] == sync_end[1]) {
			this->callback_function(&data_buffer[2], number_of_byte-4);
			return;
		}else{
      receive_complete_flag = false;
			debug_configure_serial.Print("header and footer error");
      debug_configure_serial.mSerial->println(number_of_byte);
      debug_configure_serial.mSerial->println(mSerial->available());
      //debug_configure_serial.Send(data_buffer, number_of_byte);
		}
	}else{
    receive_complete_flag = false;
		debug_configure_serial.Print("hardware serial failure (hardware damage)");
	}
}

void mySerial::timer_runout_function() 
{
  if(timeout_enable == true && (unsigned long)(millis() - time_value) > standard_timeout) {
    timeout_enable = false;
    data_pointer = 0;
    sync_flag = 0;
    sync_pointer = 0;	
    //error handler after this
	debug_configure_serial.Print("packet received timeout at central node");
	client.publish("error", "0"); //packet received timeout at centrall node
  }
}
void mySerial::testing()
{
  
}
byte backup_buffer[125];
int backup_length;
