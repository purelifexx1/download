#include "schedule.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#define	A_pulse 2
#define B_pulse 3
#define button 4
#define relay 5
schedule timer_edge;
schedule timer_button;
schedule screen_refresh;
schedule timer_countdown;
schedule button_timeout;
bool A_state = HIGH, pre_A_state = HIGH, B_state = HIGH;
bool bt_state = HIGH;
bool hold_status = false, switch_screen = false, switch_event = false;
bool relay_status = HIGH, pause_countdown = false;
uint8_t bt_duration = 0, component_select;
int8_t hour, minute, second;
int8_t* volume_counter;
void setup() {
	lcd.init();
	lcd.backlight();
	pinMode(relay, OUTPUT);
	digitalWrite(relay, relay_status);
	pinMode(A_pulse, INPUT_PULLUP);
	pinMode(B_pulse, INPUT_PULLUP);
	pinMode(button, INPUT_PULLUP);
	delay(500);
	timer_edge.start_interval(check_edge, 5);
	timer_button.start_interval(check_bt_status, 200);
	screen_refresh.start_interval(select_screen, 100);
	timer_countdown.start_interval(countdown, 1000);
}

void loop() {
	
	
	timer_edge.looping();
	timer_button.looping();
	screen_refresh.looping();
	button_timeout.looping();
	timer_countdown.looping();
	digitalWrite(
}
void countdown() {
	if(pause_countdown == false) {
		second--;
		time_valid();
		if(second == 0 && minute == 0 && hour == 0) {
			relay_status != relay_status;
			pause_countdown = true;
		}
	}
}

void check_edge(){
	if(switch_screen == true) {
		switch(component_select) {
			case 0:
				volume_counter = &hour;
			break;
			case 1:
				volume_counter = &minute;
			break;
			case 2:
				volume_counter = &second;
			break;
		}
		A_state = digitalRead(A_pulse);
		B_state = digitalRead(B_pulse);
		if(A_state != pre_A_state && A_state == HIGH && B_state == HIGH) { //rising a edge, clockwise
			*volume_counter += 1;
		}else if(A_state != pre_A_state && A_state == LOW && B_state == LOW) { //falling a edge, clockwise
			*volume_counter += 1;
		}else if(A_state != pre_A_state && A_state == HIGH && B_state == LOW) { //rising a edge, anti cw
			*volume_counter -= 1;
		}else if(A_state != pre_A_state && A_state == LOW && B_state == HIGH) { //falling a edge, anti cw
			*volume_counter -= 1;
		}
		pre_A_state = A_state;
		time_valid();
	}
}

void check_bt_status(){
	bt_state = digitalRead(button);
	/*if(bt_state == HIGH) {
		switch_event = false;
		hold_status = false;
	}
	if(bt_state == LOW && switch_event == false) {
		bt_duration++;
		hold_status = true;
	}
	if(bt_duration < 7 && bt_duration != 0 && hold_status == false){
		bt_duration = 0;
		//switch relay or start timer
		
	}else if(bt_duration >= 7 && hold_status == true){
		lcd.clear();
		switch_event = true;
		bt_duration = 0;
		switch_screen != switch_screen;			
	}*/
	
	if(bt_state == HIGH && switch_event == true) switch_event = false;
	
	if(bt_state == HIGH && hold_status == true) {//relay active stop timeout
		button_timeout.stop_timer();
		hold_status = false;		
		if(switch_screen == true) {
			component_select++;
			if(component_select >= 3) component_select = 0;
		}else{
			if(second != 0 || minute != 0 || hour != 0) pause_countdown = !pause_countdown;
			else relay_status != relay_status;
		}
	}
	
	if(bt_state == LOW && hold_status == false && switch_event == false) {//start timeout hold_status = true
		button_timeout.start_timeout(timeout, 2600);
		hold_status = true;
	}
	
	//timeout switch screen
}
void timeout(){
	switch_event = true;
	hold_status = false;
	switch_screen != switch_screen;
}
void select_screen(){
	lcd.clear();
	if(switch_screen == false) {
		lcd.setCursor(0, 0);
		lcd.print(hour/10 + '0');
		lcd.print(hour%10 + '0');
		lcd.print(':');
		lcd.print(minute/10 + '0');
		lcd.print(minute%10 + '0');
		lcd.print(':');
		lcd.print(second/10 + '0');
		lcd.print(second%10 + '0');
		lcd.setCursor(10, 0);
		if(relay_status == false) lcd.print("off");
		else lcd.print("on");
		lcd.setCursor(0,1);
		lcd.print("main screen");
	}else{
		lcd.setCursor(0, 0);
		lcd.print(hour/10 + '0');
		lcd.print(hour%10 + '0');
		lcd.print(':');
		lcd.print(minute/10 + '0');
		lcd.print(minute%10 + '0');
		lcd.print(':');
		lcd.print(second/10 + '0');
		lcd.print(second%10 + '0');
		lcd.setCursor(0, 1);
		lcd.print("setup screen");
		
	}
}
void time_valid(){
	if(second == 60) {
		second = 0;
		minute++;
	}else if(second == -1) {
		second = 59;
		minute--;
	}
	
	if(minute == 60) {
		minute = 0;
		hour++;
	}else if(minute == -1) {
		minute = 59;
		hour--;
	}
	
	if(hour == 24) hour = 0;
	else if(hour == -1) hour = 23;
	
}