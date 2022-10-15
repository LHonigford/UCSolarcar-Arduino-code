int relay = 8;
void setup() {
  pinMode(relay, OUTPUT);
}

void loop() {
  digitalWrite(relay, LOW);
  delay(2000);
  digitalWrite(relay, HIGH);
  delay(1000);
}
