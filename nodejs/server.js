var express = require("express");
var app = express();
app.use(express.static("public"));
app.set("view engine", "ejs");
app.set("views", "./views");
var server = require("http").Server(app);
var io = require("socket.io")(server);
server.listen(3000);
var mqtt = require('mqtt');
var user_number = 0;
var latch = true;
var options = {
  port: 1883,
  clientId: 'x1999',
  username: "web_client",
  password: "01262755347",
};
var timer_latch;

function timer(){
	io.sockets.emit("ar", counter);
}
var client = mqtt.connect('mqtt://node02.myqtthub.com', options);
var current;
io.on('connection', function(socket){
	user_number++;
	socket.on("package", function(data){
		console.log(data);
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
		timer_latch = setInterval(timer, 1000);
	}
})
io.on('disconnect', function(socket){
	console.log("disconnect");
})
client.on('connect', function(){
	console.log("mqtt broker connected");
	client.subscribe('another');
	client.on('message', function(topic, message){
	   if(topic == 'another') {
	   	io.to(current).emit('ar', message.toString());
	   }
    })
})

app.get("/", function(req, res){
	res.render("index");
})