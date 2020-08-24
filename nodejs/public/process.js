//var socket = io("localhost:3069");
var socket = io("http://localhost:3000");
var ss = require("struct");
var realtime_data_id = ["solar_voltage", "bat_power", "bat_percent", "solar_power", "bat_voltage", 
						"load_power", "bat_current", "load_voltage", "bat_temp_status", "load_current"];
var statistic_data_id;
var control_button_id = []
socket.on("realtime_data", function(data){
	var count = 0;
    var temper = data.split('/');
    realtime_data_id.forEach(function(x){
    	$("#" + x).val(temper[count++]);
    });
})
socket.on("statistic_data", function(data){
	var temper = data.split('/');
})
socket.on("ar", function(data){
	var ee = Buffer.from(data, 'utf8');
	$("#solar_voltage").val(ee[1]);
})
socket.on("onoff_load_confirm", function(data){
	//display button status at here
})
socket.on("control_status_data", function(data){
	//color status for button
	var control_value = data.name;
	

	
})
socket.on("packet_ongoing", function(data){
	//status text
	//run timer for text
})
$(document).ready(function(){
	$("#nut").click(function(){
		socket.emit("hello");
	})
	$("#statistic_request").click(function(){
		socket.emit("statistic_request");
	})
	$("#onoff_load").click(function(){
		socket.emit("onoff_load");
	})
	$("#output_control").click(function(){
		socket.emit("output_control");
	})
	$("#manual_control").click(function(){
		socket.emit("manual_control");
	})
	$("#default_control").click(function(){
		socket.emit("default_control");
	})
	$("#load_testmode").click(function(){
		socket.emit("load_testmode");
	})


});