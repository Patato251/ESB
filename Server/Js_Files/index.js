/*
 *  @author 
 *  Patrick Le 
 *  
 *  @description
 *  
 * 
 *  @date
 *  27/04/20
 */
var server = require("./server"); // Import the server file located in the same directory
var router = require("./router"); // Import the route file located in the same directory
var requestHandlers = require("./requestHandlers"); // Import the requestHandlers file located in the same directory

// Associative array equivalent to allow for each corresponding request to be answered with a response 
var handle = {};

/* Object in Javascript is associated with a pairing of strings and numbers and functions
 * therefore allowing us to have methods within an object similarly to other OOP languages
 */  
handle["/"] = requestHandlers.start;
handle["/start"] = requestHandlers.start;
handle["/upload"] = requestHandlers.upload;

server.start(router.route, handle); // Calling server start