var ros = new ROSLIB.Ros({
    url : 'ws://localhost:9090'
});
 
ros.on('connection', function() {
    console.log('Connected to websocket server.');
});
     
ros.on('error', function(error) {
    console.log('Error connecting to websocket server: ', error);
});
 
ros.on('close', function() {
    console.log('Connection to websocket server closed.');
});



var listener = new ROSLIB.Topic({
    ros : ros,
    name : '/camera_node/image/compressed',
    messageType : 'sensor_msgs/Image'
});
 
listener.subscribe(function(message) {
    console.log('Received message on ' + listener.name + ': ' + message.data);
    listener.unsubscribe();
});