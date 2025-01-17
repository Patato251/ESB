/*
 *  @author 
 *  Patrick Le 
 *  
 *  @description
 * 
 *  @date
 *  27/04/20
 */

var exec = require("child_process").exec; 

function start(response) {
  console.log("Request handler 'start' was called.");

  var content = "empty";

  exec("ls -lah", { timeout: 10000, maxbuffer: 2000*1024}, 
    function (error, stdout, stderr) {
      response.writeHead(200, {"Content-Type": "text/plain"});
      response.write(stdout);
      response.end();
  });
}

function upload(response) {
    console.log("Request handler 'upload' was called.");
    response.writeHead(200, {"Content-Type": "text/plain"});
    response.write("Hello Upload");
    response.end();
}

exports.start = start;
exports.upload = upload;