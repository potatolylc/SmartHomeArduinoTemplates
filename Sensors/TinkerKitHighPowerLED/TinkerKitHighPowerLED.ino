/*
    This code is for blinking a power led 
    by using TinkerKit power led.
*/

// include the TinkerKit library
#include <TinkerKit.h>
 
// creating the object 'led' that belongs to the 'TKLed' class 
TKLed led(O4);  
         
 
void setup() {
//nothing here
}
 
void loop() 
{
  led.on();       // set the LED on
  delay(1000);    // wait for a second
  led.off();      // set the LED off
  delay(1000);    // wait for a second
}
