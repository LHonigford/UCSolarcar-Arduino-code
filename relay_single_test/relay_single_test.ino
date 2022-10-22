int relay = 9;  // call pin as a variable
void setup() {
  pinMode(relay, OUTPUT); //initialize pin as an output
}

void loop() {
  digitalWrite(relay, LOW); //turn on for 2 seconds
  delay(2000);
  digitalWrite(relay, HIGH);  //turn off for 1 second
  delay(1000);
}
