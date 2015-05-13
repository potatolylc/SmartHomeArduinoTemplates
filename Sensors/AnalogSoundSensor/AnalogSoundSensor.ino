/*
    This code is for collecting analog sound value from an analog sound sensor.
*/

#define ANALOG_SOUND 3

void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
void loop()
{
      int val;
      val=analogRead(ANALOG_SOUND);   //connect mic sensor to ANALOG_SOUND pin
      Serial.println(val,DEC);//print the sound value to serial        
      delay(100);
}
