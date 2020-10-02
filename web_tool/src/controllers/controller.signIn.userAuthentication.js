var controllers = {};
var _MODELS_FINDUSER = require ('../models/models.signIn.userAuthentication').modelsFindUser;
var _MODELS_FINDUSERNAME = require ('../models/models.signIn.userAuthentication').modelsGetUsername;

function controllerRedirect(req, res) {
    var userid_signin = req.body.userid_signin.toLowerCase();
    var teamrole_signin = req.body.teamrole_signin.toLowerCase();
    _MODELS_FINDUSER(req, res, function(status){
        if (status == true) { //userid available in database
            res.redirect('/signin/userid_signin=' + userid_signin + '&teamrole_signin=' + teamrole_signin);
        }else{//userid unavailable in database
            res.redirect('/signin');
        }
    });
      
}
function controllerFindUser(req, res) {
    _MODELS_FINDUSERNAME(req, function(name){
        res.render("pages-home", {username: name});
    })
    
}

module.exports = controllers;
controllers.controllerRedirect = controllerRedirect;
controllers.controllerFindUser = controllerFindUser;