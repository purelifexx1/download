/*
 * command_decode.c
 *
 *  Created on: Mar 7, 2020
 *      Author: Dang Nam
 */

#include "command_respond.h"
#include "robot_scara.h"
#include <stdio.h>
#include <string.h>

extern const char *DETAIL_STATUS[NUM_OF_STATUS];

const char *ROBOTCOMMAND[NUM_OF_COMMAND - 1]  = {"STOP",
												"SCAN",
												"HOME",
												"MOVL",
												"MOVC",
												"MOVJ",
												"ROTA",
												"OUTP",
												"READ",
												"POSI",
												"SETT",
												"METH",  // 12 nomal

										        "JNEW",
										        "JDEL",
										        "JPML",
										        "JPMJ",
										        "JPOP",
										        "JTES",
										        "JRUN ", // 7 job

										        "KEYB",  // 2 key board
												"KSPE"
												};

const char *ROBOTRESPOND[NUM_OF_RESPOND]  	  = {"IDLE",
												"BUSY",
												"POSI",
												"STAR",
												"RUNN",
												"DONE",
												"STOP",
												"ERRO",
												"OKAY"};


Robot_CommandTypedef 	commandRead	(uint8_t *message, int32_t length, int32_t *id_command, DUTY_Command_TypeDef *duty_cmd) {
	Transfer_Protocol protocol_id = message[0];
    Robot_CommandTypedef command_id = message[1];
    duty_cmd->id_command = command_id;
	int32_t temp_pointer = 2;
    switch(protocol_id) 
    {

        // reserved for Gcode file transfer
        case FILE_TRANSMISION:
        {
            ;
        }
        break;

        // command control from pc
        case COMMAND_TRANSMISION:
        {
            switch(command_id)
            {
                // Stop now
                case CMD_STOPNOW:
                {
                    duty_cmd->robot_mode = SCARA_MODE_STOP;
                    duty_cmd->robot_method = SCARA_METHOD_SEMI_AUTO;
                    duty_cmd->change_method = FALSE;
                    return CMD_STOPNOW;
                }
                break;

                // Scan limit
                case CMD_SCAN_LIMIT:
                {
                    duty_cmd->robot_mode = SCARA_MODE_SCAN;
                    duty_cmd->robot_method = SCARA_METHOD_SEMI_AUTO;
                    duty_cmd->change_method = FALSE;
                    return CMD_SCAN_LIMIT;
                }
                break;

                // Move home
                case CMD_MOVE_HOME:
                {
                    if (length == 18){ // 2 double number + 2 define byte
                        memcpy(&duty_cmd->v_factor, &message[temp_pointer+=8], 8);
						memcpy(&duty_cmd->a_factor, &message[temp_pointer], 8); 
                    }else{
                        return CMD_ERROR;
                    }
                    duty_cmd->target_point.x = 250;
                    duty_cmd->target_point.y = -200;
                    duty_cmd->target_point.z = 120;
                    duty_cmd->target_point.roll = 0;

                    duty_cmd->modeInit_type = DUTY_MODE_INIT_QVA;
                    duty_cmd->space_type = DUTY_SPACE_JOINT;
                    duty_cmd->joint_type = DUTY_JOINT_4DOF;
                    duty_cmd->robot_mode = SCARA_MODE_DUTY;
                    duty_cmd->robot_method = SCARA_METHOD_SEMI_AUTO;
                    duty_cmd->change_method = FALSE;
                    return CMD_MOVE_HOME;
                }
                break;

                // Move line
                case CMD_MOVE_LINE:
                {
                    if (length == 51){ // 6 double number + 1 byte number + 2 define byte
						scaraSetScanFlag();
						uint8_t mode_init;
						temp_pointer = -6;
						memcpy(&duty_cmd->target_point.x, &message[temp_pointer+=8], 8);
						memcpy(&duty_cmd->target_point.y, &message[temp_pointer+=8], 8);
						memcpy(&duty_cmd->target_point.z, &message[temp_pointer+=8], 8);
						memcpy(&duty_cmd->target_point.roll, &message[temp_pointer+=8], 8);
						memcpy(&duty_cmd->v_factor, &message[temp_pointer+=8], 8);
						mode_init = message[temp_pointer+=1];

						if(mode_init == DUTY_MODE_INIT_QVA){
							duty_cmd->modeInit_type = DUTY_MODE_INIT_QVA;
							memcpy(&duty_cmd->a_factor, &message[temp_pointer], 8);
						}else if(mode_init == DUTY_MODE_INIT_QVT){
							duty_cmd->modeInit_type = DUTY_MODE_INIT_QVT;
							memcpy(&duty_cmd->time_total, &message[temp_pointer], 8);
						}else{
							return CMD_ERROR;
						}
						duty_cmd->path_type = DUTY_PATH_LINE;
						duty_cmd->space_type = DUTY_SPACE_TASK;
					}else{
						return CMD_ERROR;
					}
					duty_cmd->robot_mode = SCARA_MODE_DUTY;
					duty_cmd->robot_method = SCARA_METHOD_SEMI_AUTO;
					duty_cmd->change_method = FALSE;
					return CMD_MOVE_LINE;
                }
				break;

				// Move circle
				case CMD_MOVE_CIRCLE:
				{
					return CMD_MOVE_CIRCLE;
				}
				break;

				// Move joint
				case CMD_MOVE_JOINT:
				{
					return CMD_MOVE_JOINT;
				}
				break;

				// Rotate Single
				case CMD_ROTATE_SINGLE:
				{
					return CMD_ROTATE_SINGLE;
				}
				break;

				// Set output
				case CMD_OUTPUT:
				{
					if(length == 3){ // 1 byte output value + 2 byte define
						int temp_pointer = 2;
						duty_cmd->sub_para_int = message[temp_pointer];
						return CMD_OUTPUT;
					}else{
						return CMD_ERROR;
					}					
				}
				break;

				// Read position
				case CMD_READ_POSITION:
				{
					return CMD_READ_POSITION;
				}
				break;			

				// Setting
				case CMD_SETTING:
				{
					if (length == 4){ // 2 byte configure + 2 byte define
						uint8_t mode_traject;
						uint8_t mode_coordinate;
						mode_coordinate = message[temp_pointer++];
						mode_traject = message[temp_pointer];

						if (mode_coordinate == DUTY_COORDINATES_ABS) {
							duty_cmd->coordinate_type = DUTY_COORDINATES_ABS;
						} else if (mode_coordinate == DUTY_COORDINATES_REL) {
							duty_cmd->coordinate_type = DUTY_COORDINATES_REL;
						} else {
							return CMD_ERROR;
						}

						if (mode_traject == DUTY_TRAJECTORY_LSPB) {
							duty_cmd->trajec_type = DUTY_TRAJECTORY_LSPB;
						} else if (mode_traject == DUTY_TRAJECTORY_SCURVE) {
							duty_cmd->trajec_type = DUTY_TRAJECTORY_SCURVE;
						} else {
							return CMD_ERROR;
						}
						return CMD_SETTING;
					}else{
						return CMD_ERROR;
					}
				}
				break;
				
				//Unknow command id
				default:
				{
					return CMD_ERROR;
				}
            }
        }
        break;

        //unknow protocol id
        default:
        {
            return PROTOCOL_ERROR;
        }
    }
}

