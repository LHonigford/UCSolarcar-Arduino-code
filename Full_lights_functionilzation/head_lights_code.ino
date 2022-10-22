void headsOn(){
  while(headState == HIGH && hazState != HIGH){           // headlights 
      digitalWrite(relay[3], HIGH); //turn off all lights that need turned off
      digitalWrite(relay[5], HIGH);
      digitalWrite(relay[2], HIGH);
      digitalWrite(relay[4], HIGH);
      digitalWrite(relay[0], LOW);
      digitalWrite(relay[1], LOW);
      while(LState == HIGH && hazState != HIGH && headState == HIGH){     // left turn signal
      int startTick = millis(); // keep track of time
      int currentTick = millis();
    
      digitalWrite(relay[2], LOW);  //turn off any lights that may be on, turn on lights that we need on
      digitalWrite(relay[3], HIGH);
      digitalWrite(relay[5], HIGH);
    
      while(LState == HIGH && hazState != HIGH && headState == HIGH && currentTick - startTick <= tick){  //turn flickering light on
        digitalWrite(relay[4], LOW);
        currentTick = millis();
        LState = digitalRead(LSwitch);  //all the checks that will break the loop
        hazState = digitalRead(hazSwitch);
        headState = digitalRead(headSwitch);
      }
    
      startTick = millis();
    
      while(LState == HIGH && hazState != HIGH && headState == HIGH && currentTick - startTick <= tick){  //turn flickering light off
        digitalWrite(relay[4], HIGH);
        currentTick = millis();
        LState = digitalRead(LSwitch);  //all the checks that will break the loop
        hazState = digitalRead(hazSwitch);
        headState = digitalRead(headSwitch);
      }
    
    }
    while(RState == HIGH && hazState != HIGH && headState == HIGH){       // right turn signal
      int startTick = millis(); // keep track of time
      int currentTick = millis();
    
      digitalWrite(relay[2], HIGH); //turn off any lights that may be on, turn on lights that we need on
      digitalWrite(relay[3], LOW);
      digitalWrite(relay[4], HIGH);
    
      while(RState == HIGH && hazState != HIGH && headState == HIGH && currentTick - startTick <= tick){  //turn flickering light on
        digitalWrite(relay[5], LOW);
        currentTick = millis();
        RState = digitalRead(RSwitch);  //all the checks that will break the loop
        hazState = digitalRead(hazSwitch);
        headState = digitalRead(headSwitch);
      }
    
      startTick = millis();
    
      while(RState == HIGH && hazState != HIGH && headState == HIGH && currentTick - startTick <= tick){  //turn flickering light off
        digitalWrite(relay[5], HIGH);
        currentTick = millis();
        RState = digitalRead(RSwitch);  //all the checks that will break the loop
        hazState = digitalRead(hazSwitch);
        headState = digitalRead(headSwitch);
      }
    
    }
    RState = digitalRead(RSwitch);  //all the checks that will break the loop
    LState = digitalRead(LSwitch);
    hazState = digitalRead(hazSwitch);
    headState = digitalRead(headSwitch);
  }
}
