// Definisikan pin untuk sensor IR dan LED
const int irSensorPin = 2;
const int ledPin = 13;

void setup() {
  // Atur pin sensor IR sebagai input
  pinMode(irSensorPin, INPUT);
  // Atur pin LED sebagai output
  pinMode(ledPin, OUTPUT);

  // Inisialisasi komunikasi serial (opsional, untuk debugging)
  Serial.begin(9600);
}

void loop() {
  // Baca nilai dari sensor IR
  int irValue = digitalRead(irSensorPin);

  // Tampilkan nilai sensor di Serial Monitor (opsional, untuk debugging)
  Serial.println(irValue);

  // Jika sinyal IR terdeteksi, nyalakan LED
  if (irValue == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    // Jika tidak ada sinyal IR, matikan LED
    digitalWrite(ledPin, LOW);
  }

  // Tambahkan sedikit delay sebelum pembacaan berikutnya
  delay(100);
}
