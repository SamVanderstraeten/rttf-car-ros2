#!/usr/bin/env python
import io
import _thread
import os
import yaml
import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter

import cv2
from cv_bridge import CvBridge
 
from time import sleep
from sensor_msgs.msg import CompressedImage
from sensor_msgs.srv import SetCameraInfo
from std_msgs.msg import Bool
from sensor_msgs.msg import Image
from rclpy.utilities import ok


class CameraNode(Node):

    def __init__(self):
        super().__init__('camera_node')

        self.node_name = 'camera_node'
        self.get_logger().info("[%s] Initializing......" % (self.node_name))

        self.framerate_high = self.setupParam("~framerate_high", 30.0, Parameter.Type.DOUBLE)
        self.framerate_low = self.setupParam("~framerate_low", 15.0, Parameter.Type.DOUBLE)
        self.res_w = self.setupParam("~res_w", 640,Parameter.Type.INTEGER)
        self.res_h = self.setupParam("~res_h", 480, Parameter.Type.INTEGER)

        # initialize camera
        self.cap = cv2.VideoCapture('/dev/video0', cv2.CAP_V4L)
        self.br = CvBridge()

        # set dimensions
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.res_w)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.res_h)

        self.has_published = False

        self.pub_img = self.create_publisher(CompressedImage, "~/image/compressed", 1)

        self.is_shutdown = False
        self.update_framerate = False
        # Setup timer
        self.get_logger().info("[%s] Initialized." % (self.node_name))

    def cbSwitchHigh(self, switch_msg):
        self.get_logger().info("[%s] Switching framerate" % (self.node_name))
        if switch_msg.data and self.framerate != self.framerate_high:
            self.framerate = self.framerate_high
            self.update_framerate = True
        elif not switch_msg.data and self.framerate != self.framerate_low:
            self.framerate = self.framerate_low
            self.update_framerate = True

    def startCapturing(self):
        self.get_logger().info("[%s] Start publishing frames." % (self.node_name))
        while not self.is_shutdown and rclpy.ok():
            self.grabAndPublish()

        self.camera.close()
        self.get_logger().info("[%s] Stopped publishing." % (self.node_name))

    def grabAndPublish(self):
        while not self.is_shutdown and rclpy.ok():
            ret, frame = self.cap.read()
            if ret:
                tr = self.br.cv2_to_compressed_imgmsg(frame)
                self.pub_img.publish(tr)
            else:
                self.get_logger().info("[%s] Error capturing frame." % (self.node_name))
  
            if not self.has_published:
                self.get_logger().info("[%s] Published the first image." % (self.node_name))
                self.has_published = True
            sleep(0.001)

    def setupParam(self, param_name, default_value, param_type):
        value = self.get_parameter_or(param_name, default_value)
        param = Parameter(param_name, param_type, value)
        try:
            self.declare_parameter(param_name)
            self.set_parameters([param])
        except e:
            self.get_logger().warning("[%s] Failed setting parameter %s" % (self.node_name, param_name))

        self.get_logger().info("SET PARAM [%s] %s = %s " %(self.node_name,param_name,value))
        return value

    def onShutdown(self):
        self.get_logger().info("[%s] Closing camera." % (self.node_name))
        self.is_shutdown = True
        self.get_logger().info("[%s] Shutdown." % (self.node_name))

def main(args=None):
    rclpy.init(args=args)

    camera_node = CameraNode()

    _thread.start_new_thread(camera_node.startCapturing, ())
    rclpy.spin(camera_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    camera_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
