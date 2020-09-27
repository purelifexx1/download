//var socket = io("localhost:3069");
var socket = io("http://localhost:3000");
var button_status;
socket.on("realtime_data", function(data){
	Object.entries(data).forEach(function(element){
		document.getElementById(element[0]).style.background = '#4aff36';
		$("#" + element[0]).val(element[1]);
	});
	setTimeout(set_color_off, 2000, data);
})
socket.on("statistic_data", function(data){
	Object.entries(data).forEach(function(element){
		document.getElementById(element[0]).style.background = '#4aff36';
		$("#" + element[0]).val(element[1]);
	});
	setTimeout(set_color_off, 2000, data);
})
socket.on("ar", function(data){
	$("#solar_voltage").style.background = "#2e0101";
})


socket.on("onoff_load_confirm", function(data){
	//display button status at here
	if(data == "1") {
		document.getElementById("onoff_load").style.background = '#4aff36';
		button_status[5] = "1";
	}
	else {
		button_status[5] = "0";
		document.getElementById("onoff_load").style.background = "#e83017";
	}
})
socket.on("control_status_data", function(data){
	//color status for button
	Object.entries(data).forEach(function(element){
		if(element[1] == true){
			button_status.push("1");
			document.getElementById(element[0]).style.background='#4aff36';
		}
		else{
			button_status.push("0");
			document.getElementById(element[0]).style.background='#e83017';
		}
	})
	
})
socket.on("packet_ongoing", function(data){
	//status text
	//run timer for text
})

socket.on("packet_lost", function(data){
	
})

socket.on("error", function(data){
	
})

socket.on("server_update_enable", function(data){
	if(data == true) {
		//update button green or checkbox's ticked
		document.getElementById("first_check").checked = false;
	}else{
		//update button red or checkbox's unticked
		document.getElementById("first_check").checked = false;
	}
})

$(document).ready(function(){
	$("#nut").click(function(){
		socket.emit("hello");
	})
	$("#statistic_request").click(function(){
		socket.emit("statistic_request");
	})
	$("#onoff_load").click(function(){
		if(button_status[5] == "1") socket.emit("onoff_load", "0");
		else socket.emit("onoff_load", "1");
	})
	$("#bt-2").click(function(){
		socket.emit("statistic_request");
		// socket.emit("output_control");
		console.log("ok nha");
	})
	$("#first_check").click(function(){
		if(this.checked) {
			socket.emit("change_update_enable");
		}else{
			console.log("uncheck");
		}
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
	$("#onoff_charging").click(function(){
		socket.emit("onoff_charging");
	})
});

function set_color_off(data) {
	Object.entries(data).forEach(function(element){
		document.getElementById(element[0]).style.background = '#ffffff';
	})
};
