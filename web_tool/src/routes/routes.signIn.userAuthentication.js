var express = require('express');
var router = express.Router();
var _CONTROLLERS_REDIRECT = require('../controllers/controller.signIn.userAuthentication').controllerRedirect;
var _CONTROLLERS_FINDUSER = require('../controllers/controller.signIn.userAuthentication').controllerFindUser;

router.post('/signInSuccessful', _CONTROLLERS_REDIRECT);
router.get('/signin/userid_signin=:userid_signin&teamrole_signin=:teamrole_signin',_CONTROLLERS_FINDUSER);

module.exports = router;