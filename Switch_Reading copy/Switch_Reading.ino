int LSwitch = 7;
int RSwitch = 8;
int hazSwitch = 5;
int headSwitch = 6;
void setup() {
  pinMode(LSwitch, INPUT);
  pinMode(RSwitch, INPUT);
  pinMode(hazSwitch, INPUT);
  pinMode(headSwitch, INPUT);
  Serial.begin(9600);
}

void loop() {
  int LState = digitalRead(LSwitch);
  int RState = digitalRead(RSwitch);
  int hazState = digitalRead(hazSwitch);
  int headState = digitalRead(headSwitch);
  if(LState == HIGH){
    Serial.print("Left turn signal on. ");
  }
  if(RState == HIGH){
    Serial.print("Right turn signal on. ");
  }
  if(hazState == HIGH){
    Serial.print("Hazards on. ");
  }
  if(headState == HIGH){
    Serial.print("Headlights on. ");
  }
  if(headState == LOW && hazState == LOW && RState == LOW && LState == LOW){
    Serial.print("No signals on. ");
  }
  Serial.print('\n');
  delay(300);
}
