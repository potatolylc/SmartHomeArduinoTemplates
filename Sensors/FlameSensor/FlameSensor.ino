/*
     This code is for detecting a flame signal 
     by using the flame sensor DFR0076.
*/
#define FLAME_SENSOR A3
 
int pbIn = 0;
int state = LOW;
int flameValue;

void setup() 
{
  Serial.begin(9600);
  attachInterrupt(pbIn, stateChange, CHANGE);
}

void loop() 
{
  flameValue = analogRead(FLAME_SENSOR);
  Serial.println(flameValue);
  delay(500);
}

void stateChange() 
{
  // some action
  state = HIGH;
}
