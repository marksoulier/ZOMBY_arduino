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

We made "zomby_test" to test the ZOMBY and the RoboClaw library. We based it off of the SimplePWM example on the RoboClaw library github page.

We made "zomby_rc_test" to test controlling the ZOMBY with a radio transmitter.

For that, we used an arduino library called RC Receiver. It makes mapping RC receiver input quick and simple. There are two pieces of code that allow you to test your RC receiver input and map it to a usable value:
- RC_raw: prints raw input from RC receiver to serial monitor. 
- RC_mapped: allows you to set the max and min raw input of each channel so the library can correctly map it to a value from 0 to 100.
