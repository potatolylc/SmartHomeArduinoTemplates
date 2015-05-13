/*
    This code is for detecting whether a tilt signal is catched.
    If the signal is catched, then led is on.
*/

int ledPin = 13;                // Connect LED to pin 13
int switcher = 3;                 // Connect Tilt sensor to Pin3
 
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      // Set digital pin 13 to output mode
  pinMode(switcher, INPUT);       // Set digital pin 3 to input mode
}
void loop()
{
   Serial.println(digitalRead(switcher));  
   if(digitalRead(switcher)==HIGH) //Read sensor value
     { 
        digitalWrite(ledPin, HIGH);   // Turn on LED when the sensor is tilted
     }
   else
     {
        digitalWrite(ledPin, LOW);    // Turn off LED when the sensor is not triggered
     }
}
