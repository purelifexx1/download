#ifndef DEFINE_PARAMETER_H
#define DEFINE_PARAMETER_H

#include <QtCore>
#define SCARA_FOWARD_SCALE 1000000
#define SCARA_INVERSE_SCALE 0.000001
#define NUM_OF_STATUS 23
#define NUM_OF_COMMAND_STRING 24
typedef enum
{
    DISPLAY_POSITION,
    DISPLAY_ERROR
}display_id ;

typedef enum
{
    MAGNET_ON,
    MAGNET_OFF,
    WRONG_VALUE_FOR_OUTPUT_LEVEL
}Response_Detail_code;

typedef enum
{
    ACCEPT_COMMAND,
    STUPID_CODE,
    WRONG_SPACE_TYPE,
    WRONG_TASK_TYPE,
    WRONG_JOINT_TYPE,
    WRONG_TRAJECTORY_TYPE,
    WRONG_PARAMETER,
    OVER_WORKSPACE,
    WRONG_MODE_INIT,
    OVER_VELOCITY,
    OVER_ACCELERATE,
    WRONG_JOINT_NUM,
    WRONG_COORDINATE,
    OUTPUT_ON,
    OUTPUT_OFF,
    WRONG_OUTPUT_VALUE,
    ABSOLUTE,
    RELATIVE,
    LSPB,
    S_CURVE,
    CHECK_PARAMETER,
    MANUAL_SPEED,
    UNKNOW_COMMAND
}Response_ID;

typedef enum
{
    RPD_IDLE	,
    RPD_BUSY	,
    RPD_POSITION,
    RPD_START	,
    RPD_RUNNING	,
    RPD_DONE	,
    RPD_STOP	,
    RPD_ERROR	,
    RPD_OK 		,
    RPD_DUTY	,
    NUM_OF_RESPOND
}Robot_RespondTypedef;

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
    PROTOCOL_ERROR,
    NUM_OF_COMMAND
}Robot_CommandTypedef ;

typedef enum
{
    FILE_TRANSMISION,
    COMMAND_TRANSMISION,
    RESPONSE_TRANSMISION
}Transfer_Protocol;

typedef enum
{
    FLOAT_STRING_VALUE,
    FLOAT_VALUE,
    DOUBLE_STRING_VALUE,
    DOUBLE_VALUE,
    BYTE_VALUE,
    INT16_VALUE,
    SCARA_COR_VALUE
}TypeDef_Conversion ;

typedef struct
{
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t roll;
    int32_t theta1;
    int32_t theta2;
    int32_t D3;
    int32_t theta4;
}Scara_position_TypeDef ;

typedef struct
{
    display_id action_id;
    Scara_position_TypeDef Scara_position;
    Robot_CommandTypedef Command_ID;
    Robot_RespondTypedef Respond_Type;
    Response_ID Reference_String;
}Display_packet ;

class define_parameter
{

public:
    QString DETAIL_STATUS[NUM_OF_STATUS]  = {"Accept Command",
                                             "Stupid Code",
                                             "Wrong Space Type",
                                             "Wrong Task Type",
                                             "Wrong Joint Type",
                                             "Wrong Trajectory Type",
                                             "Wrong Parameters",
                                             "Over Workspace",
                                             "Wrong Mode Init",
                                             "Over Velocity",
                                             "Over Accelerate",
                                             "Wrong Joint Num",
                                             "Wrong Coordinate type",
                                             "Output On",
                                             "Output Off",
                                             "Wrong output value",
                                             "Absolute",
                                             "Relative",
                                             "LSPB",
                                             "S-CURVE",
                                             "Check parameter",
                                             "Manual speed ",
                                             "Unknow command"
                                            };
    QString COMMAND_STRING[NUM_OF_COMMAND_STRING] = {
        "CMD_STOPNOW",
        "CMD_SCAN_LIMIT",
        "CMD_MOVE_HOME",
        "CMD_MOVE_LINE",
        "CMD_MOVE_CIRCLE",
        "CMD_MOVE_JOINT",
        "CMD_ROTATE_SINGLE",
        "CMD_OUTPUT",
        "CMD_READ_STATUS",
        "CMD_READ_POSITION",
        "CMD_SETTING",
        "CMD_METHOD_CHANGE",

        "CMD_JOB_NEW",
        "CMD_JOB_DELETE",
        "CMD_JOB_PUSH_MOVE_LINE",
        "CMD_JOB_PUSH_MOVE_JOINT",
        "CMD_JOB_PUSH_OUTPUT",
        "CMD_JOB_TEST",
        "CMD_JOB_RUN",// 7 job

        "CMD_KEYBOARD",// 2 key board
        "CMD_KEY_SPEED",
        "CMD_ERROR",
        "PROTOCOL_ERROR",
        "NUM_OF_COMMAND"
    };
    define_parameter();
    void Convert_And_Append(QByteArray *object_array, QVariant convert_object, TypeDef_Conversion input_type);
};

#endif // DEFINE_PARAMETER_H
