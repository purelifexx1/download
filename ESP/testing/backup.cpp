#include <WiFiManager.h>
#include <PubSubClient.h>
#include "schedule.h"
#include "setup_configure.h"
#include "mySerial.h"
#include "modbus.h"
mySerial data_serial(false, 12345, 34567);
mySerial debug_configure_serial(true, 22345, 47898);
const uint16_t mqtt_port = 1883; 
WiFiClient ESP32Client;
PubSubClient client(ESP32Client);

bool LED_status = false;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(22, INPUT_PULLUP);  
  pinMode(23, INPUT_PULLUP);
  delay(50);
  data_serial.set_callback(data_handler);
  setup_mqtt();
  
  setup_wifi(); 
  
  client.setServer(device_setup.mqtt_server.c_str(), device_setup.mqtt_port.toInt()); 
  client.setCallback(callback);
}

void setup_wifi() {
  WiFiManager ESP32WiFi;
  bool status;
  if(digitalRead(22) == LOW) {
    status = ESP32WiFi.autoConnect("ESP32 Configuration", "password");
  }else{
    digitalWrite(2, LED_status = !LED_status);
    status = ESP32WiFi.startConfigPortal("ESP32 Configuration", "password");
  } 
  if (status)  //connect successfully, blink led to inform user
  {
    for (int i = 0; i < 6; ++i)
    {
      digitalWrite(2, LED_status = !LED_status);
      delay(50);
    }
    delay(2000);
    for (int i = 0; i < 6; ++i)
    {
      digitalWrite(2, LED_status = !LED_status);
      delay(50);
    }   
  }else{   //connect fail, blink led continuously
    while(1) {
      digitalWrite(2, LED_status = !LED_status);
      delay(200);
    }
  }
}
void setup_mqtt() {
  device_setup.begin_setup();
  delay(2);
  if(digitalRead(23) == LOW) {
    device_setup.in_setup();
  }else{
    device_setup.device_commence();
  }
}

void callback(char* topic, byte* payload, unsigned int length) { // for mqtt
  if(String(topic) == "data_request") {
	switch(payload[0]) {
		case '0':
			Modbus.modbus_request(0x01, read_input_register, new byte[2]{0x31, 0x00}, 15, 32);
			//real time data request
		break;
		case '1':
			Modbus.modbus_request(0x01, read_input_register, new byte[2]{0x33, 0x00}, 20, 34);
			//statistic data request
		break;
		case '2':
			Modbus.modbus_request(0x01, read_coil, new byte[2]{0x00, 0x00}, 7, 36);
			//control status request
		break;
	}
    
  }else if(String(topic) == "write_coils"){
	  switch(payload[0]) {
		  case '0':
			//on off load 
			Modbus.modbus_write_scoil(0x01, write_coil, 6, payload[0], 38);
		  break;
		  case '1':
		  
		  break;
		  
	  }
    
  }
}
void data_handler(byte* package, int Length) { // for uart lora
  digitalWrite(2, LED_status = !LED_status); 
  Modbus.packet_handler(package, Length);
}
void reconnect() {
  while (!client.connected()) {
    if (client.connect(device_setup.client_id.c_str(),device_setup.mqtt_user.c_str(), device_setup.mqtt_pwd.c_str())) {
       client.subscribe("data_request");  
       debug_configure_serial.Print("connect mqtt");  
    } else {
      digitalWrite(2, LED_status = !LED_status);
      delay(5000);
    }
  }
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  data_serial.Receive_Package();
}
