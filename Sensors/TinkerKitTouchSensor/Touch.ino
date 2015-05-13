/*
    This code is for detecting whether a touch signal is catched 
    by using TinkerKit touch sensor.
*/

// include the TinkerKit library
#include <TinkerKit.h>
 
// creating the object 'touch' that belongs to the 'TKTouchSensor' class 
TKTouchSensor touch(I1);
 
// creating the object 'led' that belongs to the 'TKLed' class 
TKLed led(O1);      
 
void setup() {
  //nothing here
}
 
void loop()
{
  // check the "switch state" of the sensor
  // if it is, turns on the LED
  if (touch.held() == HIGH) {      
    led.on();     // turn LED on 
  } else {
    led.off();    // turn LED off
  }
}
