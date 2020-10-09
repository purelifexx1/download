const Struct = require("struct");
const table = require("modbus_table");
const rf_table = table.reference_table;
var one_reg = Struct().word16Sbe('output');
var two_reg = Struct().word32Sbe('output');
one_reg.allocate();
two_reg.allocate();
var one_reg_buf = one_reg.buffer();
var two_reg_buf = two_reg.buffer();
var one_reg_field = one_reg.fields;
var two_reg_field = two_reg.fields;
var send_object_data = {};
function data_handler(data_packet, start_register_object, io){
    var number_of_packet = data_packet[0];
    var current_pointer = 2;
    var send_update_object = {};
    for( var i = 0; i < number_of_packet; i++){
        switch(data_packet[current_pointer]){
            case 1:
                var data_pointer = current_pointer + 2;
                
            break;
            case 4:
                var data_pointer = current_pointer + 2;
                var number_of_register = data_packet[current_pointer+1]/2;
                for(var j = start_register_object[i]; j < start_register_object[i]+number_of_register; j++){
                    var object_title = rf_table[j.toString()];
                    if (object_title.startsWith("*")){
                        two_reg_buf[2] = data_packet[data_pointer++];
                        two_reg_buf[3] = data_packet[data_pointer++];
                        two_reg_buf[0] = data_packet[data_pointer++];
                        two_reg_buf[1] = data_packet[data_pointer++];
                        send_update_object[object_title.replace("*","")] = two_reg_field.output/100;
                    }else{
                        one_reg_buf[0] = data_packet[data_pointer++];
                        one_reg_buf[1] = data_packet[data_pointer++];
                        send_update_object[object_title] = one_reg_buf.output/100;
                    }
                }
                current_pointer += number_of_register*2 + 4;
            break;
        }
    }
    io.sockets.emit("packet_update", send_update_object);
}
module.exports.data_handler = data_handler;
