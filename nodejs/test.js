var ok = 45;
var jj = (ok >> 3) & 1;
var list = {
	"topic": "123",
	"message": "456"
};
list.forEach(function(value){
	console.log(value);
})
var buf = Buffer.from([254, 23]);
console.log(buf[0].toString());

