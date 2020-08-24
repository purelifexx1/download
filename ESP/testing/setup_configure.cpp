#include "setup_configure.h"

setup_configure::setup_configure()
{
	  
}
void setup_configure::begin_setup()
{
  EEPROM.begin(512);
  debug_configure_serial.set_callback(get_mqtt_configuration);
}
void setup_configure::in_setup()
{  
	while(1) {
    debug_configure_serial.Receive_Package();
	}
}

void setup_configure::device_commence()
{
	byte t = 0, data;
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

void setup_configure::get_mqtt_configuration(byte* packet, int Length)
{
  for(byte t = 0; t < Length; t++) {
    EEPROM.write(t, packet[t]);
    delay(2);
  }
  EEPROM.commit();
  digitalWrite(2, 0);
  delay(500);
  digitalWrite(2, 1);
  delay(500);
  digitalWrite(2, 0);
}

setup_configure device_setup;
