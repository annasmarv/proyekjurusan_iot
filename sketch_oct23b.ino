#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "LXXIII";
const char* password = "12345678";

// Initialize Telegram BOT
#define BOTtoken "6794877940:AAGXLEvDhaPu29zaFmBeyHJZGopG5IOL66Y"  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "600651043"
#define relay D8

#ifdef ESP8266
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

const int ledPin = 2;

bool ledState = LOW;

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
 Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Gunakan Perintah Berikut. \n\n";
      welcome += "/nyala Untuk Menyalakan Lampu \n";
      welcome += "/mati Untuk Mematikan Lampu \n";
      welcome += "/status Mengecek Status Lampu \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/nyala") {
      ledState = HIGH;
      digitalWrite(relay, ledState);
      bot.sendMessage(chat_id, "Lampu Berhasil di Nyalakan", "");
    }
    
    if (text == "/mati") {
      ledState = LOW;
      digitalWrite(relay, ledState);
      bot.sendMessage(chat_id, "Lampu Berhasil di Matikan", "");
    }
    
    if (text == "/status") {
      if (digitalRead(relay)){
        bot.sendMessage(chat_id, "Lampu sudah menyala", "");
      }
      else{
        bot.sendMessage(chat_id, "Lampu sudah mati", "");
      }
    }
  }
}

void setup() {
  Serial.begin(115200);

  #ifdef ESP8266
    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
    client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  #endif

  pinMode(relay, OUTPUT); 
//  pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, ledState);
   digitalWrite(relay, ledState);
  
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
