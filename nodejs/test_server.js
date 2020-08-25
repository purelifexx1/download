var express = require("express");
var ss = require("struct");
var mang = ss().word16Sbe("mot").word16Sbe("hai");
mang.allocate();
var mang1 = mang.buffer();
var mang2 = mang.fields;

var temp_buf = Buffer.from([23, 34, 34, 33]);
temp_buf.copy(mang1, 0, 0, 4);

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
	io.sockets.emit("ar", mang2);
	socket.on("hello", function(data){
		console.log("da nhan");
	})
})


app.get("/", function(req, res){
	res.render("index");
})