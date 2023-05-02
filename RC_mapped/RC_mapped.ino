/*
 * RC Mapped
 *
 * Get rc remote value mapped from 0 to 100
 * 
 * This example code is in the public domain.
 */

#include <RC_Receiver.h>

//Create an instance of a receiver
//You can put up to 8 channels pin with one receiver instance
//ex : RC_Receiver receiver('ch1','ch2','ch3','ch4','ch5','ch6','ch7','ch8',);
RC_Receiver receiver(13,3,4,5);

//Channel min and max value
//Use the RC_raw script to get the min max val by moving your joystick up and down
//This need to be combined with the receiver.setMinMax(minMax); call
//Leave the default value for the un used channels
//First val is the min and the second is the max
//Invert the min and max val to reverse
int minMax[8][2] = 
{ 
	{1088,1880}, 
	{1010,2020}, 
	{1010,2020}, 
	{1010,2020}, 
	{1010,2020}, 
	{1010,2020}, 
	{1010,2020}, 
	{1010,2020}
};


void setup() {
  //Starting Serial
  Serial.begin(9600);

  receiver.setMinMax(minMax); //set the min and max value for each channels
  
  Serial.println("Ready");
}

void loop() {
   //prints receiver mapped val
   Serial.print(receiver.getMap(1));
   Serial.print("\t");  
   Serial.print(receiver.getMap(2));
   Serial.print("\t");  
   Serial.print(receiver.getMap(3));
   Serial.print("\t");  
   Serial.print(receiver.getMap(4));
   Serial.print("\t");  
   Serial.println();
}