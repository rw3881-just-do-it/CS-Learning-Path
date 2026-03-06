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


int currStage = 0; // default off

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
    Serial.print("go to next stage\n");
    currStage = currStage + 1;
    currStage = currStage % 4;
    delay(200);
  }

  Growth(currStage);
}

void Growth(int phase){
  switch(phase){
    case 0:
      off();
      break;
    case 1:
      seedling();
      break;
    case 2:
      vegetative();
      break;
    case 3:
      flowering();
      break;
  }
}

//more blue less red
void seedling(){
  Serial.print("Seedling Stage\n");
  analogWrite(bluePin, 77);
  analogWrite(redPin, 179);
  analogWrite(whitePin, 220);
}

//mid blue mid red
void vegetative(){
  Serial.print("Vegetative Stage\n");
  analogWrite(bluePin, 38);
  analogWrite(redPin, 217);
  analogWrite(whitePin, 220);
}

//less blue more red
void flowering(){
  Serial.print("Flowering Stage\n");
  analogWrite(bluePin, 26);
  analogWrite(redPin, 230);
  analogWrite(whitePin, 220);
}

//no
void off(){
  Serial.print("Off\n");
  analogWrite(whitePin, 0);
  analogWrite(bluePin, 0);
  analogWrite(redPin, 0);
}

