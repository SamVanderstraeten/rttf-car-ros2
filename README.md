# RTTF cardrivers (ROS2)

## cardrivers container

### Installation

0. Install 64-bit version of Raspberry Pi OS
1. Clone repo on RPi
2. ```cd rttf-car-ros2/cardrivers```
3. ```./00_build.sh```
4. ```./01_run.sh``` or ```docker start rttf-cardrivers-ros2``` (depending if it already exists)
5. ```./02_attach.sh```
6. ```./rebuild_ros.sh``` (just to be sure, should done automatically)
7. (optional) ```ros2 run wheels_driver wheels_driver``` or in the `/home/scripts` execute `./wheels_driver.sh` (listens for commands and executes commands on car)
8. (optional) ```ros2 run camera_driver camera_driver``` or in the `/home/scripts` execute `./camera_driver.sh` (starts publishing camera images)
9. (optional) ```ros2 run dummy_driver reckless_driver``` or in the `/home/scripts` execute `./dummy_driver.sh` (accelerates for 5 seconds & quits)

### Other 

There's a start for a 'launch all script'
```ros2 launch car_drivers all_drivers.launch.py```
Should work now, since camera driver was fixed. Not tested yet.

### Troubleshooting

```colcon build``` produces error related to the custom WheelCmd msg.
* Solution: ```rm -rf build/ install/ log/``` + ```colcon build```
* Should not happen anymore, above folders are no longer included in repo and must be built the first time



## dashboard container

### Setup

1. Run scripts 00, 01 and 02 to build, run and attach to the container.
2. Launch the rosbridge node ```ros2 launch rosbridge_server rosbridge_websocket_launch.xml```
3. Launch the Node.js app that serves the dashboard (very basic so far) ```cd /home/app``` and ```npm start```
4. Visit ```localhost:3000``` and watch it connect (console messages for now). Replace `localhost` with the proper IP address when connecting from other device in the same network.

### Remarks

The script on the website subscribes to the image topic of the car. (```/camera_node/image/compressed```) This was tested with the camera publishing from the ```cardrivers``` container.

### Bugs

Probably



## docker compose

Starts up everything at once.
