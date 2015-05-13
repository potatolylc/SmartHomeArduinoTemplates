/*
    This code is for collecting temperature information data
    by using temperature sensor LM35.
*/
#define TEMPERATURE_SENSOR 0

void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
}
 
void loop()
{ 
    int val;
    int dat;
    val=analogRead(TEMPERATURE_SENSOR); // Read temperature data
    dat=(500 * val) /1024;
    Serial.print("Temp:"); //Display the temperature 
    Serial.print(dat);
    Serial.println("C");
    delay(500);
}
