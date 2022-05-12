#!/bin/bash

docker run --privileged -it \
        -d \
        --name rttf-dashboard \
        --hostname rttf-dashboard \
        --network host \
        rttf-dashboard bash
