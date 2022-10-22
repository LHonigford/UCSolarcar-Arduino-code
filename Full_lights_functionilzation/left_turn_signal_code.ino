void leftTSOn(){
  while(LState == HIGH && hazState != HIGH && headState != HIGH){     // left turn signal
    int startTick = millis(); // keep track of time
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
}
