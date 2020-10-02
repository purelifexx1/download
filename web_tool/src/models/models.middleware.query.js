var models = {};
var MongoClient = require('mongodb').MongoClient;
var _URL_MONGODBSERVER = require('../public/js/api.collection')._URL_MONGODBSERVER;
var options = {
    useUnifiedTopology: true,
};

var findWithQuery = MongoClient.connect(_URL_MONGODBSERVER, options, function(err, db){
  if(err) throw err;
  var dbo = db.db("db_userManagement");
  var stdInfoQuery = {
      userId: userProfile.userId,
      email: userProfile.email,
  }

  var userTeamRolesQuery = {
      teamRoles:{
          admin: userProfile.teamRoles.admin,
          leader: userProfile.teamRoles.leader,
          labCoordinator: userProfile.teamRoles.labCoordinator,
      }
  }
  dbo.collection("col_userProfiles").find(stdInfoQuery).toArray(function(err, result){
      if(err) throw err;
      
      if(result == "" ){
          console.log("not available")
          checkIndex = checkIndex + 0;
      } else{
          console.log("available")
          checkIndex = checkIndex + 1;
      }
      console.log(checkIndex)
      db.close();
  })    
  
})

module.exports = models;

