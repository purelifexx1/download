#ifndef INC_BUTTON_HANDLE_
#define INC_BUTTON_HANDLE_
#include <Arduino.h>
#include "schedule.h"
#define short_press void(*callback1)()
#define long_press void(*callback2)()

class button_handle
{
	private:
		bool bt_state = HIGH;
		bool hold_status = false;
		bool switch_event = false;
		bool is_volume_bt;
		bool A_state, B_state, pre_A_state = HIGH;
		byte PIN, A_PIN, B_PIN;
		byte pulse;
		short_press;
		long_press;
		schedule cycle_check;
		schedule bt_timeout;
		schedule cycle_pulse_check;
	public:
		button_handle(byte PIN, short_press, long_press);
		button_handle(byte PIN, byte A_PIN, byte B_PIN, short_press, long_press); 
		void looping();
		void static long_click();
		void static check_bt_status();
		void static check_pulse();
		byte get_pulse();
};



#endif