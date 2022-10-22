int switchPin = 8;  // call switch pin as a variable
void setup() {
  pinMode(switchPin, INPUT);  // set up switch pin as an input
  Serial.begin(9600); //set up serial monitor for reading
}

void loop() {
  int switchState = digitalRead(switchPin); //read switch pin
  if(switchState == HIGH){  //if switch pin is on, print on
    Serial.println("Switch on");
  }
  else{   //if switch pin is off, print off
    Serial.println("Switch off");
  }
  delay(300); //slight delay for reading ease
}
