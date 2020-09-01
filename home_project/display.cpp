#include "display.h"

display::display(byte address, byte horizental, byte vertical)
{
	
}

void display::begin()
{
	lcd.begin();
	lcd.backlight();
}

void display::select_content(configure_data* input_data)
{
	if(input_data->current_position == 0 && input_data->current_position == 1){
		screen1(input_data->current_position);
	}else if(input_data->current_position == 2 && input_data->current_position == 3){
		screen2(input_data->current_position);
	}else if(input_data->current_position == 10) {
		set_clock(input_data);
	}
}

void display::screen1(byte selection)
{
	lcd.setCursor(3, 0);
	lcd.print("1.Set clock");
	if(selection == 0) lcd.print('.   ') else lcd.print(' ');
	lcd.setCursor(3, 1);
	lcd.print("2.Set alarm");
	if(selection == 1) lcd.print('.   ') else lcd.print(' ');
}

void display::screen2(byte selection)
{
	lcd.setCursor(3, 0);
	lcd.print("3.Room calling");
	if(selection == 0) lcd.print('.   ') else lcd.print(' ');
	lcd.setCursor(3, 1);
	lcd.print("4.Camera");
	if(selection == 1) lcd.print('.   ') else lcd.print(' ');
}

void display::set_clock(configure_data* input_data)
{
	lcd.setCursor(3, 0);
	lcd.print(input_data->hour/10); lcd.print(input_data->hour%10); lcd.print(':');
	lcd.print(input_data->minute/10); lcd.print(input_data->minute%10); lcd.print(':');
	lcd.print(input_data->second/10); lcd.print(input_data->second%10); lcd.print(':');
	
}
configure_data screen_data;