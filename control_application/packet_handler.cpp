#include "packet_handler.h"

packet_handler::packet_handler()
{

}

void packet_handler::categorize(QByteArray packet)
{
    int packet_length = packet.length();
    if(packet.at(0) == 0x28 && packet.at(packet_length-1) == 0x29){
        //full packet receive
        archive_buffer.clear();
        routing(packet.mid(1, packet_length - 2));
    }else if(packet.at(0) == 0x28 && packet.at(packet_length-1) != 0x29){
        //packet to long, receive first half
        archive_buffer.append(packet);
        archive_status = true;
    }else if(packet.at(0) != 0x28 && packet.at(packet_length-1) == 0x29){
        //receive rest
        if(archive_status == true){
            archive_status = false;
            archive_buffer.append(packet);
            routing(archive_buffer.mid(1, archive_buffer.length() - 2));
            archive_buffer.clear();
        }else{

        }
    }else{
        //error packet format
    }
}

void packet_handler::routing(QByteArray packet)
{
    int packet_length = packet.length();
    switch (packet.at(0)){ // Transmission protocol
        case FILE_TRANSMISION:

        break;
        case COMMAND_TRANSMISION:
            // error format
        break;
        case RESPONSE_TRANSMISION:
            switch (packet.at(1)) { // RPD type
                case RPD_IDLE:

                break;
                case RPD_BUSY:

                break;
                case RPD_POSITION:
                    if(packet.at(2) == CMD_READ_POSITION){ // check if CMD_ID is correct
                        Scara_position_received(packet.mid(3, packet_length-3));
                    }else{
                        // incorrect packet format
                    }
                break;
                case RPD_START:

                break;
                case RPD_RUNNING:

                break;
                case RPD_DONE:

                break;
                case RPD_STOP:

                break;
                case RPD_ERROR:
                    Error_Handler(packet.mid(0, packet_length-2));
                break;
                case RPD_OK:

                break;
                case RPD_DUTY:

                break;
                case NUM_OF_RESPOND:

                break;
            }
        break;
    }
}

void packet_handler::Scara_position_received(QByteArray data)
{
    Scara_Position_RawData *RawData = reinterpret_cast<Scara_Position_RawData*>(data.data());
    Display_packet display_packet;

    display_packet.RealData.theta1 = (double)(RawData->raw_theta1*SCARA_INVERSE_SCALE);
    display_packet.RealData.theta2 = (double)(RawData->raw_theta2*SCARA_INVERSE_SCALE);
    display_packet.RealData.theta4 = (double)(RawData->raw_theta4*SCARA_INVERSE_SCALE);
    display_packet.RealData.D3 = (double)(RawData->raw_D3*SCARA_INVERSE_SCALE);
    display_packet.RealData.x = (double)(RawData->raw_x*SCARA_INVERSE_SCALE);
    display_packet.RealData.y = (double)(RawData->raw_y*SCARA_INVERSE_SCALE);
    display_packet.RealData.z = (double)(RawData->raw_z*SCARA_INVERSE_SCALE);
    display_packet.RealData.roll = (double)(RawData->raw_roll*SCARA_INVERSE_SCALE);
    display_packet.action_id = DISPLAY_POSITION;
    emit on_display_event(display_packet);
}

void packet_handler::Error_Handler(QByteArray data)
{
    Display_packet display_packet;
    display_packet.Respond_Type = RPD_ERROR;
    display_packet.action_id = DISPLAY_ERROR;
    switch(data.at(0)){
    case CMD_STOPNOW               :
    {

    }
    break;
    case CMD_SCAN_LIMIT            :
    case CMD_MOVE_HOME             :
    {
        display_packet.Command_ID = CMD_MOVE_HOME;
        display_packet.Reference_String = (Response_ID)data.at(1);
    }
    break;
    case CMD_MOVE_LINE             :
    case CMD_MOVE_CIRCLE           :
    case CMD_MOVE_JOINT            :
    case CMD_ROTATE_SINGLE         :
    case CMD_OUTPUT                :
    case CMD_READ_STATUS           :
    case CMD_READ_POSITION         :
    case CMD_SETTING               :
    case CMD_METHOD_CHANGE         :
    case CMD_JOB_NEW               :
    case CMD_JOB_DELETE            :
    case CMD_JOB_PUSH_MOVE_LINE    :
    case CMD_JOB_PUSH_MOVE_JOINT   :
    case CMD_JOB_PUSH_OUTPUT       :
    case CMD_JOB_TEST              :
    case CMD_JOB_RUN               :
    case CMD_KEYBOARD              :
    case CMD_KEY_SPEED             :
    case CMD_ERROR                 :
    case PROTOCOL_ERROR            :
    case NUM_OF_COMMAND            :
    break;

    }
    emit on_display_event(display_packet);
}
