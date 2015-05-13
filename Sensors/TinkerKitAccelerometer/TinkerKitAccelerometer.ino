/*
    This code is for sensing the x and y values of a TinkerKit accelerometer.
    With the sensed values, turn on two leds.
*/

// include the TinkerKit library
#include <TinkerKit.h>
 
//Create "accelerometer" object of
//TKAccelerometer class.
TKAccelerometer accelerometer(I0, I1); 
 
//Same with two leds
TKLed xLed(O0), yLed(O1);
 
 
// a variable to store the accelerometer's x value
int xAxisValue = 0;           
// a variable to store the accelerometer's y value
int yAxisValue = 0;           
 
void setup() 
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}
 
void loop()
{
  // read the both joystick axis values:
  xAxisValue = accelerometer.readX();  
  yAxisValue = accelerometer.readY(); 
 
  // set the leds brightness
  xLed.brightness(xAxisValue);
  yLed.brightness(yAxisValue);
 
  // print the results to the serial monitor:
  Serial.print("Accelerometer X = " );                       
  Serial.print(xAxisValue);   
  Serial.print("\t Accelerometer Y = " );                       
  Serial.println(yAxisValue);     
 
 
  // wait 10 milliseconds before the next loop
  delay(10);    
}
