var Struct = require("struct");
var testing = Struct().word16Sle('world');
testing.allocate();
var buf = testing.buffer();
var union = testing.fields;
module.exports = {

	foo: function(){
		console.log("eeee");
	},
	ok: function(){
		console.log("ehiru");
	}
};

module.exports.union = union;
module.exports.buf = buf;