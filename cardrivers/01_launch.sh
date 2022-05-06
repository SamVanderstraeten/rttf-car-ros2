#!/bin/bash

xhost +local:docker
sudo xhost +
export DISPLAY=:0.0
docker run --privileged -it \
        -d \
        --name rttf-cardrivers-ros2 \
        --hostname rttf-cardrivers-ros2 \
        --network host \
        -v ~/projects/rttf-ros2/cardrivers/dev_ws:/home/dev_ws \
        -v /tmp/.X11-unix:/tmp/.X11-unix \
        --env LD_LIBRARY_PATH=/opt/vc/lib
        -e "DISPLAY=$DISPLAY" \
        --device=/dev/dri:/dev/dri \
        rttf-ros2 bash
