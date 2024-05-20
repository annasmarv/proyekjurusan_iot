// Dua button dan LED
const int pinButton1 = 2; // berada pada pin dua arduino
const int pinButton2 = 3; // berada pada pin tiga arduino
const int pinLed = 9; // led berada di pin sembilan

void setup() {
  pinMode(pinButton1, INPUT); // sebagai input
  pinMode(pinButton2, INPUT); // sebagai input
  pinMode(pinLed, OUTPUT); // sebagai output
  digitalWrite(pinButton1, HIGH); // pull up pin 1 aktif
  digitalWrite(pinButton2, HIGH); // pull up pin 2 aktif
}

void loop() {
  if (digitalRead(pinButton1) == LOW) { // membaca jika button kita tekan
    digitalWrite(pinLed, HIGH); // menyalakan LED
  }
  else if (digitalRead(pinButton2) == LOW) {
    digitalWrite(pinLed, LOW); // mematikan LED
  }
}
