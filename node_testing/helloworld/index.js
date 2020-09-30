const express = require("express");
const path = require('path');
const app = express();

const posts = require("./server/routes/posts.js");

app.use(express.static(path.join(__dirname, 'dist')));
app.use('/posts', posts);

app.get('*', function(req, res){
    res.sendFile(path.join(__dirname, './dist//helloworld/index.html'));
})

const port = process.env.PORT || 4600;
app.listen(port, function(req, res){
    
});