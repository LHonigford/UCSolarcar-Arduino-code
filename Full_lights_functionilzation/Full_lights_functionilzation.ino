int relay[] = {9, 10, 11, 12, 3, 4}; // 0 = Right head light, 1 = Left head light, 2 = Front left turn signal, 3 = Front right turn signal, 4 = Back left turn signal, 5 = Back right turn signal

int LSwitch = 7; // set up all the switch pins
int RSwitch = 8;
int hazSwitch = 5;
int headSwitch = 6;

int first; // variable to keep hazards cleaner
int tick;  // flicker rate of turn signals and hazards

int LState; // set up all of these as global variables
int RState;
int hazState;
int headState;

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
  
  first = 0;  
  tick = 500; 
  
  LState = digitalRead(LSwitch);  // read all switches everytime through
  RState = digitalRead(RSwitch);
  hazState = digitalRead(hazSwitch);
  headState = digitalRead(headSwitch);
  
  hazardsOn();
  
  rightTSOn();
  
  leftTSOn();
  
  headsOn();
  
  if(headState == LOW && hazState == LOW && RState == LOW && LState == LOW){  //if no switches are on, turn off all lights
    for(int i = 0; i <= 5; i++){
      digitalWrite(relay[i], HIGH);
    }
  }
}
