import os

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter

#from edgecar_msgs.msg import WheelsCmdStamped, BoolStamped
from rttf_car_interfaces.msg import WheelsCmdStamped
from std_msgs.msg import Bool
#from wheels_driver.RcDriver import RcDriver
from adafruit_drivers.PCA9685 import PCA9685_Driver
from adafruit_drivers.PWMSteering import PWMSteering
from adafruit_drivers.PWMThrottle import PWMThrottle
#from std_msgs.msg import String

'''
    Wheels driver listens for wheel commands and passes them on to the physical components that control the wheels.
    Also listens to emergency stop and 'use_rad_limit' topic.
    Publishes executed commands on 'wheels_cmd_executed'.
'''


class WheelsDriverNode(Node):

    def __init__(self):
        super().__init__('wheels_driver', allow_undeclared_parameters=True, automatically_declare_parameters_from_overrides=True)

        self.node_name = 'wheels_driver_node'

        self.use_rad_lim        =   self.setupParam("~use_rad_lim", False, Parameter.Type.BOOL)
        self.min_rad            =   self.setupParam("~min_rad", 0.08, Parameter.Type.DOUBLE)
        self.wheel_distance     =   self.setupParam("~wheel_distance", 0.103, Parameter.Type.DOUBLE)

        self.steering_channel     =   self.setupParam('~steering_channel',1, Parameter.Type.INTEGER)
        self.steering_left_pwm    =   self.setupParam('~steering_left_pwm',460, Parameter.Type.INTEGER)
        self.steering_right_pwm   =   self.setupParam('~steering_right_pwm',290, Parameter.Type.INTEGER)

        self.throttle_channel       =   self.setupParam('~throttle_channel', 0, Parameter.Type.INTEGER)
        self.throttle_forward_pwm   =   self.setupParam('~throttle_forward_pwm',500, Parameter.Type.INTEGER)
        self.throttle_stopped_pwm   =   self.setupParam('~throttle_stopped_pwm',370, Parameter.Type.INTEGER)
        self.throttle_reverse_pwm   =   self.setupParam('~throttle_reverse_pwm', 220, Parameter.Type.INTEGER)
        
        self.PCA9685_I2C_ADDRESS =  self.setupParam("~PCA9685_I2C_ADDRESS", 0x40, Parameter.Type.INTEGER) # TODO CHECK IF TYPE IS OK
        self.PCA9685_I2C_BUSNUM =   os.environ.get('I2C_BUSNUM', 1)
        self.get_logger().info('Current busnum for I2C = {}'.format(self.PCA9685_I2C_BUSNUM))

        self.get_logger().info("Create steering controller")
        self.steering_controller = PCA9685_Driver(self.steering_channel, self.PCA9685_I2C_ADDRESS, busnum=self.PCA9685_I2C_BUSNUM)
        self.steering = PWMSteering(controller = self.steering_controller, 
                                                left_pulse=self.steering_left_pwm,
                                                right_pulse=self.steering_right_pwm)
        
        self.throttle_controller = PCA9685_Driver(self.throttle_channel, self.PCA9685_I2C_ADDRESS, busnum=self.PCA9685_I2C_BUSNUM)
        self.throttle = PWMThrottle(controller=self.throttle_controller,
                                                max_pulse=self.throttle_forward_pwm,
                                                zero_pulse=self.throttle_stopped_pwm,
                                                min_pulse=self.throttle_reverse_pwm)
        
        #add publisher for wheels command wih execution time
        self.msg_wheels_cmd = WheelsCmdStamped()
        self.pub_wheels_cmd = self.create_publisher(WheelsCmdStamped, "~/wheels_cmd_executed", 1)

        # Setup subscribers
        self.control_constant = 1.0
        # Done 
        self.sub_e_stop = self.create_subscription(Bool,"~/emergency_stop", self.cbEStop, 1)
        self.sub_e_stop = self.create_subscription(WheelsCmdStamped,"/wheels/wheels_driver/wheels_cmd", self.cbWheelsCmd, 1)
        self.sub_e_stop = self.create_subscription(Bool,"~/radius_limit", self.cbRadLimit, 1)

        self.estop = False

    def setupParam(self,param_name,default_value, param_type):
        value = self.get_parameter_or(param_name, default_value)
        param = Parameter(param_name, param_type, value)
        self.set_parameters([param])

        self.get_logger().info("SET PARAM [%s] %s = %s " %(self.node_name,param_name,value))
        return value

    def updateParams(self,event):
        self.get_logger().info("Update params [TODO]") # TODO

    def cbWheelsCmd(self,msg):
        if self.estop:
            self.throttle.set_speed(0)
            # self.driver.setWheelsSpeed(left=0.0,right=0.0)
            return

        self.get_logger().info('[wheels_driver_node] got wheels command %s' % (msg))
        
        # pass it on
        self.throttle.set_speed(msg.velocity)
        self.steering.set_angle(msg.rotation)

    def cbRadLimit(self, msg):
        param = Parameter("~use_rad_lim", Parameter.Type.BOOL, msg.data)
        self.set_parameters([param])
        self.use_rad_lim = msg.data

    def cbEStop(self,msg):
        self.get_logger().info('[wheels_driver_node] cbEstop =>  %s' % msg.data)
        self.estop=msg.data
        if self.estop:
            self.get_logger().info("[wheels_driver_node] Emergency Stop Activated")
        else:
            self.get_logger().info("[wheels_driver_node] Emergency Stop Released")

    def on_shutdown(self):
        self.driver.setWheelsSpeed(left=0.0,right=0.0)
        self.get_logger().info("[wheels_driver_node] Shutting down.")



def main(args=None):
    rclpy.init(args=args)

    wheel_driver = WheelsDriverNode()

    rclpy.spin(wheel_driver)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    wheel_driver.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
