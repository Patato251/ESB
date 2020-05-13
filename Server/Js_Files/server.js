/*!
 *  @author 
 *  Patrick Le 
 *  
 *  @description
 *  The file allows for routing of the url and to determine GET/POST requests as well as to other URL's
 * 
 *  @date
 *  27/04/20
 */
var http = require("http");
var url = require("url");

function start(route, handle) {
    function onRequest(request, response) {
      var pathname = url.parse(request.url).pathname; // Determine pathname allocation
      console.log("Request for " + pathname + " received"); // Confirms pathname for routing
    
      route(handle, pathname, response); // Routing pathname obtained via request url
    }


    http.createServer(onRequest).listen(8888);
    console.log("Server has started");
}

exports.start = start;