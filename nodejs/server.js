var express = require("express");
var app = express();
app.use(express.static("public"));
app.set("view engine", "ejs");
app.set("views", "./views");
var server = require("http").Server(app);
var io = require("socket.io")(server);
server.listen(3069);
var mqtt = require('mqtt');
var options = {
  port: 1883,
  clientId: 'x1999',
  username: "web_client",
  password: "01262755347",
};

var user_number = 0;
var latch = true;
var timer_latch;
var mqtt_status = false;

var client = mqtt.connect('mqtt://node02.myqtthub.com', options);
function timer(){
	if (mqtt_status == true) {
		client.publish('realtime_data_request', "3e68");
	}
}

io.on('connection', function(socket){
	user_number++;
	socket.on("statistic_request", function(data){
		client.publish('statistic_data_request', "3f69"); // dummy data, should transfer the id of requested client
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
	mqtt_status = true;
	console.log("mqtt broker connected");
	client.subscribe('realtime_data');
	client.subscribe('statistic_data');
	client.on('message', function(topic, message){

	   if(topic == 'realtime_data') {
	   	io.sockets.emit("realtime_data", message);	
	   }

	   if(topic == 'statistic_data') {
   		io.to(message).emit("statistic_data", message)
	   }
    })

    client.on('disconnect', function(){
    	mqtt_status = false;
    })
})

app.get("/", function(req, res){
	res.render("index");
})