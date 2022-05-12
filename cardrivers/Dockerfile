FROM ros:foxy-ros-base

# TODO enable when done
#RUN mkdir -p /home/dev_ws/src
RUN mkdir -p /home/scripts

RUN apt-get update && apt-get install -y \
        nano \
        ros-foxy-rqt-image-view \
        ros-foxy-compressed-image-transport \
        python3-pip \
        python3-smbus \
        libffi-dev \
        libssl-dev \
        python3-opencv 
#       qt5-default

ENV READTHEDOCS=True
COPY pip_requirements.txt /pip_requirements.txt

RUN pip install --upgrade pip
RUN pip install -r /pip_requirements.txt

# Reference script with commands to source workspace
#GONE COPY ./source_ros.sh /home/dev_ws/source_ros.sh
COPY ./run_all_drivers.sh /home/scripts/run_all_drivers.sh
RUN chmod +x /home/scripts/run_all_drivers.sh

# Change to workspace on sign in
RUN echo "cd /home/dev_ws" >> ~/.bashrc

# Build the workspace
#RUN cd /home/dev_ws && . /opt/ros/foxy/setup.sh && colcon build

# Source the workspace on sign in
RUN echo "export ROS_IPV6=off" >> ~/.bashrc
RUN echo "source /opt/ros/foxy/setup.bash" >> ~/.bashrc
RUN echo ". install/local_setup.bash" >> ~/.bashrc

CMD [ "./home/scripts/run_all_drivers.sh" ]