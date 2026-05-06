#include <ESP32Servo.h>
#include <WiFi.h>
#include <WebServer.h>
#include "webPage.h"

// WiFi credentials (kosongkan pw jika open network)
String cmd = "", ssid = "realme 12+ 5G", pw = "";  

WebServer server(80); // Inisialisasi Web Server pada port 80
Servo myServo;

// Render halaman utama dari file webPage.h
void handleRoot() {
  server.send(200, "text/html", html); 
}

// Handler untuk menggerakkan servo ke kanan
void handleRight() {
  server.sendHeader("Location", "/");
  server.send(303);
  myServo.write(100); // Set sudut servo ke 100 derajat
}

// Handler untuk posisi netral/berhenti
void handleStop() {
  server.sendHeader("Location", "/");
  server.send(303);
  myServo.write(90);  // Set sudut servo ke posisi tengah (90 derajat)
}

// Handler untuk menggerakkan servo ke kiri
void handleLeft() {
  server.sendHeader("Location", "/");
  server.send(303);
  myServo.write(80);  // Set sudut servo ke 80 derajat
}

void setup() {
  myServo.attach(13); // Hubungkan sinyal servo ke pin GPIO 13
  Serial.begin(9600);

  // Proses koneksi ke WiFi
  WiFi.begin(ssid, pw);
  Serial.printf("\nConnecting to %s", ssid.c_str());

  // Loop tunggu sampai WiFi terkoneksi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.printf("\nConnected! IP Address: ");
  Serial.println(WiFi.localIP());

  // Routing URL ke fungsi handler masing-masing
  server.on("/", handleRoot);
  server.on("/Stop", handleStop);
  server.on("/Right", handleRight);
  server.on("/Left", handleLeft);

  server.begin(); // Jalankan server
  Serial.println("HTTP Server started");
}

void loop() {
  // Fitur debugging via Serial Monitor
  if (Serial.available()) {
    cmd = Serial.readString();
    cmd.trim();
    Serial.println("Command received: " + cmd);

    // Kirim angka '1' di Serial Monitor untuk cek info koneksi
    if (cmd == "1") {
      Serial.printf("\n--- WiFi Info ---\nSSID: %s\nIP: ", WiFi.SSID().c_str());
      Serial.println(WiFi.localIP());
      cmd = "";
    }
  }

  // Tetap standby dengerin request dari client (browser)
  server.handleClient();
}
