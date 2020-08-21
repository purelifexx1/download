#include <WiFiManager.h>
#include <PubSubClient.h>
//#include "schedule.h"
#include "setup_configure.h"
#include "mySerial.h"

const uint16_t mqtt_port = 1883; 
WiFiClient ESP32Client;
PubSubClient client(ESP32Client);
byte data_buffer[128];
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
      delay(100);
    }
  }
}
void setup_mqtt() {
  if(digitalRead(23) == LOW) {
    device_setup.in_setup();
  }else{
    device_setup.device_commence();
  }
}

void callback(char* topic, byte* payload, unsigned int length) { // for mqtt
//  switch (String(topic)) {
//    case "realtime_data_request":
//      Modbus.modbus_request(0x01, 0x04, new byte[2]{0x31, 0x00}, 15);
//      break;
//    case "statistic_data_request":
//      Modbus.modbus_request(0x01, 0x04, new byte[2]{0x33, 0x00}, 20);
//      break;
//    
//  }
}
void data_handler(byte* package, int Length) { // for uart
  
}
void reconnect() {
  while (!client.connected()) {
    if (client.connect(device_setup.client_id.c_str(),device_setup.mqtt_user.c_str(), device_setup.mqtt_pwd.c_str())) {
       client.subscribe("realtime_data_request");
       client.subscribe("statistic_data_request");     
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
