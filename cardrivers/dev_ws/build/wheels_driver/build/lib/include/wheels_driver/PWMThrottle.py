import time
import rclpy


class PWMThrottle:
    MIN_THROTTLE = -1.0
    MAX_THROTTLE = 1.0

    def __init__(self, controller=None, max_pulse=300.0, min_pulse=490.0, zero_pulse=350.0):
        self.controller = controller
        self.max_pulse = max_pulse
        self.min_pulse = min_pulse
        self.zero_pulse = zero_pulse

        rclpy.get_logger().info("INIT ESC")
        self.controller.set_pulse(self.max_pulse)
        time.sleep(0.01)
        self.controller.set_pulse(self.min_pulse)
        time.sleep(0.01)
        self.controller.set_pulse(self.zero_pulse)
        time.sleep(1)
        rclpy.get_logger().info('FINISHED INIT ESC')

    def map_range(self, x, x_MIN, x_MAX, y_MIN, y_MAX):
        x_range = x_MAX - x_MIN
        y_range = y_MAX - y_MIN
        xy_ratio = x_range * 1.0 / y_range * 1.0
        # [] 0.0 -1 0 220 370 1 150 0

        y = ((x - x_MIN) / xy_ratio + y_MIN) // 1

        return int(y)

    def set_speed(self, throttle):
        if throttle > 0:
            pulse = self.map_range(throttle, 0.0, self.MAX_THROTTLE, self.zero_pulse, self.max_pulse)
        else:
            pulse = self.map_range(throttle, self.MIN_THROTTLE, 0.0, self.min_pulse, self.zero_pulse)

        rclpy.get_logger().info('[PWM Throttle] Set speed pulse to %s' % pulse)
        self.controller.set_pulse(pulse)

    def shutdown(self):
        self.set_speed(0)
