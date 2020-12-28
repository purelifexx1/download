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
    switch (packet.at(0)) {
        case POSITION_DATA:
            Scara_position_received(packet.mid(1, packet_length - 2));
        break;
    }
}

void packet_handler::Scara_position_received(QByteArray data)
{
    Scara_position_TypeDef *Scara_position_data = reinterpret_cast<Scara_position_TypeDef*>(data.data());
    Display_packet display_packet;
    display_packet.Scara_position.D3 = Scara_position_data->D3;
    display_packet.Scara_position.current_time = Scara_position_data->current_time;
    display_packet.Scara_position.roll = Scara_position_data->roll;
    display_packet.Scara_position.theta1 = Scara_position_data->theta1;
    display_packet.Scara_position.theta2 = Scara_position_data->theta2;
    display_packet.Scara_position.theta4 = Scara_position_data->theta4;
    display_packet.Scara_position.total_time = Scara_position_data->total_time;
    display_packet.Scara_position.x = Scara_position_data->x;
    display_packet.Scara_position.y = Scara_position_data->y;
    display_packet.Scara_position.z = Scara_position_data->z;
    display_packet.action_id = DISPLAY_POSITION;
    emit on_display_event(display_packet);
}
