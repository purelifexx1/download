#include <WiFiManager.h>
#include <PubSubClient.h>
#include <mySerial.h>
#include "schedule.h"
#include "button_handle.h"
#include "setup_configure.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

button_handle bt1(4, bt1_short_press, bt1_long_press);

schedule screen_refresh;
WiFiClient ESP8266Client;
PubSubClient client(ESP8266Client);
LiquidCrystall_I2C lcd(0x27, 16, 2);
mySerial debug_configure_serial(true, 22345, 45698);
bool led_status;
int8_t volume_position;
void setup() {
	setup_mqtt();
	setup_wifi();
	client.setServer(device_setup.mqtt_server.c_str(), device_setup.mqtt_port.toInt());
	client.setCallback(callback);
	screen_refresh(content, 100);
}
void callback(char* topic, byte* payload, unsigned int length) {
	
}


void loop() {
	if(!client.connected()){
		reconnect();
	}
	client.loop();
	
}

void content(){
	
}

void setup_wifi() {
	WiFiManager ESP8266WiFi;
	bool status;
	if(digitalRead(wifi_bt) == LOW) {
		status = ESP8266WiFi.autoConnect("ESP82663e6f", "password");
	}else{
		status = ESP8266WiFi.startConfigPortal("ESP82663e6f", "password");
	}
	if(status) {
		for (int i = 0; i < 6; ++i)
		{
		  digitalWrite(led_pin, LED_status = !LED_status);
		  delay(50);
		}
		delay(2000);
		for (int i = 0; i < 6; ++i)
		{
		  digitalWrite(led_pin, LED_status = !LED_status);
		  delay(50);
		}   
	}else{
		while(1){digitalWrite(led_pin, LED_status = !LED_status);delay(200);}
	}
}

void setup_mqtt() {
	device_setup.begin_setup();
	delay(2);
	if(digitalRead(mqtt_bt) == LOW) device_setup.in_setup();
	else device_setup.device_commence();
}
void reconnect() {
	while(!client.connected()) {
		if(client.connect(device_setup.client_id.c_str(), device_setup.mqtt_user.c_str(), device_setup.mqtt_pwd.c_str())) {
			//subscribe at here
			debug_configure_serial.Print("connect mqtt");
		}else{
			digitalWrite(led_pin, LED_status = !LED_status);
			delay(5000);
		}
	}
}