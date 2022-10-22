void rightTSOn(){
  while(RState == HIGH && hazState != HIGH && headState != HIGH){       // right turn signal
    int startTick = millis(); // keep track of time
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
}
