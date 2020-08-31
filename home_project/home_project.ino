#include <WiFiManager.h>
#include <PubSubClient.h>
#include <mySerial.h>
#include "schedule.h"
#include "setup_configure.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define A_pulse 2
#define B_pulse 3
#define mqtt_bt 4
#define wifi_bt 5
#define led_pin 0
schedule timer_edge;
schedule timer_button;
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
}
void callback(char* topic, byte* payload, unsigned int length) {
	
}

void check_edge() {
	A_state = digitalRead(A_pulse);
	B_state = digitalRead(B_pulse);
	if(A_state != pre_A_state && A_state == HIGH && B_state == HIGH) {
		volume_position += 1;
	}else if(A_state != pre_A_state && A_state == LOW && B_state == HIGH) {
		volume_position -= 1;
	}
	pre_A_state = A_state;
	if(volume_position > 7) {
		volume_position = -6;
	}else if(volume_position < -7) {
		volume_position = 6;
	}
}

void check_bt_status() {
	
}

void loop() {
	if(!client.connected()){
		reconnect();
	}
	client.loop();
	
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