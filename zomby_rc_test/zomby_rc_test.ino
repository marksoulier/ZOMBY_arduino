#include <RC_Receiver.h>

RC_Receiver receiver(13,11,9,7,5);
/* Ch1: 13
 * Ch2: 11
 * Ch3: 9
 * Ch4: 7
 * Ch5: 5
 */

//Channel min and max value
//Leave the default value for the un used channels
//Invert the min and max val to reverse
int minMax[5][2] = { 
// Min   Max
	{1088,1880},  // Ch1: Throttle
	{1088,1873},  // Ch2: Elevator
	{1085,1871},  // Ch3: Aileron (Max to the left and min to the right)
	{1090,1875},  // Ch4: Rudder (Max to the left and min to the right)
  {1080, 1880}  // Ch5: Gear Channel (kill switch) (0 = 1880) (1 = 1080)
                // Ch6: Aux channel (0 = 1880) (1/2 = 1480) (1 = 1080)
};

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

  // Set min and max values for receiver channels
  receiver.setMinMax(minMax);

}

/******************************************************************************
NOIE: To run a motor forward at a certain speed, use the following command:

roboclaw.ForwardM1(address of motor, speed from 0 to 128);

To run it backwards, use this command:

roboclaw.BackwardM1(address of motor, speed from 0 to 128);

To run it forwards or backwards, use this command:

roboclaw.ForwardBackwardM1(address of motor, speed from 0 to 128);
 > 0 to 63 runs it backwards
 > 64 stops motor
 > 65 to 128 runs it forwards

Once the speed has been set, the motor will continue at that speed until it
receives another command.
******************************************************************************/

int speed;
int difference;
int final_speed_right;
int final_speed_left;

void loop() {

  speed = map(receiver.getMap(2), 0, 100, 0, 128);
  difference = map(receiver.getMap(3), 0, 100, -40, 40);

  // Create dead zone in the middle of the stick so the robot will stop moving
  // when stick is in the middle
  if (speed >= 62 && speed <= 66)
  {
    speed = 64;
  }
  if (difference >= -1 && difference <= 1)
  {
    difference = 0;
  }

  final_speed_left = speed - difference;
  final_speed_right = speed + difference;

  roboclaw.ForwardBackwardM1(left_front,  final_speed_left);
  roboclaw.ForwardBackwardM1(right_front, final_speed_right);
  roboclaw.ForwardBackwardM1(left_rear,   final_speed_left);
  roboclaw.ForwardBackwardM1(right_rear,  final_speed_right);

}