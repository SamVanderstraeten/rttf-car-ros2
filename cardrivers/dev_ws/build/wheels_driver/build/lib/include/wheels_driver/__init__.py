from .PCA9685 import PCA9685_Driver

class RcDriver(object):
	def __init__(self, addr = 0x60, freq = 1600):
		# default addr on HAT
		self._i2caddr = addr
		# default @1600Hz PWM freq
		self._frequency = freq
		# self.motors = [ Adafruit_DCMotor(self, m) for m in range(4) ]
    	# self.steppers = [ Adafruit_StepperMotor(self, 1), Adafruit_StepperMotor(self, 2) ]
		self._pwm =  PWM(addr, debug=False)
		self._pwm.setPWMFreq(self._frequency)