// Definisikan pin untuk buzzer
const int buzzerPin = 8;

void setup() {
  // Atur pin buzzer sebagai output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Membuat buzzer berbunyi dengan pola tertentu

  // Bunyi 1: Buzzer ON selama 500 ms
//  digitalWrite(buzzerPin, HIGH);
//  delay(500);

  // Bunyi 2: Buzzer OFF selama 500 ms
//  digitalWrite(buzzerPin, LOW);
//  delay(500);

  // Bunyi 3: Buzzer ON selama 300 ms
//  digitalWrite(buzzerPin, HIGH);
//  delay(300);

  // Bunyi 4: Buzzer OFF selama 300 ms
//  digitalWrite(buzzerPin, LOW);
//  delay(300);

  // Bunyi 5: Buzzer ON selama 100 ms
  digitalWrite(buzzerPin, HIGH);
  delay(100);

  // Bunyi 6: Buzzer OFF selama 100 ms
  digitalWrite(buzzerPin, LOW);
  delay(100);

  // Tunggu 1 detik sebelum memulai pola lagi
  delay(1000);
}
