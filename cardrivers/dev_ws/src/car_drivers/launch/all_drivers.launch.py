from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='camera_driver',
            namespace='camera',
            executable='camera_driver',
            name='camera_driver'
        ),
        Node(
            package='wheels_driver',
            namespace='wheels',
            executable='wheels_driver',
            name='wheels_driver'
        )
    ])