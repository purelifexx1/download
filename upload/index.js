var Struct = require('struct');
var person = Struct().word16Sle('one').word8('two');
person.allocate();
var buf = person.buffer();
var buf1 = Buffer.from([1, 0, 10]);
buf1.copy(buf, 0, 0, 3);
var proxy = person.fields;
console.log(proxy.one);