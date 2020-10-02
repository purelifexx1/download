var express = require('express');
var router = express.Router();

router.use(require('./routes.get.middleware'));
router.use(require('./routes.signUp.userProfiles'));
router.use(require('./routes.signIn.userAuthentication'));
module.exports = router;
