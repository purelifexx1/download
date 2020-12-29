#ifndef DEFINE_PARAMETER_H
#define DEFINE_PARAMETER_H

#include <QtCore>

typedef enum
{
    DISPLAY_POSITION
}display_id ;

typedef enum
{
    POSITION_DATA = 0x09
}command_code ;

typedef enum
{
      DUTY_MODE_INIT_QVA				= 0x00U,  /*!< Consume A max, determine T max */
      DUTY_MODE_INIT_QVT				= 0x01U  /*!< Consume T max, determine A max   */
}ModeInitTypeDef;

typedef enum
{
      DUTY_COORDINATES_ABS				= 0x00U,  /*!< Absolute position */
      DUTY_COORDINATES_REL				= 0x01U  /*!< Relative position*/
}CoordinatesTypeDef;

typedef enum
{
      DUTY_TRAJECTORY_LSPB				= 0x00U,  /*!< Trajectory planning LSBP */
      DUTY_TRAJECTORY_SCURVE			= 0x01U  /*!< Trajectory planning S-curve */
}TrajectoryTypeDef;

typedef enum
{
    SCARA_KEY_X_INC,
    SCARA_KEY_X_DEC,
    SCARA_KEY_Y_INC,
    SCARA_KEY_Y_DEC,
    SCARA_KEY_Z_INC,
    SCARA_KEY_Z_DEC,
    SCARA_KEY_ROLL_INC,
    SCARA_KEY_ROLL_DEC,
    SCARA_KEY_VAR0_INC,
    SCARA_KEY_VAR0_DEC,
    SCARA_KEY_VAR1_INC,
    SCARA_KEY_VAR1_DEC,
    SCARA_KEY_VAR2_INC,
    SCARA_KEY_VAR2_DEC,
    SCARA_KEY_VAR3_INC,
    SCARA_KEY_VAR3_DEC,// 16 key board
}SCARA_KeyTypeDef;

typedef enum
{
    CMD_STOPNOW,
    CMD_SCAN_LIMIT,
    CMD_MOVE_HOME,
    CMD_MOVE_LINE,
    CMD_MOVE_CIRCLE,
    CMD_MOVE_JOINT,
    CMD_ROTATE_SINGLE,
    CMD_OUTPUT,
    CMD_READ_STATUS,
    CMD_READ_POSITION,
    CMD_SETTING,
    CMD_METHOD_CHANGE,

    CMD_JOB_NEW,
    CMD_JOB_DELETE,
    CMD_JOB_PUSH_MOVE_LINE,
    CMD_JOB_PUSH_MOVE_JOINT,
    CMD_JOB_PUSH_OUTPUT,
    CMD_JOB_TEST,
    CMD_JOB_RUN,// 7 job

    CMD_KEYBOARD,// 2 key board
    CMD_KEY_SPEED,
    CMD_ERROR,
    NUM_OF_COMMAND
}Robot_CommandTypedef ;

typedef enum
{
    FILE_TRANSMISION,
    COMMAND_TRANSMISION
}Transfer_Protocol;

typedef enum
{
    FLOAT_STRING_VALUE,
    FLOAT_VALUE,
    DOUBLE_STRING_VALUE,
    DOUBLE_VALUE,
    BYTE_VALUE,
    INT16_VALUE
}TypeDef_Conversion ;

typedef struct
{
    double current_time;
    double total_time;
    double x;
    double y;
    double z;
    double roll;
    double theta1;
    double theta2;
    double D3;
    double theta4;
}Scara_position_TypeDef ;

typedef struct
{
    display_id action_id;
    Scara_position_TypeDef Scara_position;
}Display_packet ;

class define_parameter
{

public:

    define_parameter();
    void Convert_And_Append(QByteArray *object_array, QVariant convert_object, TypeDef_Conversion input_type);
};

#endif // DEFINE_PARAMETER_H
