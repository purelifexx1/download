var models = {};
var _URL_MONGODBSERVER = require('../public/js/api.collection')._URL_MONGODBSERVER;
var MongoClient = require('mongodb').MongoClient;
var options = {
  useUnifiedTopology: true,
};

function modelsFindUser(req, res, callback) {
  var userid_signin = req.body.userid_signin;
  var teamrole_signin = req.body.teamrole_signin;
  var id_checking = {userId: userid_signin};
  MongoClient.connect(_URL_MONGODBSERVER, options, function(err, db) {
      if (err) throw err;
      var dbo = db.db("db_userManagement");
      dbo.collection("col_userProfiles").find(id_checking).toArray(function(err, result) {
        if (err) throw err;
        if(result != "") {
          console.log("return true");
          return callback(true);
        }else{
          return callback(false);
        }
        db.close();
      });
  });
}

function ModelsGetUsername(req, callback) {
  var userid_signin = req.params.userid_signin;
  console.log(userid_signin);
  var id_checking = {userId: userid_signin};
  MongoClient.connect(_URL_MONGODBSERVER, options, function(err, db) {
      if (err) throw err;
      var dbo = db.db("db_userManagement");
      dbo.collection("col_userProfiles").find(id_checking).toArray(function(err, result) {
        if (err) throw err;
        if(result != "") {     
          console.log("return true");   
          return callback(result[0].userName);
        }else{
          return callback("");
        }
        db.close();
      });
  });
}

module.exports = models;
models.modelsFindUser = modelsFindUser; 
models.modelsGetUsername = ModelsGetUsername;
