var firebase = require('firebase');
firebase.initializeApp({
    databaseURL: "https://data-59fcf.firebaseio.com"
});
var ref = firebase.database().ref('power_consume');
var express = require("express");
var app = express();
var server = require("http").createServer(app);
var io = require("socket.io").listen(server);
server.listen(process.env.PORT || 80);
var sum = 0;
var relay = true;
var archive = 0;
var pos, first, second;
var sub_hour, sub_minute, alarm_output;   


io.sockets.on("connection", function(socket){
     console.log("someone has connectted")
     socket.emit("plug_in_status", {"relay": relay});
     socket.on("socket_plugged", function(){
        relay = true;
        socket.broadcast.emit("relay_status", {"relay": relay});
     })
     socket.on("pressed", function(){
     	relay = !relay;
        console.log(relay);
     	socket.broadcast.emit("relay_status", {"relay": relay});
     })
     socket.on("confirm_pressed", function(){
        socket.broadcast.emit("relay_status", {"relay": relay});
     })
     socket.on("change_state", function(){
        relay = !relay;
        socket.broadcast.emit("relay_status", {"relay": relay});
     })
     socket.on("Data", function(data){
        let time = Date.now();
        var mydate = new Date(time);
        var month = ["January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"][mydate.getMonth()];
        var chuoi = "Date " + mydate.getDate();
        var sec_ref = ref.child(month);
        const string = JSON.stringify(data);
        const obj = JSON.parse(string);
        archive = obj.signal;
        console.log(archive);
        if (archive <= 75 && archive >= -45) {archive = 0.0};
        sec_ref.child(chuoi).once('value', function(snap){
            sum = archive + snap.val();
        })
        var day = "{" + JSON.stringify(chuoi) + ":" + sum + "}";
        var json = JSON.parse(day);
        sec_ref.update(json);
        
     })
     socket.on("cancel", function(){
        socket.broadcast.emit("abort");
     })
     socket.on("set_time", function(data){
        pos = data.indexOf("/");
        first = data.substring(0, pos);
        second = data.substring(pos + 1, data.length);
        pos = data.indexOf(":");
        sub_minute = parseInt(second.substring(pos + 1, second.length)) - parseInt(first.substring(pos + 1, first.length));
        sub_hour = parseInt(second.substring(0, pos)) - parseInt(first.substring(0, pos));
        if (sub_hour < 0 || (sub_hour == 0 && sub_minute < 0)) {
            sub_hour = 24 + sub_hour;
        }
        alarm_output = sub_hour*60 + sub_minute;
        console.log(alarm_output);
        socket.broadcast.emit("alarm", alarm_output);
     })


    
})

