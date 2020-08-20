#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "schedule.h"
#include "setup_configure.h"


const uint16_t mqtt_port = 1883; 
WiFiClient ESP8266Client;
PubSubClient client(ESP8266Client);
byte data_buffer[128];
bool LED_status = false;
void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT_PULLUP);  
  delay(50);
  if(digitalRead(D1) == LOW) {
    device_setup.in_setup();  
  }else{
    device_setup.device_commence();
  } 
  
  mSerial.set_callback(data_handler);
  setup_wifi();
  client.setServer(device_setup.mqtt_server.c_str(), device_setup.mqtt_port.toInt()); 
  client.setCallback(callback);
}

void setup_wifi() {
  delay(10);
  WiFi.begin(device_setup.ssid, device_setup.password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    digitalWrite(D0, LED_status = !LED_status);
  }
}

void callback(char* topic, byte* payload, unsigned int length) { // for mqtt
  switch (String(topic)) {
    case "realtime_data_request":
      
      break;
    case "statistic_data_request":

      break;
    
  }
}
void data_handler(byte* package, int Length) { // for uart
  if(Length == 8) {
    digitalWrite(D0, LED_status = !LED_status);
  }else{
    //throw error
  }
}
void reconnect() {
  while (!client.connected()) {
    if (client.connect(device_setup.client_id.c_str(),device_setup.mqtt_user.c_str(), device_setup.mqtt_pwd.c_str())) {
       client.subscribe("realtime_data_request");
       client.subscribe("statistic_data_request");
    } else {
      digitalWrite(D0, LED_status = !LED_status);
      delay(5000);
    }
  }
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  mSerial.Receive_Package();
}
