//var socket = io("localhost:3000");
var socket = io("http://localhost:3000");
var button_status;
var button_namespace = {
	charging_onoff: false,
	load_control: false,
	manual_control: false,
	default_control: false,
	load_testmode: false,
	onoff_load: false
}
socket.on("packet_update", function(data){
	Object.entries(data).forEach(function(element){
		document.getElementById(element[0]).style.background = '#4aff36';
		$("#" + element[0]).val(element[1]);		
	});
	setTimeout(set_color_off, 2000, data);
})
socket.on("realtime_data", function(data){
	Object.entries(data).forEach(function(element){
		if(element[0].startsWith("@")){
			if (element[1] == 255) {
				document.getElementById(element[0].replace("@","")).style.background = '#4aff36';
				button_namespace[element[0].replace("@","")] = true;
			}
			else{
				document.getElementById(element[0].replace("@","")).style.background = '#eb240e';
				button_namespace[element[0].replace("@","")] = false;
			}
		}else{
			document.getElementById(element[0]).style.background = '#4aff36';
			$("#" + element[0]).val(element[1]);
		}
		
	});
	setTimeout(set_color_off, 2000, data);
	
	// Object.entries(data).forEach(function(element){
	// 	if(element[0] == "button_status"){
	// 		var count_shift = 0;
	// 		for(var i = 0; i< 6; i++){
	// 			if (((element[1] >> count_shift++) & 1) == 1)
	// 				document.getElementById(Object.keys(button_namespace)[i]).style.background = '#22ed0c';
	// 			else
	// 				document.getElementById(Object.keys(button_namespace)[i]).style.background = '#f51707';
	// 		}
	// 	}else{
	// 		document.getElementById(element[0]).style.background = '#4aff36';
	// 		$("#" + element[0]).val(element[1]);
	// 	}
	// })
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

socket.on("packet_timeout", function(data){
	if (data == "0") {
		console_log("realtime packet timeout");
	}else if(data == "1"){
		console_log("statistic packet timeout");
	}
	
})

socket.on("error", function(data){
	console_log(data);
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
		console.log("ok nha");
	})
	$("#get_bt_status").click(function(){
		socket.emit("control_status_request");
	})
	$("#charging_onoff").click(function(){
		if(button_namespace.charging_onoff == true)
			socket.emit("change_coil_status", ["0000", "0", "1"]);
		else
			socket.emit("change_coil_status", ["0000", "255", "1"]);
	})
	$("#database_update").click(function(){
		socket.emit("update_database");
		console_log("new time stamp for realtime data has been updated")
	})
	$("#manual_control").click(function(){
		if(button_namespace.manual_control == true)
			socket.emit("change_coil_status", ["0003", "0", "2"]);
		else
			socket.emit("change_coil_status", ["0003", "255", 
		"2"]);
	})
	$("#load_control").click(function(){
		if(button_namespace.load_control == true)
			socket.emit("change_coil_status", ["0002", "0", "0"]);
		else
			socket.emit("change_coil_status", ["0002", "255", "0"]);
	})
	$("#load_testmode").click(function(){
		socket.emit("load_testmode");
	})
	$("#onoff_charging").click(function(){
		socket.emit("onoff_charging");
	})
});
function console_log(data) {
	var textarea = document.getElementById("unique");
	textarea.textContent += data + "\r\n";
	textarea.scrollTop = textarea.scrollHeight;
}
function set_color_off(data) {
	Object.entries(data).forEach(function(element){
		if(element[0].startsWith("@")){
			
		}else{
			document.getElementById(element[0]).style.background = '#ffffff';
		}
	})
};
