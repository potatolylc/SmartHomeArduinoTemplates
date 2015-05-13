/*
    This code is for detecting whether a vibration signal is catched.
    If the signal is catched, then led is on.
*/

#define SensorLED     13
#define SensorINPUT   3  //Connect the sensor to digital Pin 3 which is Interrupts 1.
  
unsigned char state = 0;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(SensorLED, OUTPUT); 
  pinMode(SensorINPUT, INPUT);
  attachInterrupt(1, blink, FALLING);// Trigger the blink function when the falling edge is detected
  
}
void loop()
{
      if(state!=0)
      {
        state = 0;
        digitalWrite(SensorLED,HIGH);
        delay(200);
        Serial.println(state);
      }  
      else
        digitalWrite(SensorLED,LOW);
} 
  
  
void blink()//Interrupts function
{
  state++;
}
