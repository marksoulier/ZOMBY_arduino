# ZOMBY_arduino
This will be a repository of code to be used on the ZOMBY robotic project

The ZOMBY has 4 RoboClaw motor controllers, each connected to one of the 4 motors on the robot. We’re using an Arduino to control the robot. The motor controllers can support up to 2 motors each, which is why there are commands in the RoboClaw library for both “motor 1” and “motor 2”. We found through our testing that you need to use the “motor 1” command for each of the motors.

Here’s a link to the library GitHub Page:
https://github.com/basicmicro/roboclaw_arduino_library 

The motor controllers are currently set up for serial communication, so you need to use the “Rx” and “Tx” pins on the Arduino to communicate with them. We’re pretty sure you need to use a baud rate of 115200 because we were told that’s the baud rate of the motor controllers, and we tried a different baud rate and it didn’t work.

The addresses of each motor are the following, given in both hex and decimal:
Left front: 0x81 (129)
Right front: 0x82 (130)
Left rear: 0x83 (131)
Right rear: 0x84 (132)

Below is some code we used to test the ZOMBY and the RoboClaw library. We based it off of the SimplePWM example.

Zomby is able to run both with radio controller and by ros2

Zomby rasberrypi

username:Zomby
ip-address on robotics_lab_2.4 is: 192.168.1.4
password: usurobotics

to connect on seperate computer use the following command in the terminal:
ssh zomby@192.168.1.4

To run iniate ros2
run: ros2 run zomby_robot




