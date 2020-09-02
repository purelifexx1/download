var express = require("express");
var firebase = require("firebase");
firebase.initializeApp({
	databaseURL: "https://data-59fcf.firebaseio.com"
});
var main_branch = firebase.database().ref("power_consume");
var ss = require("struct");
var mang = ss().word16Sbe("mot").word16Sbe("hai");
mang.allocate();
var mang1 = mang.buffer();
var mang2 = mang.fields;

var temp_buf = Buffer.from([23, 34]);
temp_buf.copy(mang1, 0, 0, 4);

var app = express();
app.use(express.static("public"));
app.set("view engine", "ejs");
app.set("views", "./views");
var server = require("http").Server(app);
var io = require("socket.io")(server);
server.listen(3069);
var buf = Buffer.from([23, 234, 51]);

var te = 0;
var obj = {"Date 13": 2.96};
var testt = main_branch.child("October");
var day = "{" + JSON.stringify("Date 13") + ":" + 12.96 + "}";
var json = JSON.parse(day);
testt.update(obj);

io.on('connection', function(socket){
	console.log("co nguoi connect");
	io.sockets.emit("ar");
	socket.on("hello", function(data){
		console.log("da nhan");
	})
})


app.get("/", function(req, res){
	res.render("index");
})