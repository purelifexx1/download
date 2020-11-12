/*
 * control_pi.h
 *
 *  Created on: Nov 10, 2020
 *      Author: Admin
 */

#ifndef INC_CONTROL_PI_H_
#define INC_CONTROL_PI_H_
#include "main.h"
float Ka, Kb, Upper_sat, Lower_sat;
float error, Pa, Pb;
float P_inter, pre_P_inter;
float P_compare, pre_P_compare;
float P_f1, P_f2;
float pre_feedback;
void begin_configuration(float ka, float kb, float upper_sat, float lower_sat);
void reset();
float output_control_function(float set_point, float feedback);
void control_loop(float set_point, float feedback);


#endif /* INC_CONTROL_PI_H_ */
