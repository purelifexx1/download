var express = require("express");
var firebase = require("firebase");
firebase.initializeApp({
	databaseURL: "https://archive-34c94.firebaseio.com"
});
var main_branch = firebase.database().ref("Data");
var data_handler = require("./second");
var app = express();
app.use(express.static("public"));
app.set("view engine", "ejs");
app.set("views", "./views");
var server = require("http").Server(app);
var io = require("socket.io")(server);
server.listen(3000);
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
var packet_number = 1;
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
var buf = Buffer.from([48, 0, 0]);

function timer(){
	if (mqtt_status == true && waitfor_reply == false) {
		buf[1] = packet_number >> 8 & 0xff;
		buf[2] = packet_number & 0xff;
		client.publish('data_request', buf);		
		storage_packet.topic_timeout = 'data_request';
		storage_packet.content_timeout = "0";
		timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
		waitfor_reply = true;		
		console.log("da gui " + packet_number);
		packet_number++;
	}
}
var realtime_buf = data_handler.realtime_buf;
var statistic_buf = data_handler.statistic_buf;

io.on('connection', function(socket){
	console.log("co nguoi connect");
	user_number++;
	io.sockets.emit("server_update_enable", server_update);
	socket.on("change_update_enable", function(data){
		server_update = !server_update;
		io.sockets.emit("server_update_enable", server_update);
		sec_value = 0;
	})

	socket.on("statistic_request", function(data){
		if(waitfor_reply == false){
			client.publish('data_request', "1"); 
			storage_packet.topic_timeout = 'data_request';
			storage_packet.content_timeout = "1";
			timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
			waitfor_reply = true;			
		}else{
			socket.emit("packet_ongoing");
			storage_packet.topic = "data_request";
			storage_packet.message = "1";
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
		//mqtt_status = true;
		console.log("mqtt broker connected");
		client.subscribe('realtime_data');
		client.subscribe('statistic_data');
		client.subscribe('control_status_data');
		client.subscribe('onoff_load_confirm');
		client.on('message', function(topic, message){

			if(topic == 'realtime_data') {
				connection_status_interval = 0;
				clearTimeout(timeout_latch);
				message.copy(realtime_buf, 0, 0, message.length);
				data_handler.realtime_send(io);	
				waitfor_reply = false;
				re_send(storage_packet);
			}

			if(topic == 'statistic_data') {
				connection_status_interval = 0;
				clearTimeout(timeout_latch);
				message.copy(statistic_buf, 0, 0, message.length);
				data_handler.statistic_send(io);
				waitfor_reply = false;
				re_send(storage_packet);
			}

			if(topic == 'control_status_data'){
				connection_status_interval = 0;
				clearTimeout(timeout_latch);
				data_handler.control_status_send(io, message);
				re_send(storage_packet);
			}

			if(topic == 'onoff_load_confirm'){
				clearTimeout(timeout_latch);
				if(message[0] == 256) io.sockets.emit("onoff_load_confirm", "1");
				else io.sockets.emit("onoff_load_confirm", "0");
				re_send(storage_packet);
			}
		})

		client.on('disconnect', function(){
			mqtt_status = false;
			console.log("mqtt disconnect");
		})
	})
})

function re_send(storage_packet){
	if(storage_packet.topic != "" && storage_packet.message != ""){
		timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
		waitfor_reply = true;
		client.publish(storage_packet.topic, storage_packet.message);
		storage_packet.topic = "";
		storage_packet.message = "";
	}	
}
function timeout_function(storage_packet){
	console.log("timeout");
	if(storage_packet.topic_timeout == "data_request") {		
		connection_status_interval++;
	}
	if(connection_status_interval > 5) {
		io.sockets.emit("error", "2")
	}

	io.sockets.emit("packet_lost");
	waitfor_reply = false
	re_send(storage_packet);
}

app.get("/", function(req, res){
	res.render("index1");
})