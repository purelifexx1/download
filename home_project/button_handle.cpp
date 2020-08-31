#include "button_handle"

button_handle::button_handle(byte PIN, bool is_volume_bt, short_press, long_press)
{
	this->PIN = PIN;
	pinMode(this->PIN, INPUT_PULLUP);
	is_volume_bt = false;
	this->callback1 = callback1;
	this->callback2 = callback2;
	cycle_check.start_interval(check_bt_status, 200);
}

button_handle::button_handle(byte PIN, byte A_PIN, byte B_PIN, short_press, long_press)
{
	this->PIN = PIN;
	this->A_PIN = A_PIN;
	this->B_PIN = B_PIN;
	pinMode(this->PIN, INPUT_PULLUP);
	pinMode(this->A_PIN, INPUT_PULLUP);
	pinMode(this->B_PIN, INPUT_PULLUP);
	this->callback1 = callback1;
	this->callback2 = callback2;
	is_volume_bt = true;
	cycle_check.start_interval(check_bt_status, 200);
	cycle_pulse_check(check_pulse, 2);
}

void button_handle::check_bt_status()
{
	bt_state = digitalRead(this->PIN);
	if(bt_state == HIGH && switch_event == true) switch_event = false;
	
	if(bt_state == HIGH && hold_status == true) {//relay active stop timeout
		bt_timeout.stop_timer();
		hold_status = false;		
		//handle button click
		this->callback1();
	}
	
	if(bt_state == LOW && hold_status == false && switch_event == false) {//start timeout hold_status = true   
		bt_timeout.start_timeout(long_click, 2000);
		hold_status = true;
	}	
	//timeout switch screen
}

void button_handle::long_click()
{
	//handle long button click event
	switch_event = true;
	hold_status = false;
	this->callback2();
}

void button_handle::check_pulse()
{
	A_state = digitalRead(A_PIN);
	B_state = digitalRead(B_PIN);
	if(A_state != pre_A_state && A_state == HIGH && B_state == HIGH) { //rising a edge, clockwise
		pulse += 1;
	}else if(A_state != pre_A_state && A_state == LOW && B_state == HIGH) { //falling a edge, anti cw
		pulse -= 1;
	}
	pre_A_state = A_state;
}
byte button_handle::get_pulse()
{
	return pulse;
}

void button_handle::looping()
{
	cycle_check.looping();
	if(is_volume_bt == true)
		cycle_pulse_check.looping();	
}

