// constants won't change. They're used here to set pin numbers.
// Button pin.
const int BUTTON_PIN_1 = 3;

// Two LEDs.
const int LED_PIN_1 =  8;
const int LED_PIN_2 =  9;

// declare buttonState, which reads the pushbutton status.
int buttonState_1 = 0;

void setup() {
  Serial.begin(9600);

  // initialize the LED pin as an output:
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  // initialize the pushbutton pin as an pull-up input:
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

}
