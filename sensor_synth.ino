
const byte buttonPin = 2;
const byte ledPin = 13;
byte ledState = LOW;
int buttonPresses = 0;
long lastInterruptTime = 0;

int i = 1;
int CMajor[] = {60, 62, 64, 65, 67, 69, 71, 72};
boolean swapScale = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), sendNote, RISING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  i++;
  delay(1000);
}

void sendNote() {
  long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 200) {
    buttonPresses++;
    Serial.print("note ");
    Serial.println(CMajor[buttonPresses % 8]);
    Serial.print("light ");
    Serial.println(i % 100);
  }

  lastInterruptTime = interruptTime;
}
