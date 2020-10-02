var models = {};
var MongoClient = require('mongodb').MongoClient;
var _URL_MONGODBSERVER = require('../public/js/api.collection')._URL_MONGODBSERVER;

var options = {
    useUnifiedTopology: true,
};
var Q = require('q');

function modelsGetAllUserProfiles()
{
    var deferred = Q.defer();
    try 
    {
        MongoClient.connect(_URL_MONGODBSERVER, options, function(err, db) {
            if (err) throw err;
            var dbo = db.db("db_userManagement");
            dbo.collection("col_userProfiles").find({}).toArray(function(err, result) {
                if (err) 
                {   
                    deferred.reject(err.name + ': ' + err.message);
                }                 
                if (result) 
                {            
                    deferred.resolve(result);
                } 
                else 
                {            
                    deferred.reject(MESSAGE_NOT_FOUND); 
                }

                db.close();
            });
        });
    } 
    catch (ex) 
    {
        deferred.reject(ex.message || ex);
    }    

    return deferred.promise;
}

function modelsCreateUserProfiles(req, callback){
    var username = req.body.username_signup;
    var userid = req.body.userid_signup;
    var password = req.body.userid_signup;
    var email = req.body.email_signup;
    var department = req.body.department_signup;
    var db_name = "db_"+userid.toLowerCase();
    // var _URL_MONGODBSEVER_USER = _URL_MONGODBSERVER + db_name;

    if(req.body.teamrole_signup == "admin"){
        var teamRoles = {
            "admin": true,
            "leader": false,
            "labCoordinator": false,
            "member": true
        };
    } else if(req.body.teamrole_signup == "leader"){
        var teamRoles = {
            "admin": false,
            "leader": true,
            "labCoordinator": false,
            "member": true
        };
    } else if(req.body.teamrole_signup == "labCoord"){
        var teamRoles = {
            "admin": false,
            "leader": false,
            "labCoordinator": true,
            "member": true
        };
    } else if(req.body.teamrole_signup == "member"){
        var teamRoles = {
            "admin": false,
            "leader": false,
            "labCoordinator": false,
            "member": true
        };
    }

    var userProfile = {
        "userName": username,
        "userId": userid.toLowerCase(),
        "passWord": password.toLowerCase(),
        "email": email.toLowerCase(),
        "department": department.toLowerCase(),
        "teamRoles": teamRoles
    }
    var stdInfoQuery = {
        userId: userProfile.userId,
        //email: userProfile.email,
    }

    
    modelsCheckUserProfile(stdInfoQuery, function(status){
        if(status == true){
            return callback(false) // dont create user profile
        } else {
            MongoClient.connect(_URL_MONGODBSERVER, options, function(err, db){
                if(err) throw err;
                var dbo = db.db("db_userManagement")
                dbo.collection("col_userProfiles").insertOne(userProfile, function(err, res) {
                    if (err) throw err;
                    db.close();
                });
            })
            return callback(true) // user profile create successfully
        }
    })
}

function modelsCheckUserProfile(stdInfoQuery, callback){
    MongoClient.connect(_URL_MONGODBSERVER, options, function(err, db){
        if(err) throw err;
        var dbo = db.db("db_userManagement")
        dbo.collection("col_userProfiles").find(stdInfoQuery).toArray(function(err, result, status){
            if(err) throw err;
            console.log(status);
            if(result != "") { // user profile is available in db
                status = true;
            } else { // user profile isn't available in db 
                status = false;
            }
            db.close();
            return callback(status)
        })
    })
}

module.exports = models;
models.modelsGetAllUserProfiles = modelsGetAllUserProfiles;
models.modelsCreateUserProfiles = modelsCreateUserProfiles;
models.modelsCheckUserProfile = modelsCheckUserProfile;