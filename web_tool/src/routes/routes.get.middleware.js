var express = require('express');
var router = express.Router();


router.get('/', function(req, res, next)
{
    res.render('pages-index', { title: 'Start page' });
});

router.get('/signin', function(req, res, next)
{
    res.render('pages-signin', { title: 'Sign in'});
});

router.get('/signup', function(req, res, next)
{
    res.render('pages-signup', { title: 'Sign up' });
});

router.get('/home', function(req, res, next)
{
    res.render('pages-home', { title: 'Home page' });
});

router.get('/admin', function(req, res, next)
{
    console.log(req);
    res.render('pages-admin', { title: 'Home page' });
});
router.get('/teamMember', function(req, res, next)
{
    res.render('pages-teamMember', { title: 'Team member page' });
});
router.get('/projectPlan', function(req, res, next)
{
    res.render('pages-projectPlan', { title: 'Project Plan page' });
});
router.get('/leader', function(req, res, next)
{
    res.render('pages-leader', { title: 'Leader page' });
});
router.get('/standardTask', function(req, res, next)
{
    res.render('pages-standardTask', { title: 'Standard Task page' });
});
router.get('/competencyPlan', function(req, res, next)
{
    res.render('pages-competencyPlan', { title: 'Competency Plan page' });
});
router.get('/labBooking', function(req, res, next)
{
    res.render('pages-labBooking', { title: 'Lab Booking page' });
});
router.get('/labEquipment', function(req, res, next)
{
    res.render('pages-labEquipment', { title: 'Lab Equipment page' });
});
router.get('/internalTool', function(req, res, next)
{
    res.render('pages-internalTool', { title: 'Internal Tool page' });
});
router.get('/license', function(req, res, next)
{
    res.render('pages-license', { title: 'License page' });
});
module.exports = router;
