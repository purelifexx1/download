const Struct = require("struct");
var one_reg = Struct().word16Sbe('output');
var two_reg = Struct().word32Sbe('output');
one_reg.allocate();
two_reg.allocate();
var one_reg_buf = one_reg.buffer();
var two_reg_buf = two_reg.buffer();
var one_reg_field = one_reg.fields;
var two_reg_field = two_reg.fields;
var send_object_data = {};
function data_handler(data_packet){

}