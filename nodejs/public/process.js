var socket = io("http://localhost:3000");

socket.on("realtime_data", function(data){
    var temper = data.split('/');
	$("#solar_voltage").val(temper[0]);
	$("#bat_power").val(temper[1]);
	$("#bat_percent").val(temper[2]);
	$("#solar_power").val(temper[3]);
	$("#bat_voltage").val(temper[4]);
	$("#load_power").val(temper[5]);
	$("#bat_current").val(temper[6]);
	$("#load_voltage").val(temper[7]);
	$("#bat_temp_status").val(temper[8]);
	$("#load_current").val(temper[9]);
})
socket.on("statistic_data", function(data){
	var temper = data.split('/');
})
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