
const table = require("./modbus_table");
const rf_table = table.reference_table;

var send_object_data = {};
function data_handler(data_packet, io){
    var number_of_packet = data_packet[0];
    var current_pointer = 1;
    var send_update_object = {};
    for( var i = 0; i < number_of_packet; i++){
        switch(data_packet[current_pointer]){
            case 1:
                var data_pointer = current_pointer + 2;
                
            break;
            case 4:
                
                var data_pointer = current_pointer + 4;
                var start_register_address = data_packet[current_pointer+1] << 8 | data_packet[current_pointer+2];
                var number_of_register = data_packet[current_pointer+3]/2;
                for(var j = start_register_address; j < start_register_address+number_of_register; j++){
                    var object_title = rf_table[j.toString()];
                    if (object_title.startsWith("*")){
                        var number = (data_packet[data_pointer+2] << 24) | (data_packet[data_pointer+3] << 16)| (data_packet[data_pointer] << 8)| data_packet[data_pointer+1];
                        data_pointer+=4;
                        j++;
                        send_update_object[object_title.replace("*","")] = number/100;
                    }else if(object_title.startsWith("$")){
                        data_pointer+=2;
                    }
                    else{
                        
                        var number = (data_packet[data_pointer] << 8) | data_packet[data_pointer+1];
                        data_pointer+=2;
                        send_update_object[object_title] = number/100;
                        
                    }
                }
                current_pointer += number_of_register*2 + 4;
            break;
        }
    }
    console.log(send_update_object);
    io.sockets.emit("packet_update", send_update_object);
}
module.exports.data_handler = data_handler;
