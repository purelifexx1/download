var MongoClient = require('mongodb').MongoClient;
var _URL_MONGODBSERVER = require('../public/js/api.collection')._URL_MONGODBSERVER;
var options = {
    useUnifiedTopology: true,
};
var userProfile = {
    userId: "nuc81hc",
    email: "cong.nguyenthanh2@vn.bosch.com",
    teamRoles: {
        "admin": true,
        "leader": false,
        "labCoordinator": false,
        "member": true
    }
}

var stdInfoQuery = {
    userId: userProfile.userId,
    email: userProfile.email,
}


function test(callback){
    MongoClient.connect(_URL_MONGODBSERVER, options, function(err, db){
        if(err) throw err;
        var dbo = db.db("db_userManagement")
        dbo.collection("col_userProfiles").find(stdInfoQuery).toArray(function(err, result, status){
            if(err) throw err;
            if(result != ""){
                status = true
            } else {
                status = false
            }
            db.close();
            return callback(status)
            
        })
    })
}


function sayHello(callback1) {
	var myName = {
        a:1,
        b:2
    }

    return callback1(myName);

}
 
var index = 0;
test(function(arg) {
    if(arg != ""){
        index = index + 1;
    } else{
        index = index + 2;
    }

    //console.log(index);
});

console.log(index)