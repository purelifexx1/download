var express = require("express");
var app = express();

app.get("/", function(req, res){
    res.send("hello world");
});
app.use(function(req, res, next){
    console.log(req);
    console.log(res);
})

app.listen(3000);