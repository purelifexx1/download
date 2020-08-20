#include "setup_configure.h"

setup_configure::setup_configure()
{
	mSerial.Begin(115200);
	EEPROM.begin(512);
}

void setup_configure::in_setup()
{
	while(1) {
    mSerial.Receive(data_buffer, &Length);
    if (Length >= checked) {
      if(data_buffer[0] == 'p' && data_buffer[1] == 'c' && data_buffer[2] == 's' && data_buffer[3] == 'd' && check_header == 1) {
        if (Length > checked) {
          check_header = Length - checked;
          memcpy(data_buffer1, &data_buffer[checked], check_header);
        }else
          check_header = 0;
        checked = data_buffer[4];
      }else if (check_header == 0) {
        memcpy(data_buffer1, &data_buffer[0], Length);
        for(byte t = 0; t<Length; t++) {
          EEPROM.write(t, data_buffer1[t]);
          delay(2);
        }
        EEPROM.commit();
      }else{
        memcpy(&data_buffer1[check_header], &data_buffer[0], Length);
        for(byte t = 0; t<check_header + Length; t++) {
          EEPROM.write(t, data_buffer1[t]);
          delay(2);
        }
        EEPROM.commit();
      }
      mSerial.Pointer_Reset();
    }
	}
}

void setup_configure::device_commence()
{
	byte t = 0, data;
	  while((data = EEPROM.read(t++)) != '\r'){
      ssid.concat((char)data);
      delay(2);
    }
    while((data = EEPROM.read(t++)) != '\r'){
      password.concat((char)data);
      delay(2);
    }
    while((data = EEPROM.read(t++)) != '\r'){
      mqtt_server.concat((char)data);
      delay(2);
    }
    while((data = EEPROM.read(t++)) != '\r'){
      mqtt_user.concat((char)data);
      delay(2);
    }
    while((data = EEPROM.read(t++)) != '\r'){
      mqtt_pwd.concat((char)data);
      delay(2);
    }
    while((data = EEPROM.read(t++)) != '\r'){
      client_id.concat((char)data);
      delay(2);
    }
    while((data = EEPROM.read(t++)) != '\r'){
      mqtt_port.concat((char)data);
      delay(2);
    }
    
}

setup_configure device_setup;