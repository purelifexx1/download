var express = require("express");
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
var options = {
  port: 1883,
  clientId: 'x1999',
  username: "web_client",
  password: "01262755347",
};
var storage_packet = {
	"topic": "",
	"message": ""
};

var user_number = 0;
var latch = true;
var timer_latch;
var timeout_latch;
var mqtt_status = false;

var client = mqtt.connect('mqtt://node02.myqtthub.com', options);
function timer(){
	if (mqtt_status == true && waitfor_reply == false) {
		timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
		waitfor_reply = true;
		client.publish('data_request', "0");
	}
}
var realtime_buf = data_handler.realtime_buf;
var statistic_buf = data_handler.statistic_buf;
var real_time = data_handler.real_time;

io.on('connection', function(socket){
	user_number++;
	io.sockets.emit("ar", buf);
	socket.on("statistic_request", function(data){
		if(waitfor_reply == false){
			timeout_latch = setTimeout(timeout_function, 4000, storage_packet);
			waitfor_reply = true;
			client.publish('data_request', "1"); // dummy data, should transfer the id of requested client
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
			client.publish("data_request", 2);
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
		timer_latch = setInterval(timer, 10000);
	}
})

client.on('connect', function(){
	//mqtt_status = true;
	console.log("mqtt broker connected");
	client.subscribe('realtime_data');
	client.subscribe('statistic_data');
	client.subscribe('control_status_data');
	client.subscribe('onoff_load_confirm');
	client.on('message', function(topic, message){

	   if(topic == 'realtime_data') {
	   	clearTimeout(timeout_latch);
	   	message.copy(realtime_buf, 0, 0, message.length);
	   	data_handler.realtime_send(io);	
	   	waitfor_reply = false;
	   	re_send(storage_packet);
	   }

	   if(topic == 'statistic_data') {
	   	clearTimeout(timeout_latch);
	   	message.copy(statistic_buf, 0, 0, message.length);
	   	data_handler.statistic_send(io);
	   	waitfor_reply = false;
	   	re_send(storage_packet);
	   }

	   if(topic == 'control_status_data'){
	   	clearTimeout(timeout_latch);
	   	data_handler.control_status_send(io, message);
	   	re_send(storage_packet);
	   }

	   if(topic == 'onoff_load_confirm'){
	   	clearTimeout(timeout_latch);
	   	io.sockets.emit("onoff_load_confirm", message);
	   	re_send(storage_packet);
	   }


    })

    client.on('disconnect', function(){
    	mqtt_status = false;
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
	io.sockets.emit("packet_lost");
	waitfor_reply = false
	re_send(storage_packet);
}

app.get("/", function(req, res){
	res.render("index");
})