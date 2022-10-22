int LSwitch = 7;  // call all the switch pins as variables
int RSwitch = 8;
int hazSwitch = 5;
int headSwitch = 6;
void setup() {
  pinMode(LSwitch, INPUT);  //initialize all switches as inputs
  pinMode(RSwitch, INPUT);
  pinMode(hazSwitch, INPUT);
  pinMode(headSwitch, INPUT);
  Serial.begin(9600); //start serial monitor for reading
}

void loop() {
  int LState = digitalRead(LSwitch);  //read all the switches
  int RState = digitalRead(RSwitch);
  int hazState = digitalRead(hazSwitch);
  int headState = digitalRead(headSwitch);
  if(LState == HIGH){ //print left if left is on
    Serial.print("Left turn signal on. ");
  }
  if(RState == HIGH){ //print right if right is on
    Serial.print("Right turn signal on. ");
  }
  if(hazState == HIGH){ //print hazards if hazard is on
    Serial.print("Hazards on. ");
  }
  if(headState == HIGH){  //print headlights if headlight on
    Serial.print("Headlights on. ");
  }
  if(headState == LOW && hazState == LOW && RState == LOW && LState == LOW){  //if no switches are on, print no signals
    Serial.print("No signals on. ");
  }
  Serial.print('\n'); //print on new line
  delay(300); //add delay for ease of reading
}
