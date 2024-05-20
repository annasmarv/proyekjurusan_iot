#include <Servo.h>

// Definisikan pin untuk Trig dan Echo
const int trigPin = 9;
const int echoPin = 10;

// Definisikan pin untuk Servo
const int servoPin = 6;

// Variabel untuk menyimpan durasi dan jarak
long duration;
int distance;

// Buat objek servo
Servo myServo;

// Ambang jarak untuk mendeteksi tangan atau objek (dalam cm)
const int thresholdDistance = 20;

void setup() {
  // Atur pin Trig sebagai output
  pinMode(trigPin, OUTPUT);
  // Atur pin Echo sebagai input
  pinMode(echoPin, INPUT);

  // Pasang servo ke pin yang telah ditentukan
  myServo.attach(servoPin);

  // Inisialisasi komunikasi serial (opsional, untuk debugging)
  Serial.begin(9600);

  // Posisikan servo pada posisi tertutup (0 derajat)
  myServo.write(0);
}

void loop() {
  // Pastikan Trig dalam keadaan LOW selama 2 mikrosekon
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Aktifkan Trig selama 10 mikrosekon untuk mengirimkan sinyal ultrasonik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi dari Echo
  duration = pulseIn(echoPin, HIGH);

  // Konversi durasi menjadi jarak dalam cm
  distance = duration * 0.034 / 2;

  // Tampilkan jarak di Serial Monitor (opsional, untuk debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Jika jarak lebih kecil dari ambang batas, buka tutup tempat sampah
  if (distance < thresholdDistance) {
    myServo.write(90); // Buka tutup tempat sampah (90 derajat)
    delay(5000); // Biarkan tutup terbuka selama 5 detik
  } else {
    // Tutup kembali jika tidak ada tangan atau objek
    myServo.write(0); // Tutup tutup tempat sampah (0 derajat)
  }

  // Tambahkan sedikit delay sebelum pengukuran berikutnya
  delay(500);
}
