from setuptools import setup

package_name = 'dummy_driver'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='sam.vanderstraeten@pxl.be',
    description='Dummy script that sends default command to wheels, to check if it is alive.',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'reckless_driver = dummy_driver.reckless:main',
        ],
    },
)
