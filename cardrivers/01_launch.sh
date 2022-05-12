#!/bin/bash

docker run --privileged -it \
        -d \
        --name rttf-cardrivers-ros2 \
        --hostname rttf-cardrivers-ros2 \
        --network host \
        -v ~/rttf-car-ros2/cardrivers/dev_ws:/home/dev_ws \
        --env LD_LIBRARY_PATH=/opt/vc/lib \
        rttf-ros2 bash
