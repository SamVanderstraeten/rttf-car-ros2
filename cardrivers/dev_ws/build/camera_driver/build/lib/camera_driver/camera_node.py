#!/usr/bin/env python
import io
import _thread
import os
import yaml
import rclpy
 
#from edgecar_msgs.msg import BoolStamped
#from duckietown_msgs.msg import BoolStamped
#from duckietown_utils import get_duckiefleet_root
from time import sleep
from picamera import PiCamera
from picamera.array import PiRGBArray
from sensor_msgs.msg import CompressedImage
from sensor_msgs.srv import SetCameraInfo, SetCameraInfoResponse
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

        self.image_msg = CompressedImage()

        # Setup PiCamera

        self.camera = PiCamera()
        self.framerate = self.framerate_high  # default to high
        self.camera.framerate = self.framerate
        self.camera.resolution = (self.res_w, self.res_h)

        cam_config_root='/data/config'
        self.cali_file_folder = cam_config_root + "/calibrations/camera_intrinsic/"

        self.frame_id = rospy.get_namespace().strip('/') + "/camera_optical_frame"

        self.has_published = False

        self.pub_img = self.create_publisher(CompressedImage, "~image/compressed", 1)
        self.sub_switch_high = self.create_subscription(BoolStamped,"~framerate_high_switch", self.cbSwitchHigh, 1)

        # Create service (for camera_calibration)
        self.srv = self.create_service(SetCameraInfo, "~set_camera_info", self.cbSrvSetCameraInfo)

        self.stream = io.BytesIO()

        #self.camera.exposure_mode = 'off'
        # self.camera.awb_mode = 'off'

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
        self.get_logger().info("[%s] Start capturing" % (self.node_name))
        while not self.is_shutdown and rclpy.ok():
            gen = self.grabAndPublish(self.stream, self.pub_img)
            try:
                self.camera.capture_sequence(gen, 'jpeg', use_video_port=True, splitter_port=0)
            except StopIteration:
                pass
            # print "updating framerate"
            self.camera.framerate = self.framerate
            self.update_framerate = False

        self.camera.close()
        self.get_logger().info("[%s] Capture Ended." % (self.node_name))

    def grabAndPublish(self, stream, publisher):
        while not self.update_framerate and not self.is_shutdown and rclpy.ok():
            yield stream
            # Construct image_msg
            # Grab image from stream
            #stamp = rospy.Time.now()
            stamp = self.get_clock().now()
            stream.seek(0)
            stream_data = stream.getvalue()
            # Generate compressed image
            image_msg = CompressedImage()
            image_msg.format = "jpeg"
            image_msg.data = stream_data

            image_msg.header.stamp = stamp
            image_msg.header.frame_id = self.frame_id
            publisher.publish(image_msg)

            # Clear stream
            stream.seek(0)
            stream.truncate()

            if not self.has_published:
                self.get_logger().info("[%s] Published the first image." % (self.node_name))
                self.has_published = True

            #rospy.sleep(rospy.Duration.from_sec(0.001))
            sleep(0.001)

    def setupParam(self, param_name, default_value, param_type):
        value = self.get_parameter_or(param_name, default_value)
        param = Parameter(param_name, param_type, value)
        self.set_parameters([param])

        self.get_logger().info("SET PARAM [%s] %s = %s " %(self.node_name,param_name,value))
        return value

    def onShutdown(self):
        self.get_logger().info("[%s] Closing camera." % (self.node_name))
        self.is_shutdown = True
        self.get_logger().info("[%s] Shutdown." % (self.node_name))

    def cbSrvSetCameraInfo(self, req):
        # TODO: save req.camera_info to yaml file
        self.get_logger().info("[cbSrvSetCameraInfo] Callback!")
        filename = self.cali_file_folder + rospy.get_namespace().strip("/") + ".yaml"
        response = SetCameraInfoResponse()
        response.success = self.saveCameraInfo(req.camera_info, filename)
        response.status_message = "Write to %s" % filename  #TODO file name
        return response

    def saveCameraInfo(self, camera_info_msg, filename):
        # Convert camera_info_msg and save to a yaml file
        self.get_logger().info("[saveCameraInfo] filename: %s" % (filename))

        # Converted from camera_info_manager.py
        calib = {'image_width': camera_info_msg.width,
        'image_height': camera_info_msg.height,
        'camera_name': rospy.get_name().strip("/"),  #TODO check this
        'distortion_model': camera_info_msg.distortion_model,
        'distortion_coefficients': {'data': camera_info_msg.D, 'rows':1, 'cols':5},
        'camera_matrix': {'data': camera_info_msg.K, 'rows':3, 'cols':3},
        'rectification_matrix': {'data': camera_info_msg.R, 'rows':3, 'cols':3},
        'projection_matrix': {'data': camera_info_msg.P, 'rows':3, 'cols':4}}

        self.get_logger().info("[saveCameraInfo] calib %s" % (calib))

        try:
            f = open(filename, 'w')
            yaml.safe_dump(calib, f)
            return True
        except IOError:
            return False


if __name__ == '__main__':
    rclpy.init(args=args)

    camera_node = CameraNode()

    thread.start_new_thread(camera_node.startCapturing, ())
    rclpy.spin(camera_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    camera_node.destroy_node()
    rclpy.shutdown()