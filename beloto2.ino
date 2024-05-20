// Dua button dan LED
const int pinButton1 = 2;
// const int pinButton2 = 3;
const int pinLed = 9;

void setup() {
  pinMode(pinButton1, INPUT);
  // pinMode(pinButton2, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinButton1, HIGH);
  // digitalWrite(pinButton2, HIGH);
}

void loop() {
  if (digitalRead(pinButton1) == LOW) {
    digitalWrite(pinLed, HIGH);
    delay(300);
    digitalWrite(pinLed, LOW);
    delay(300);
  } else {
    digitalWrite(pinLed, LOW);
  }
}
