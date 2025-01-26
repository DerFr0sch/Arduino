// constants won't change. They're used here to set pin numbers.
// button pins are used to represent the floor number of the building.
const int BUTTON_PIN_1 = 3;
const int BUTTON_PIN_2 = 4;
const int BUTTON_PIN_3 = 5;
const int BUTTON_PIN_4 = 6;
const int BUTTON_PIN_5 = 7;

// LEDs are used to represent the floor number of the building.
const int LED_PIN_1 =  8;
const int LED_PIN_2 =  9;
const int LED_PIN_3 =  10;
const int LED_PIN_4 =  11;
const int LED_PIN_5 =  12;

// declare buttonState, which reads the pushbutton status.
int buttonState_1 = 0;
int buttonState_2 = 0;
int buttonState_3 = 0;
int buttonState_4 = 0;
int buttonState_5 = 0;

// declare currentFloor, which keeps track of where the "elevator" is currently located
// as well as targetFloor, which is where the "elevator" is headed.
int currentFloor = 4;
int targetFloor = 4;
int floorDifference = 1;
int a = 0;

void setup() {
  Serial.begin(9600);

  // initialize the LED pin as an output:
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  // initialize the pushbutton pin as an pull-up input:
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  pinMode(BUTTON_PIN_5, INPUT_PULLUP);

  // "elevator" starts at floor 1.
  digitalWrite(LED_PIN_4, HIGH);
}

// checks if currentFloor and targetFloor are identical. If not, the code will calculate
// the difference between them and will either move the "elevator" up or down accordingly,
// depending on if the difference is positive (up) or negative (down). When currentFloor
// and targetFloor are the same integer, the loop stops and returns the new value of
// currentFloor back to the function that called it.
void moveElevator(int currentFloorParam, int targetFloorParam) {
  floorDifference = targetFloorParam - currentFloorParam;
  while (floorDifference != 0) {
    if (floorDifference > 0) {
      delay(1000);
      digitalWrite(currentFloorParam + 7, HIGH);
      delay(1000);
      digitalWrite(currentFloorParam + 7, LOW);
      currentFloorParam++;
      floorDifference--;
      Serial.print("Elevator is now at floor ");
      Serial.println(currentFloorParam);
      Serial.println(floorDifference);
      if (floorDifference == 0) {
        break;
      }
    } else if (floorDifference < 0) {
      delay(1000);
      digitalWrite(currentFloorParam + 7, HIGH);
      delay(1000);
      digitalWrite(currentFloorParam + 7, LOW);
      currentFloorParam--;
      floorDifference++;
      Serial.print("Elevator is now at floor ");
      Serial.println(currentFloorParam);
      Serial.println(floorDifference);
      if (floorDifference == 0) {
        break;
      }
    }
  }
  currentFloor = currentFloorParam;  // Update the global currentFloor
  targetFloor = targetFloorParam;    // Update the global targetFloor
}

void loop() {
  // read the state of the pushbutton value:
  buttonState_1 = digitalRead(BUTTON_PIN_1);
  buttonState_2 = digitalRead(BUTTON_PIN_2);
  buttonState_3 = digitalRead(BUTTON_PIN_3);
  buttonState_4 = digitalRead(BUTTON_PIN_4);
  buttonState_5 = digitalRead(BUTTON_PIN_5);

  if(buttonState_1 == LOW)         // If button is pressing
    targetFloor = 1;
    moveElevator(currentFloor, targetFloor);
//    digitalWrite(currentFloor+7, HIGH);

  if(buttonState_2 == LOW)         // If button is pressing
    targetFloor = 2;
    moveElevator(currentFloor, targetFloor);
  //  digitalWrite(currentFloor+7, HIGH);

  if(buttonState_3 == LOW)         // If button is pressing
    targetFloor = 3;
    moveElevator(currentFloor, targetFloor);
  //  digitalWrite(currentFloor+7, HIGH);

  if(buttonState_4 == LOW)         // If button is pressing
    targetFloor = 4;
    moveElevator(currentFloor, targetFloor);
  //  digitalWrite(currentFloor+7, HIGH);

  if(buttonState_5 == LOW)         // If button is pressing
    targetFloor = 5;
    moveElevator(currentFloor, targetFloor);
  //  digitalWrite(currentFloor+7, HIGH);
}