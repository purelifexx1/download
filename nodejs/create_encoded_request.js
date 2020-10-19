

function create_request(request_reference, callback){
    var buffer = [Object.keys(request_reference).length];
    Object.entries(request_reference).forEach(function(element){
        switch(element[1].function_code){
            case 4:
                buffer = buffer.concat(fc_04_request(element[1]));
            break;
            case 1:
                buffer = buffer.concat(fc_01_request(element[1]));
            break;
            case 5:
                buffer = buffer.concat(fc_05_request(element[1]));
            break;
        }
    })
    callback(Buffer.from(buffer));
}
function fc_04_request(data){
    var start_register_value = parseInt(data.start_address, 16);
    var array = [];
    array[0] = 4;
    array[1] = data.function_code;
    array[2] = start_register_value >> 8 & 0xff;
    array[3] = start_register_value & 0xff;
    array[4] = data.number_of_register;
    return array;
}
function fc_01_request(data){
    var start_register_value = parseInt(data.start_address, 16);
    var array = [];
    array[0] = 4;
    array[1] = data.function_code;
    array[2] = start_register_value >> 8 & 0xff;
    array[3] = start_register_value & 0xff;
    array[4] = data.number_of_coils;
    return array;
}
function  fc_05_request(data) {
    var start_register_value = parseInt(data.start_address, 16);
    var array = [];
    array[0] = 4;
    array[1] = data.function_code;
    array[2] = start_register_value >> 8 & 0xff;
    array[3] = start_register_value & 0xff;
    array[4] = data.status & 0xff; // 255 or 0
    return array;
}

module.exports.create_request = create_request;