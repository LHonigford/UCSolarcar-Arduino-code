void hazardsOn(){
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
}
