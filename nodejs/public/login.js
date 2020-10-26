var socket = io("http://localhost:3000");


$(document).ready(function(){
    $("@submit").click(function(){
        socket.emit("login", {
            "user": document.getElementById("username").textContent,
            "pwd": document.getElementById("pwd").textContent
        });
    })
})