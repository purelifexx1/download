var express = require("express");
var firebase = require("firebase");
var modbus = require('./modbus_handler');
var request = require('./create_encoded_request');
var path = require("path");
firebase.initializeApp({
	databaseURL: "https://archive-34c94.firebaseio.com"
});
var main_branch = firebase.database().ref("Data");
var data_handler = require("./second");
var app = express();
app.use(express.static("public"));
app.set("view engine", "ejs");
app.set("views", path.join(__dirname, 'views'));
var server = require("http").Server(app);
var io = require("socket.io")(server);

var mqtt = require('mqtt');
var waitfor_reply = false;

var mqtt_branch = firebase.database().ref("mqtt configuration");

var client;
var storage_packet = {
	"topic": "",
	"message": "",
	"topic_timeout": "",
	"content_timeout": ""
};
var archive_packet = {};


var user_number = 0;
var latch = true;
var timer_latch;
var timeout_latch;
var mqtt_status = false;
var server_update = false;
var sec_value = 0;
var connection_status_interval = 0;

setInterval(function(){
	if(server_update == true) {
		sec_value++;
		if(sec_value < 3600) {
			//send data to firebase
			data_handler.update_server(main_branch);
			sec_value = 0;
		}
		server_update = false;
	}
}, 1000);

function timer(){
	if (mqtt_status == true && waitfor_reply == false) {
		console.log("send");
		var real_time_request = {
			"1":{
				"function_code": 4,
				"start_address": "3100",
				"number_of_register": 8
			},
			"2":{
				"function_code": 4,
				"start_address": "310c",
				"number_of_register": 6
			},
			"3":{
				"function_code": 4,
				"start_address": "311a",
				"number_of_register": 1
			}
		}
		request.create_request(real_time_request, function(buf){
			client.publish('data_request', buf);	
		})			
		storage_packet.topic_timeout = 'data_request';
		storage_packet.content_timeout = "0";
		timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
		waitfor_reply = true;		

	}
}

var realtime_buf = data_handler.realtime_buf;
var statistic_buf = data_handler.statistic_buf;

io.on('connection', function(socket){
	console.log("co nguoi connect");	
	
	user_number++;
	socket.on("change_update_enable", function(data){
		server_update = !server_update;
		io.sockets.emit("server_update_enable", server_update);
		sec_value = 0;
	})

	socket.on("update_database", function(data){
		data_handler.update_server(main_branch);
	})

	socket.on("statistic_request", function(data){
		console.log("send request statistic");
		var statistic_request = {
			"1":{
				"function_code": 4,
				"start_address": "3300",
				"number_of_register": 20
			}
		}
		if(waitfor_reply == false){			
			request.create_request(statistic_request, function(buf){
				client.publish('data_request', buf); 
			})		
			storage_packet.topic_timeout = 'data_request';
			storage_packet.content_timeout = "1";
			timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
			waitfor_reply = true;			
		}else{
			socket.emit("packet_ongoing");			
			request.create_request(statistic_request, function(buf){
				archive_packet["2"] = {
					"topic": "data_request",
					"message": buf,
					"content_timeout": "1"
				};
			})
		}
		
	})
	socket.on("control_status_request", function(data){
		if(waitfor_reply == false){
			
			timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
			waitfor_reply = true;
			client.publish("data_request", "2");
		}else{
			socket.emit("packet_ongoing");
			storage_packet.topic = "data_request";
			storage_packet.message = "2";
		}
	})

	socket.on("onoff_load", function(data){
		if(waitfor_reply == false) {
			timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
			waitfor_reply = true;
			if (data == "1") {}
			client.publish("write_coils", "0" + data);
		}else{
			socket.emit("packet_ongoing");
			storage_packet.topic = "onoff_load";
			storage_packet.message = "0" + data;
		}
	})


	socket.on("disconnect", function(){
		user_number--;
		if (user_number == 0) {
			latch = true;
			clearInterval(timer_latch);
		}
	})
	if (user_number != 0 && latch == true) {
		latch = false;
		timer_latch = setInterval(timer, 8000);
	}
})

mqtt_branch.once('value', function(snap){
	client = mqtt.connect("mqtt://node02.myqtthub.com", snap.val());
	client.on('connect', function(){
		mqtt_status = true;
		console.log("mqtt broker connected");
		client.subscribe('realtime_data');
		client.subscribe('statistic_data');
		client.subscribe('control_status_data');
		client.subscribe('onoff_load_confirm');
		client.subscribe('error');
		client.on('message', function(topic, message){

			if(topic == 'realtime_data') {
				connection_status_interval = 0;
				clearTimeout(timeout_latch);
				console.log("da nhan");
				//message.copy(realtime_buf, 0, 0, message.length);
				//data_handler.realtime_send(io);	
				modbus.data_handler(message, io);
				waitfor_reply = false;
				send_wait_in_line_packet(storage_packet);
			}

			if(topic == 'statistic_data') {
				connection_status_interval = 0;
				clearTimeout(timeout_latch);
				message.copy(statistic_buf, 0, 0, message.length);
				data_handler.statistic_send(io);
				waitfor_reply = false;
				send_wait_in_line_packet(storage_packet);
			}

			if(topic == 'control_status_data'){
				connection_status_interval = 0;
				clearTimeout(timeout_latch);
				data_handler.control_status_send(io, message);
				send_wait_in_line_packet(storage_packet);
			}

			if(topic == 'onoff_load_confirm'){
				clearTimeout(timeout_latch);
				if(message[0] == 256) io.sockets.emit("onoff_load_confirm", "1");
				else io.sockets.emit("onoff_load_confirm", "0");
				send_wait_in_line_packet(storage_packet);
			}
			if(topic == 'error'){
				connection_status_interval = 0;
				clearTimeout(timeout_latch);
				waitfor_reply = false;
				data_handler.log_error(io, message)
			}
		})

		client.on('disconnect', function(){
			mqtt_status = false;
			console.log("mqtt disconnect");
		})
	})
})

function send_wait_in_line_packet(storage_packet){

	if(Object.keys(archive_packet).length != 0){
		var wait_in_line = Object.keys(archive_packet).map(function(item){
			return parseInt(item, 10);
		});
		var send_object = Math.min(...wait_in_line).toString();
		console.log("gui archive")
		client.publish(archive_packet[send_object].topic, archive_packet[send_object].message);
		storage_packet.topic_timeout = archive_packet[send_object].topic;
		storage_packet.content_timeout = archive_packet[send_object].content_timeout;
		waitfor_reply = true;
		timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
		delete archive_packet[send_object];
	}
	// if(storage_packet.topic != "" && storage_packet.message != ""){
	// 	timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
	// 	waitfor_reply = true;
	// 	client.publish(storage_packet.topic, storage_packet.message);
	// 	storage_packet.topic = "";
	// 	storage_packet.message = "";
	// }	
}
function timeout_function(storage_packet){
	console.log("timeout");
	if(storage_packet.topic_timeout == "data_request") {		
		connection_status_interval++;
	}
	if(connection_status_interval > 5) {
		data_handler.log_error(io, "2");
	}

	io.sockets.emit("packet_lost", storage_packet.content_timeout);
	waitfor_reply = false
	send_wait_in_line_packet(storage_packet);
}
server.listen(3000);
app.get("/", function(req, res){
	res.render("index1");
})