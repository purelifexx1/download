#ifndef INC_DISPLAY__
#define INC_DISPLAY_
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class display
{
	private:
		LiquidCrystal_I2C lcd(0x27, 16, 2);
	public:
		display(byte adress, byte horizental, byte vertical);
		void begin();
		void select_content(configure_data* input_data);
		void main_screen();
		void screen1();
		void screen2();
		void screen3();
		void set_clock(configure_data* input_data);
		
};
struct configure_data {
	byte current_position;
	byte second;
	byte minute;
	byte hour;
	byte set_hour;
	byte set_minute;
	byte set_hour;
	byte current_call_room;
	bool camera_onoff_status;
	bool water_valve_status;
	
};
extern configure_data screen_data;
#endif