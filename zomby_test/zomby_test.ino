// Includes required to use Roboclaw library
#include <SoftwareSerial.h>
#include "RoboClaw.h"

// See limitations of Arduino SoftwareSerial
// Rx pin: 0
// TX pin: 1
SoftwareSerial serial(0,1);	
RoboClaw roboclaw(&serial,10000);

// Addresses (in hexadecimal) of each of the 4 motor controllers
#define left_front 0x81
#define right_front 0x82
#define left_rear 0x83
#define right_rear 0x84

void setup() {
  // Open roboclaw serial ports
  // This is the baud rate of the motor controllers, so it must be used
  roboclaw.begin(115200);
}

/******************************************************************************
NOIE: To run a motor forward at a certain speed, use the following command:

roboclaw.ForwardM1(address of motor, speed from 0 to 127);

To run it backwards, use this command:

roboclaw.BackwardM1(address of motor, speed from 0 to 127);

Once the speed has been set, the motor will continue at that speed until it
receives another command.
******************************************************************************/

void loop() {

  int i;

  // Accelerate all motors to almost full speed over the course of 6 seconds
  for (i = 0; i < 120; i+=1)
  {
    roboclaw.ForwardM1(left_front, i);
    roboclaw.ForwardM1(right_front, i);
    roboclaw.ForwardM1(left_rear, i);
    roboclaw.ForwardM1(right_rear, i);
    delay(50);
  }

  // Decelerate all motors to a stop over the course of 6 seconds
  for (i = 120; i > 0; i-=1)
  {
    roboclaw.ForwardM1(left_front, i);
    roboclaw.ForwardM1(right_front, i);
    roboclaw.ForwardM1(left_rear, i);
    roboclaw.ForwardM1(right_rear, i);
    delay(50);
  }

  // Wait 2 seconds before starting the loop again
  delay(2000);

}