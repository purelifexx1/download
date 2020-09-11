var express = require("express");
var MongoClient = require('mongodb').MongoClient;
var options = {
    useUnifiedTopology: true,
};
MongoClient.connect('mongodb://localhost:27017/testdb', options, function(){
    console.log("connect");
})
var app = express();
console.log("ola");
app.use("/test" ,function(req, res, next){
    console.log("hello");
    next();
})
app.get("/", function(req, res){
    res.send("hello world");
});


app.listen(3000);