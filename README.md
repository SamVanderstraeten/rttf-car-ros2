# RTTF cardrivers (ROS2)

## Installation

1. Clone repo on RPi
2. ```cd rttf-car-ros2/cardrivers```
3. ```./00_build.sh```
4. ```./01_run.sh``` or ```docker start rttf-cardrivers-ros2``` (depending if it already exists)

5. ```./02_attach.sh```
6. ```./rebuild_ros.sh``` (just to be sure, should done automatically)
7. ```ros2 run wheels_driver wheels_driver``` (listens for commands and executes commands on car)
8. ```ros2 run dummy_driver reckless_driver``` (accelerates for 5 seconds & quits)

## Troubleshooting

```colcon build``` produces error related to the custom WheelCmd msg.
* Solution: ```rm -rf build/ install/ log/``` + ```colcon build```
