/*
functionsForLightControl.ino

Arduino code for the manual control of four LED light phase,
which will be input from two buttons.

Rui Wang
*/

const int whitePin = 3;
const int bluePin = 5;
const int redPin = 6;

const int buttonOne = 2;

/*
Stage order
off (0) -> seedling (1) -> vegetative(2) -> flowering (3) -> back to off
*/

/*
==+ signal logic +==
bottonOne is pressed:
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


void setup(){
    pinMode(whitePin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(redPin, OUTPUT);

    pinMode(buttonOne, INPUT_PULLUP);

    Serial.begin(9600); //for print out message

    analogWrite(whitePin, 191); // white always on
}

void loop(){
  int b1 = digitalRead(buttonOne);

  //buttonOne pressed
  if(b1 == LOW && lastB1 == HIGH){
    Serial.print("go to next stage");
    currStage = currStage + 1;
    currStage = currStage % 4;
    delay(200);
  }
  else{
    Serial.print("Not recognized button pattern. Failed. Try again.");
  }

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
  Serial.print("Seedling Stage");
  analogWrite(bluePin, 220);
  analogWrite(redPin, 60);
}

//mid blue mid red
void vegetative(){
  Serial.print("Vegetative Stage");
  analogWrite(bluePin, 200);
  analogWrite(redPin, 120);
}

//less blue more red
void flowering(){
  Serial.print("Flowering Stage");
  analogWrite(bluePin, 100);
  analogWrite(redPin, 220);
}

//no
void off(){
  Serial.print("Off");
  analogWrite(whitePin, 0);
  analogWrite(bluePin, 0);
  analogWrite(redPin, 0);
}

