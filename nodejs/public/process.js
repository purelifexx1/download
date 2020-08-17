var socket = io("http://localhost:3000");
// var client = new Paho.MQTT.Client("node02.myqtthub.com",443,"x2000");
// var options = {
//   useSSL: true,
//   username: "web_client1",
//   password: "167943522",
//   onSuccess: onConnect
// };
// client.connect(options);
// function onConnect(){
// 	$("#input").val("da ket noi");
// }
socket.on("ar", function(data){
	$("#solar_voltage").val(data);
})
$(document).ready(function(){
	/*$("#send1").click(function(){
		// socket.emit("package", "hello");
		//$("#input").val("ok");
	})*/
});