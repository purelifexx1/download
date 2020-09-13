var express = require("express");

var MongoClient = require('mongodb').MongoClient;
var options = {
    useUnifiedTopology: true,
    useNewUrlParser: true
};
var search = {title:"hello"};
MongoClient.connect('mongodb://localhost:27017/', options, function(err, db){
    var dbo = db.db('testDB');
    dbo.collection("testDB").find(search).toArray(function(error, result){
        console.log(result);
    });

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