FROM ros:foxy-ros-base


RUN mkdir /home/app

RUN apt-get update && apt-get install -y \
        nano \
        curl \
        ros-foxy-rqt-image-view \
        ros-foxy-compressed-image-transport \
        python3-pip \
        ros-foxy-rosbridge-server \
        ros-foxy-rosbridge-suite

# https://wiki.ros.org/rosbridge_suite
# https://github.com/RobotWebTools/roslibjs

RUN curl -s https://deb.nodesource.com/setup_16.x | sudo bash

RUN apt-get install nodejs

RUN curl -L https://npmjs.org/install.sh | sudo sh 

RUN echo "export ROS_IPV6=off" >> ~/.bashrc
RUN echo "source /opt/ros/foxy/setup.bash" >> ~/.bashrc
RUN echo ". install/local_setup.bash" >> ~/.bashrc

COPY ./app /home/app/

RUN cd /home/app

WORKDIR /home/app
RUN rm -rf node_modules
RUN /bin/bash -c "source \"/opt/ros/$ROS_DISTRO/setup.bash\" && npm install"

# CMD [ "npm start" ]