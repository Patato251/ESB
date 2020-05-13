/*
 *  @author 
 *  Patrick Le 
 *  
 *  @description
 * 
 *  @date
 *  27/04/20
 */
function start() {
    console.log("Request handler 'start' was called.");
}

function upload() {
    console.log("Request handler 'upload' was called.");
}

exports.start = start;
exports.upload = upload;