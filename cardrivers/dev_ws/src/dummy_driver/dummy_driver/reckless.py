import rclpy
from rclpy.node import Node

import time
from rttf_car_interfaces.msg import WheelsCmdStamped

class RecklessDriverNode(Node):
    def __init__(self):
        super().__init__('reckless_dummy_driver', allow_undeclared_parameters=True, automatically_declare_parameters_from_overrides=True)

        self.node_name = 'reckless_dummy_driver'
        
        self.get_logger().info("[%s] Initializing..." %(self.node_name))

        self.msg_wheels_cmd = WheelsCmdStamped()
        self.pub_wheels_cmd = self.create_publisher(WheelsCmdStamped, "/wheels/wheels_driver/wheels_cmd", 1)

        self.get_logger().info("[%s] Sending dummy messages..." %(self.node_name))

        i = 20
        while True:
            self.sendWheelMsg()
            time.sleep(0.5)
            i-=1
    
    def sendWheelMsg(self):
        self.msg_wheels_cmd.velocity = 0.2
        self.msg_wheels_cmd.rotation = 0.1

        self.pub_wheels_cmd.publish(self.msg_wheels_cmd)

def main(args=None):
    rclpy.init(args=args)

    driver = RecklessDriverNode()

    rclpy.spin(driver)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    driver.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()