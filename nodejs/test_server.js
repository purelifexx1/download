var express = require("express");
var app = express();
app.use(express.static("public"));
app.set("view engine", "ejs");
app.set("views", "./views");
var server = require("http").Server(app);
var io = require("socket.io")(server);
server.listen(3069);
var buf = Buffer.from([23, 234, 51]);
var obj = {name:buf};
io.on('connection', function(socket){
	console.log("co nguoi connect");
	io.sockets.emit("ar", obj);
	socket.on("hello", function(data){
		console.log("da nhan");
	})
})


app.get("/", function(req, res){
	res.render("index");
})