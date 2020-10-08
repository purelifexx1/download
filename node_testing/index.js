var testing = {
    "hello": 123,
    "hello1": 456,
    "xin": 1234,
    "123":223
};
var buf = Buffer.from([12, 34,24]);
console.log(buf);
buf[0] = 25;
console.log(buf);