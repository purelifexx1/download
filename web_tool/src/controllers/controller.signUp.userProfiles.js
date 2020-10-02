var controllers = {};
var _MODELS_CREATEUSERPROFILES = require('../models/models.signUp.userProfiles').modelsCreateUserProfiles;
var _MODELS_GETALLUSERPROFILES = require('../models/models.signUp.userProfiles').modelsGetAllUserProfiles;

function controllersCreateUserProfiles(req, res, callback){
	//document.getElementById("checkUserProfile").innerHTML = "abc";
	_MODELS_CREATEUSERPROFILES(req, function(status){
		if(status == true){
			console.log("not available")
			res.render('pages-signUpSuccessful', { title: 'Sign up successful'});
		} else {
			console.log(" available")
			res.render('pages-signup')
		}	
		
	})	

}

function controllerGetAllUserProfiles(req, res){
    _MODELS_GETALLUSERPROFILES().then(function(classes)
		{
			res.json({col_userProfiles:classes});		
		}).catch(function(error)
			{
				res.json({error: error.message || error});
				console.log(error);
			});
}

function controllerCheckUserProfile(){

	_MODELS_CREATEUSERPROFILES(req, function(status){
		if(status == false ){
			console.log("userid is available 1")
		} else {
			console.log("userid isn't available 1")
		}
	})
	
}
module.exports = controllers;
controllers.controllersCreateUserProfiles = controllersCreateUserProfiles;
controllers.controllerGetAllUserProfiles = controllerGetAllUserProfiles;
controllers.controllerCheckUserProfile = controllerCheckUserProfile;

