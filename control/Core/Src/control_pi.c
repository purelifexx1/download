/*
 * control_pi.c
 *
 *  Created on: Nov 10, 2020
 *      Author: Admin
 */

#include "control_pi.h"
void begin_configuration(float ka, float kb, float upper_sat, float lower_sat)
{
	Ka = ka;
	Kb = kb;
	Upper_sat = upper_sat;
	Lower_sat = lower_sat;
}

float output_control_function(float set_point, float feedback)
{
	error = set_point - pre_feedback;
	Pa = error * Ka;
	Pb = Pa * Kb;
	P_inter = Pb * pre_P_compare + pre_P_inter;
	P_f1 = P_inter + Pa;
	P_f2 = (P_f1 > Upper_sat)?Upper_sat:((P_f1 < Lower_sat)?Lower_sat:P_f1);
	P_compare = (P_f2 == P_f1)?1.0f:0.0f;

	//update
	pre_feedback = feedback;
	pre_P_inter = P_inter;
	pre_P_compare = P_compare;

	return P_f2 / 3.3f;
}

void control_loop(float set_point, float feedback)
{
	htim3.Instance->CCR1 = (uint32_t)(htim3.Instance->ARR*output_control_function(set_point, feedback));
}
void reset()
{

}
