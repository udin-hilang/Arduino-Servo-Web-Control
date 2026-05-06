#include <ESP32Servo.h>
#include <WiFi.h>
#include <WebServer.h>
#include "sliderPage1.h"

String cmd = "", ssid = "realme 12+ 5G", pw = "";  // WiFi credential

WebServer server(80);              // Web server di port 80

Servo myServo;

void handleRoot() {
  server.send(200, "text/html", html); // kirim halaman ke browser
}

void handleSpeed() {
  String value = server.arg("value");
  int speed = value.toInt();
  myServo.write(speed);
}


void setup() {
  myServo.attach(13);
  Serial.begin(9600);

  // Koneksi ke WiFi
  WiFi.begin(ssid, pw);
  Serial.printf("\n\n\n\nConnecting to ");
  Serial.println(ssid);

  // Tunggu sampai terhubung
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.printf("\nConnected!\n");
  // Routing web server
  server.on("/", handleRoot);
  server.on("/speed", handleSpeed);

  // Start server
  server.begin();
  Serial.println("Server ready");
}

void loop() {
  // Input debug via Serial Monitor
  if (Serial.available()) {
    cmd = Serial.readString();
    cmd.trim();
    Serial.println(cmd);

    // Command "1" untuk cek status WiFi
    if (cmd == "1") {
      Serial.printf("\nWiFi status:\nSSID: ");
      Serial.println(WiFi.SSID());
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
      cmd = "";
    }
  }

  // Handle client request dari browser
  server.handleClient();
}