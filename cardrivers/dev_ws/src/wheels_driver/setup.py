from setuptools import setup

package_name = 'wheels_driver'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name, "include/wheels_driver"],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Sam Vanderstraeten',
    maintainer_email='sam.vanderstraeten@pxl.be',
    description='Package that is used to control the wheel movement of the car',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'wheels_driver = wheels_driver.wheels_driver_node:main',
        ],
    }
)
