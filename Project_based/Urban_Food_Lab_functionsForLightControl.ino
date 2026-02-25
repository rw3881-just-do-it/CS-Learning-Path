/*
functionsForLightControl.ino

Arduino code for the manual control of four LED light phase,
which will be input from two buttons.

RW
*/

const int whitePin = 3;
const int bluePin = 5;
const int redPin = 6;

const int buttonOne = 2;
const int buttonTwo = 4;

/*
Stage order
off (0) -> seedling (1) -> vegetative(2) -> flowering (3) -> back to off
*/

/*
==+ two button signal logic +==
if buttonTwo is pressed:
  off mode (reset)
if both bottons are pressed:
  off mode (reset)
if only bottonOne is pressed:
  go to next stage
*/

enum LedStage{
  OFF = 0,
  SEEDLING,
  VEGETATIVE,
  FLOWERING,
};

LedStage currStage = OFF; // default off

//To triger stage changing in the loop
int lastB1 = HIGH;
int lastB2 = HIGH;


void setup(){
    pinMode(whitePin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(redPin, OUTPUT);

    pinMode(buttonOne, INPUT_PULLUP);
    pinMode(buttonTwo, INPUT_PULLUP);

    Serial.begin(9600); //for print out message

    analogWrite(whitePin, 191); // white always on
}

void loop(){
  int b1 = digitalRead(buttonOne);
  int b2 = digitalRead(buttonTwo);

  //reset
  if(b2 == LOW && lastB2 == HIGH){
    Serial.print("reset to off, stage 0");
    currStage = OFF;
    delay(200);
  }
  //only buttonOne pressed
  else if(b1 == LOW && lastB1 == HIGH && b2 == HIGH){
    Serial.print("go to next stage");
    currStage = currStage + 1;
    currStage = currStage % 4;
    delay(200);
  }
  else{
    Serial.print("Not recognized button pattern. Failed. Try again.");
  }
  lastB1 = b1;
  lastB2 = b2;

  Growth(currStage);
}

void Growth(int phase){
  switch(phase){
    case OFF:
      off();
      break;
    case SEEDLING:
      seedling();
      break;
    case VEGETATIVE:
      vegetative();
      break;
    case FLOWERING:
      flowering();
      break;
  }
}

//more blue less red
void seedling(){
  analogWrite(bluePin, 220);
  analogWrite(redPin, 60);
}

//mid blue mid red
void vegetative(){
  analogWrite(bluePin, 200);
  analogWrite(redPin, 120);
}

//less blue more red
void flowering(){
  analogWrite(bluePin, 100);
  analogWrite(redPin, 220);
}

//no
void off(){
  analogWrite(whitePin, 0);
  analogWrite(bluePin, 0);
  analogWrite(redPin, 0);
}

