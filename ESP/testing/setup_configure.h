#ifndef INC_SETUPCONFIGURE_
#define INC_SETUPCONFIGURE_
#include "mySerial.h"
#include <EEPROM.h>
#include <String.h>
class setup_configure
{
private:
	byte checked = 5;
	byte data_buffer[128];
  	byte data_buffer1[128];
	byte check_header = 1;
  	int Length;
  	
public:
  void begin_setup();
	setup_configure();
	String ssid = "";
	String password = "";
	String mqtt_server = "";
	String mqtt_user = "";
	String mqtt_pwd = "";
	String client_id = "";
	String mqtt_port = "";
	void in_setup();
	void device_commence();
 void static get_mqtt_configuration(byte* packet, int Length);
};

extern setup_configure device_setup;

#endif
