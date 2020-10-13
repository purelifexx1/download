const { connect } = require("mongoose");

var testing = {
    "hello": {
        "fun":1,
        "two":2
    },
    "hello1": 456,
    "xin": 1234,
    123:223
};
var tt = testing["222"];
if(tt == undefined) console.log("eee")