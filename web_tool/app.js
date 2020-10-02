var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./src/routes/index');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'src/views/pages'));
app.set('view engine', 'ejs');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'src/models')));
app.use(express.static(path.join(__dirname, 'src/public')));
app.use(express.static(path.join(__dirname, 'src/controllers')));

app.use('/', indexRouter);

// app.use('/bucketlist',bucketlist);
app.use('/css', express.static(__dirname + '/node_modules/bootstrap/dist/css'));
app.use('/css', express.static(__dirname + '/node_modules/font-awesome/css'));
app.use('/css', express.static(__dirname + '/node_modules/ionicons/dist/css'));
app.use('/css', express.static(__dirname + '/node_modules/admin-lte/dist/css'));
app.use('/css', express.static(__dirname + '/node_modules/admin-lte/dist/css/skins'));
app.use('/css', express.static(__dirname + '/node_modules/angularjs-datepiker/dist'));

app.use('/js', express.static(__dirname + '/node_modules/jquery/dist'));
app.use('/js', express.static(__dirname + '/node_modules/bootstrap/dist/js'));
app.use('/js', express.static(__dirname + '/node_modules/admin-lte/dist/js'));
app.use('/js', express.static(__dirname + '/node_modules/angular'));
app.use('/js', express.static(__dirname + '/node_modules/python-shell'));
app.use('/js', express.static(__dirname + '/node_modules/chart.js/dist'));
app.use('/js', express.static(__dirname + '/node_modules/angular-chart.js/dist'));
app.use('/js', express.static(__dirname + '/node_modules/angularjs-datepiker/dist'));
app.use('/js', express.static(__dirname + '/node_modules/angularjs-datepiker/assets/js'));
app.use('/js', express.static(__dirname + '/node_modules/angularjs-datepiker/assets/js'));

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});


// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  console.log(err.message);
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('../errors/error');
});

module.exports = app;
