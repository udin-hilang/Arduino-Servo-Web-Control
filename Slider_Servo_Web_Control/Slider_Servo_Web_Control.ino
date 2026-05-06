#include <ESP32Servo.h>
#include <WiFi.h>
#include <WebServer.h>
#include "sliderPage.h"

// WiFi credentials
String cmd = "", ssid = "realme 12+ 5G", pw = ""; 

WebServer server(80);              // Inisialisasi web server pada port 80
Servo myServo;

// Fungsi untuk mengirimkan tampilan HTML ke browser
void handleRoot() {
  server.send(200, "text/html", html); 
}

// Fungsi untuk menerima input nilai dari slider di halaman web
void handleSpeed() {
  String value = server.arg("value"); // Menangkap parameter "value" dari request
  int speed = value.toInt();          // Mengubah tipe data string ke integer
  myServo.write(speed);               // Menggerakkan servo sesuai nilai slider
}


void setup() {
  myServo.attach(13);                 // Servo terhubung ke pin GPIO 13
  Serial.begin(9600);

  // Memulai koneksi ke jaringan WiFi
  WiFi.begin(ssid, pw);
  Serial.printf("\n\n\n\nConnecting to ");
  Serial.println(ssid);

  // Menunggu status koneksi hingga terhubung
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.printf("\nConnected!\n");

  // Pengaturan routing URL server
  server.on("/", handleRoot);         // Route halaman utama
  server.on("/speed", handleSpeed);   // Route untuk menerima data slider

  // Menjalankan server
  server.begin();
  Serial.println("Server ready");
}

void loop() {
  // Fitur debugging melalui Serial Monitor
  if (Serial.available()) {
    cmd = Serial.readString();
    cmd.trim();
    Serial.println(cmd);

    // Tekan "1" di Serial Monitor untuk cek status jaringan
    if (cmd == "1") {
      Serial.printf("\nWiFi status:\nSSID: ");
      Serial.println(WiFi.SSID());
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
      cmd = "";
    }
  }

  // Standby melayani request dari client/browser
  server.handleClient();
}
