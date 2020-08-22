var socket = io("http://localhost:3000");
//var Struct = require("struct");
/*var realtime_data = Struct.word16Sbe('pv_vol').word16Sbe('pv_current').word32Sle('pv_power').word16Sbe('bat_vol').word16Sbe('bat_current').word32Sle('bat_power')
								.word16Sbe('load_vol').word16Sbe('load_current').word32Sle('load_power').word16Sbe('bat_temp').word16Sbe('temp_in').word16Sbe('bat_percent');
var statistic_data = Struct.word16Sbe('max_pv_vol_today').word16Sbe('min_pv_vol_today').word16Sbe('max_bat_vol_today').word16Sbe('min_bat_vol_today').word32Sle('con_energy_today')
								.word32Sle('bat_power').word32Sle('con_energy_month').word32Sle('con_energy_year').word32Sle('total_con_energy').word32Sle('gen_energy_today')
								.word32Sle('gen_energy_month').word32Sle('gen_energy_year').word32Sle('total_gen_energy');
realtime_data.allocate();
statistic_data.allocate();
var realtime_union_buf = realtime_data.buffer();
var statistic_union_buf = statistic_data.buffer();
var struct_statistic_data= statistic_data.fields;
var struct_realtime_data = realtime_data.fields;
var test_buffer = Buffer.from([12, 23, 34, 34]);
socket.on("realtime_data", function(data){
	//data has been converted to buffer type
	data.copy(realtime_union_buf, 0, 0, realtime_union_buf.length);
	$("#solar_voltage").val((struct_realtime_data.pv_vol/100).toString());
	$("#bat_power").val((struct_realtime_data.bat_power/100).toString());
	$("#bat_percent").val((struct_realtime_data.bat_percent/100).toString());
	$("#solar_power").val((struct_realtime_data.pv_power/100).toString());
	$("#bat_voltage").val((struct_realtime_data.bat_vol/100).toString());
	$("#load_power").val((struct_realtime_data.load_power/100).toString());
	$("#bat_current").val((struct_realtime_data.bat_current/100).toString());
	$("#load_voltage").val((struct_realtime_data.load_vol/100).toString());
	$("#bat_temp_status").val((struct_realtime_data.bat_temp/100).toString());
	$("#load_current").val((struct_realtime_data.load_current/100).toString());
})
socket.on("statistic_data", function(data){
	//data.copy(statistic_union_buf, 0, 0, statistic_union_buf.length);
	socket.emit("load_relay", data);
})*/
socket.on("ar", function(data){
	var temp = data.split('/');
	$("#input").val(temp[0]);
	$("#input1").val(temp[1]);
})
$(document).ready(function(){
	socket.emit("load_relay", test_buffer);
	$("#statistic_request").click(function(){
		socket.emit("statistic_request");
	})
	$("#onoff_load").click(function(){
		socket.emit("load_relay");
	})
	$("#nut").click(function(){
		$("#input").val("hahaha");
		socket.emit("load_relay",test_buffer);
	})
});