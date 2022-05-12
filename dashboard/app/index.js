const http = require('http');
const fs = require('fs');
const path = require('path');
//const rclnodejs = require('rclnodejs');

const server = http.createServer((request, response) => {
  var filePath = '.' + request.url;
  if (filePath == './')
      filePath = 'index.html';

  var extname = path.extname(filePath);
  var contentType = 'text/html';
  switch (extname) {
      case '.js':
          contentType = 'text/javascript';
          break;
  }

  fs.readFile("public/"+filePath, function(error, content) {
    if (error) {
        if(error.code == 'ENOENT'){
            fs.readFile('./404.html', function(error, content) {
                response.writeHead(200, { 'Content-Type': contentType });
                response.end(content, 'utf-8');
            });
        }
        else {
            response.writeHead(500);
            response.end('Sorry, check with the site admin for error: '+error.code+' ..\n');
            response.end(); 
        }
    }
    else {
        response.writeHead(200, { 'Content-Type': contentType });
        response.end(content, 'utf-8');
    }
  });


  //res.writeHead(200, { 'content-type': 'text/html' });
  //fs.createReadStream('public/index.html').pipe(res);
})

server.listen(process.env.PORT || 3000)