/*
    This code is for detecting whether the infared signal is catched.
    If signal is detected, digitalRead will be high. 
    Switch the resistor backward to adjust the sensitivity as you want.
*/

#define INFARED_MOTION_SENSOR 3

unsigned char state = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(INFARED_MOTION_SENSOR, INPUT);
  attachInterrupt(1, blink, FALLING);
}
 
void loop()
{
  int val = digitalRead(INFARED_MOTION_SENSOR);
  Serial.println(val);
  if(state != 0){
    state = 0;
    delay(100); 
  }
}

void blink(){
  state++;
  Serial.println(state);
  delay(10000);
}
