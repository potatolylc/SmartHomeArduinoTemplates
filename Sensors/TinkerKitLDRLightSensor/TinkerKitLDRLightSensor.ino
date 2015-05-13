/*
    This code is for sensing the light brightness 
    by using a TinkerKit light brightness sensor.
*/

#include <TinkerKit.h>

//create the "ldr" object on port I0
TKLightSensor ldr(I0);	

//create the "led" object on port O1
TKLed led(O1);		

void setup() {
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop() {
  // store the ldr values into a variable called brightnessVal
  int brightnessVal = ldr.read();            

  // set the led brightness
  led.brightness(brightnessVal);       
  
  //to have it at full brightness
  //when it's dark, uncomment this line:
  led.brightness(1023 - brightnessVal);

  // print the results to the serial monitor:
  Serial.print("brightness = " );                      
  Serial.println(brightnessVal);      


  // wait 10 milliseconds before the next loop
  delay(1000);                    
}

