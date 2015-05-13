/*
    This code is for collecting temperature and humidity information data
    by using DHT11 sensor.
*/

#define dpin A2

byte bGlobalErr;
byte data[5];

void setup(){
  InitDHT();
  Serial.begin(9600);
  delay(300);
  Serial.println("Humidity and Temperature \n\n");
  delay(700);
}

void loop(){
  ReadDHT();
  switch(bGlobalErr){
    case 0:
       Serial.print("Current humdity = ");
       Serial.print(data[0], DEC);
       Serial.print(".");
       Serial.print(data[1], DEC);
       Serial.print("%  ");
       Serial.print("temperature = ");
       Serial.print(data[2], DEC);
       Serial.print(".");
       Serial.print(data[3], DEC);
       Serial.println("C  ");
       break;
    case 1:
       Serial.println("Error 1: DHT start condition 1 not met.");
       break;
    case 2:
       Serial.println("Error 2: DHT start condition 2 not met.");
       break;
    case 3:
       Serial.println("Error 3: DHT checksum error.");
       break;
    default:
       Serial.println("Error: Unrecognized code encountered.");
       break;
  }
  delay(800);
}

void InitDHT(){
  pinMode(dpin, OUTPUT);
  digitalWrite(dpin, HIGH);
}

void ReadDHT(){
  bGlobalErr=0;
  byte in;
  byte i;
  digitalWrite(dpin, LOW);
  delay(20);
  
  digitalWrite(dpin,HIGH);
  delayMicroseconds(40);
  
  pinMode(dpin, INPUT);
  in=digitalRead(dpin);
  
  if(in){
    bGlobalErr=1;
    return;
  }
  delayMicroseconds(80);
  in=digitalRead(dpin);
  
  if(!in){
    bGlobalErr=2;
    return;
  }
  delayMicroseconds(80);
  for(i=0; i<5; i++){
    data[i]=read_data();
    Serial.println(data[i]);
  }
  
  pinMode(dpin, OUTPUT);
  digitalWrite(dpin, HIGH);
  byte data_sum=data[0]+data[1]+data[2]+data[3];
  if(data[4]!=data_sum){
    //bGlobalErr=3;
  }  
};

byte read_data(){
  byte i=0;
  byte result=0;
  for(i=0; i<8; i++){
    while(digitalRead(dpin)==LOW);
    delayMicroseconds(30);
    if(digitalRead(dpin)==HIGH)
      result |=(1<<(7-i));
    while(digitalRead(dpin)==LOW);
  }
  return result;
}


























