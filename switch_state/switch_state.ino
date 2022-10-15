int switchPin = 8;
void setup() {
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int switchState = digitalRead(switchPin);
  if(switchState == HIGH){
    Serial.println("Switch on");
  }
  else{
    Serial.println("Switch off");
  }
  delay(300);
}
