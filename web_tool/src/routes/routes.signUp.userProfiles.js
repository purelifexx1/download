var express = require('express');
var router = express.Router();
var _CONTROLLERS_CREATEUSERPROFILES = require('../controllers/controller.signUp.userProfiles').controllersCreateUserProfiles;
var _CONTROLLERS_GETALLUSERPROFILES = require('../controllers/controller.signUp.userProfiles').controllerGetAllUserProfiles;

router.post('/signUpSuccessful', _CONTROLLERS_CREATEUSERPROFILES);
router.get('/db_userManagement/col_userProfiles/findAll', _CONTROLLERS_GETALLUSERPROFILES)

module.exports = router;
