var express = require("express");
var firebase = require("firebase");
firebase.initializeApp({
	databaseURL: "https://data-59fcf.firebaseio.com"
});

var ref = firebase.database().ref('power_consume');
var sec_ref = ref.child("Octobor");
var day = "{" + JSON.stringify("Date 1") + ":" + 123 + "}";
var json = JSON.parse(day);
sec_ref.update(json);
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
var obj = {solar_voltage:23, bat_power:12};

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