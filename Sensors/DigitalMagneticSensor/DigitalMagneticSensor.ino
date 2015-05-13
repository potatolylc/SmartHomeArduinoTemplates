/*
    This code is for detecting whether a magnetic signal is catched.
    If signal is catched, then led is on.
*/

int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // choose the input pin  
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare pushbutton as input
  Serial.begin(9600);
}
void loop(){
  val = digitalRead(inputPin);  // read input value
  Serial.println(val);
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
