#!/usr/bin/python

import rclpy
import time
import math

# ============================================================================
# Adafruit PCA9685 16-Channel PWM Servo Driver
# ============================================================================

class PCA9685_Driver:
    def __init__(self, channel, address=0x40, frequency=60, busnum=None, init_delay=0.1):
        self.logger_name = "PCA9685"
        self.default_freq = 60
        self.pwm_scale= frequency / self.default_freq

        import Adafruit_PCA9685
        if busnum is not None:
            from Adafruit_GPIO import I2C
            def get_bus():
                return busnum
            
            I2C.get_default_bus = get_bus

        self.pwm = None
        try:
            self.pwm = Adafruit_PCA9685.PCA9685(address=address)
            self.pwm.set_pwm_freq(frequency)
        except:
            rclpy.logging.get_logger(self.logger_name).error('PWM connection failed!')

        self.channel = channel
        time.sleep(init_delay)

    def set_pulse(self, pulse):
        if not self.pwm == None:
            self.pwm.set_pwm(self.channel, 0, int(pulse * self.pwm_scale))
        else:
            rclpy.logging.get_logger(self.logger_name).warning('PWM pulse could not be set.')

    def run(self, pulse):
        self.set_pulse(pulse)
  