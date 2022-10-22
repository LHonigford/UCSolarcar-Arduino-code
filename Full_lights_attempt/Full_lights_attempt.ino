int relay[] = {9, 10, 11, 12, 3, 4}; // 0 = Right head light, 1 = Left head light, 2 = Front left turn signal, 3 = Front right turn signal, 4 = Back left turn signal, 5 = Back right turn signal
int LSwitch = 7; // set up all the switch pins
int RSwitch = 8;
int hazSwitch = 5;
int headSwitch = 6;
void setup() {
  pinMode(LSwitch, INPUT);  // all switch pins are inputs
  pinMode(RSwitch, INPUT);
  pinMode(hazSwitch, INPUT);
  pinMode(headSwitch, INPUT);
  for(int i = 0; i <= 5; i++){  // all relay pins are outputs
    pinMode(relay[i], OUTPUT);
  }
}

void loop() {
  int first = 0;  // variable just to keep hazards cleaner
  int tick = 500; // flicker rate of turn signals and hazards
  int LState = digitalRead(LSwitch);  // read all switches everytime through
  int RState = digitalRead(RSwitch);
  int hazState = digitalRead(hazSwitch);
  int headState = digitalRead(headSwitch);
  while(hazState == HIGH){      //hazards on
    if((LState == HIGH || RState == HIGH) && first == 0){ // check if this is the first iteration of the hazards and reset lights if the turn signals were on
      digitalWrite(relay[2], HIGH);
      digitalWrite(relay[3], HIGH);
      delay(100);
      first = 1;
    }
    int startTick = millis(); // keep track of time
    int currentTick = millis();
    digitalWrite(relay[1], HIGH); //turn off any lights that may be on, turn on lights that we need on
    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[2], LOW);  
    digitalWrite(relay[3], LOW);
    while(hazState == HIGH && currentTick - startTick <= tick){ // turn the flickering lights on
      digitalWrite(relay[4], LOW);
      digitalWrite(relay[5], LOW);
      currentTick = millis();
      hazState = digitalRead(hazSwitch);  // check if loop needs to be broken
    }
    startTick = millis();
    while(hazState == HIGH && currentTick - startTick <= tick){ // turn the flickering lights off
      digitalWrite(relay[4], HIGH);
      digitalWrite(relay[5], HIGH);
      currentTick = millis();
      hazState = digitalRead(hazSwitch);  //check if loop needs to be broken
    }
  }
  while(RState == HIGH && hazState != HIGH && headState != HIGH){       // right turn signal
    int startTick = millis();
    int currentTick = millis();
    digitalWrite(relay[2], HIGH); //turn off any lights that may be on, turn on lights that we need on
    digitalWrite(relay[3], LOW);
    digitalWrite(relay[1], HIGH);
    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[4], HIGH);
    while(RState == HIGH && hazState != HIGH && headState != HIGH && currentTick - startTick <= tick){  //turn flickering light on
      digitalWrite(relay[5], LOW);
      currentTick = millis();
      RState = digitalRead(RSwitch);  //all the checks that will break the loop
      hazState = digitalRead(hazSwitch);
      headState = digitalRead(headSwitch);
    }
    startTick = millis();
    while(RState == HIGH && hazState != HIGH && headState != HIGH && currentTick - startTick <= tick){  //turn flickering light off
      digitalWrite(relay[5], HIGH);
      currentTick = millis();
      RState = digitalRead(RSwitch);  //all the checks that will break the loop
      hazState = digitalRead(hazSwitch);
      headState = digitalRead(headSwitch);
    }
  }
  while(LState == HIGH && hazState != HIGH && headState != HIGH){     // left turn signal
    int startTick = millis();
    int currentTick = millis();
    digitalWrite(relay[2], LOW);  //turn off any lights that may be on, turn on lights that we need on
    digitalWrite(relay[3], HIGH);
    digitalWrite(relay[1], HIGH);
    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[5], HIGH);
    while(LState == HIGH && hazState != HIGH && headState != HIGH && currentTick - startTick <= tick){  //turn flickering light on
      digitalWrite(relay[4], LOW);
      currentTick = millis();
      LState = digitalRead(LSwitch);  //all the checks that will break the loop
      hazState = digitalRead(hazSwitch);
      headState = digitalRead(headSwitch);
    }
    startTick = millis();
    while(LState == HIGH && hazState != HIGH && headState != HIGH && currentTick - startTick <= tick){  //turn flickering light off
      digitalWrite(relay[4], HIGH);
      currentTick = millis();
      LState = digitalRead(LSwitch);  //all the checks that will break the loop
      hazState = digitalRead(hazSwitch);
      headState = digitalRead(headSwitch);
    }
  }
  while(headState == HIGH && hazState != HIGH){           // headlights
    while(LState == HIGH && headState == HIGH && hazState != HIGH){   // headlights with a left turn signal
      digitalWrite(relay[0], HIGH); //turn off any lights that may be on, turn on lights that we need on
      digitalWrite(relay[3], HIGH);
      digitalWrite(relay[5], HIGH);
      digitalWrite(relay[1], LOW);
      digitalWrite(relay[2], LOW);
      digitalWrite(relay[4], LOW);
      delay(500);
      digitalWrite(relay[4], HIGH);
      delay(500);
      headState = digitalRead(headSwitch);  //all the checks that will break the loop
      hazState = digitalRead(hazSwitch);
      LState = digitalRead(LSwitch);
    }
    while(RState == HIGH && headState == HIGH && hazState != HIGH){   // headlights with a right turn signal
      digitalWrite(relay[1], HIGH); //turn off any lights that may be on, turn on lights that we need on
      digitalWrite(relay[2], HIGH);
      digitalWrite(relay[4], HIGH);
      digitalWrite(relay[0], LOW);
      digitalWrite(relay[3], LOW);
      digitalWrite(relay[5], LOW);
      delay(500);
      digitalWrite(relay[5], HIGH);
      delay(500);
      headState = digitalRead(headSwitch);  //all the checks that will break the loop
      hazState = digitalRead(hazSwitch);
      RState = digitalRead(RSwitch);
    }
    digitalWrite(relay[2], HIGH); //turn off any lights that may be on, turn on lights that we need on
    digitalWrite(relay[3], HIGH);
    digitalWrite(relay[1], LOW);
    digitalWrite(relay[0], LOW);
    digitalWrite(relay[4], HIGH);
    digitalWrite(relay[5], HIGH);
    headState = digitalRead(headSwitch);  //all the checks that will break the loop
    hazState = digitalRead(hazSwitch);
    LState = digitalRead(LSwitch);
    RState = digitalRead(RSwitch);
  }
  if(headState == LOW && hazState == LOW && RState == LOW && LState == LOW){  //if no switches are on, turn off all lights
    for(int i = 0; i <= 5; i++){
      digitalWrite(relay[i], HIGH);
    }
  }
}