Robot_RespondTypedef	commandReply	(Robot_CommandTypedef cmd_type,
										DUTY_Command_TypeDef duty_cmd,
										uint8_t *detail) {
	Robot_RespondTypedef ret;

	switch(cmd_type) {
	case CMD_STOPNOW:
	case CMD_SCAN_LIMIT:
	case CMD_MOVE_HOME:
	case CMD_MOVE_LINE:
	case CMD_MOVE_CIRCLE:
	case CMD_MOVE_JOINT:
	case CMD_ROTATE_SINGLE:
		ret = RPD_DUTY;
		break;
	case CMD_OUTPUT:
		{
			if (1 == duty_cmd.sub_para_int) {
				scaraSetOutput(1);
				strcpy( (char *)detail, "Output ON");
			} else if (0 == duty_cmd.sub_para_int) {
				scaraSetOutput(0);
				strcpy( (char *)detail, "Output OFF");
			} else {
				strcpy( (char *)detail, "Wrong Value");
				return RPD_ERROR;
			}
			ret = RPD_OK;
		}
		break;
	case CMD_READ_STATUS:
		{
			SCARA_ModeTypeDef		current_mode;
			SCARA_DutyStateTypeDef 	current_state;
			current_mode	 = scaraGetMode();
			current_state	 = scaraGetDutyState();
			if ( SCARA_MODE_DUTY == current_mode && SCARA_DUTY_STATE_READY == current_state) {
				ret = RPD_IDLE;
			} else {
				ret = RPD_BUSY;
			}
		}
		break;
	case CMD_READ_POSITION:
		{
			SCARA_PositionTypeDef position;
			scaraGetPosition(&position);
			//scaraPosition2String((char *)detail, position);
			scaraPosition_packaging(detail, position);
			ret =  RPD_POSITION;
		}
		break;
	case CMD_SETTING:
		if ( DUTY_COORDINATES_ABS == duty_cmd.coordinate_type) {
			strcpy( (char *)detail, "ABSOLUTE.");
		} else if ( DUTY_COORDINATES_REL == duty_cmd.coordinate_type) {
			strcpy( (char *)detail, "RELATIVE.");
		} else {
			strcat((char *)detail, DETAIL_STATUS[SCARA_STATUS_ERROR_COORDINATE]);
			return RPD_ERROR;
		}

		if ( DUTY_TRAJECTORY_LSPB == duty_cmd.trajec_type) {
			strcat((char *)detail, " LSPB");
		} else if ( DUTY_TRAJECTORY_SCURVE == duty_cmd.trajec_type) {
			strcat((char *)detail, " S-CURVE");
		} else {
			strcat((char *)detail, DETAIL_STATUS[SCARA_STATUS_ERROR_TRAJECTORY]);
			return RPD_ERROR;
		}
		ret = RPD_OK;
		break;
	case CMD_METHOD_CHANGE:
		ret = RPD_DUTY;
		break;
	case CMD_JOB_NEW:
		break;
	case CMD_JOB_DELETE:
		break;
	case CMD_JOB_PUSH_MOVE_LINE:
		break;
	case CMD_JOB_PUSH_MOVE_JOINT:
		break;
	case CMD_JOB_PUSH_OUTPUT:
		break;
	case CMD_JOB_TEST:
		break;
	case CMD_JOB_RUN:
		ret = RPD_DUTY;
		break;
	case CMD_KEYBOARD:
		ret = RPD_DUTY;
		break;
	case CMD_KEY_SPEED:
		sprintf((char*) detail, "MANUAL SPEED = %d", duty_cmd.key_speed);
		ret = RPD_OK;
		break;
	case CMD_ERROR:
		strcpy( (char *)detail, "Check parameters");
		ret = RPD_ERROR;
		break;
	default:
		strcpy( (char *)detail, "Unknown command");
		ret = RPD_ERROR;
	}
	return ret;
}


int32_t				commandRespond	(Robot_RespondTypedef rpd,
										int32_t id_command,
										char *detail,
										char *respond) {
	int out_lenght;
	switch(rpd) {
	case RPD_IDLE:
	case RPD_BUSY:
		{
			uint8_t		isScanLitmit;
			isScanLitmit = scaraIsScanLimit();
			out_lenght = snprintf( (char *)respond,
									20,
									"%d %s %d",
									(int)id_command,
									ROBOTRESPOND[rpd],
									(int)isScanLitmit);
		}
		break;
	case RPD_POSITION:
	case RPD_START:
	case RPD_RUNNING:
	case RPD_DONE:
	case RPD_STOP:
	case RPD_ERROR:
	case RPD_OK:

		{
			out_lenght = snprintf( (char *)respond,
									145,
									"%d %s %s",
									(int)id_command,
									ROBOTRESPOND[rpd],
									(char *)detail);
		}
		break;
	default:
		out_lenght = 0;
	}

	return (int32_t)out_lenght;
}
