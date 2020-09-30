const express = require('express');
const router = express.Router();
const axios = require('axios');
const postapi = 'https://jsonplaceholder.typicode.com';
router.get('/', function(req, res){
    axios.get('${postapi}/posts').then(posts=>{
        console.log(posts.data);
    })
});

module.exports = router;