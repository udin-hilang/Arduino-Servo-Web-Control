# ESP32 Web-Based Continuous Servo Speed Control

This repository features a real-time speed and direction controller for a **360-degree Continuous Rotation Servo** using an **ESP32** web server. Instead of controlling position, this system manages the rotation velocity via a web-based slider.

## 🚀 Features
- **Speed & Direction Control:** Seamlessly switch between clockwise, counter-clockwise, and stop states.
- **Web Interface:** Accessible via any device on the same local network.
- **Real-time Interaction:** Uses asynchronous HTTP requests to update motor speed instantly.
- **Serial Diagnostics:** Real-time network status monitoring through the Serial interface.

## 🛠️ Hardware Requirements
- **Microcontroller:** ESP32 (DevKit V1).
- **Actuator:** 360-degree Continuous Rotation Servo (e.g., MG995 360 or SG90 360).
- **Power:** 5V External Power supply (common ground with ESP32).

## 🎮 Servo Logic (360° Rotation)
The slider values are interpreted as follows:
- **Value 90:** Servo Stops.
- **Value > 90 (up to 180):** Rotates in one direction (Speed increases as value rises).
- **Value < 90 (down to 0):** Rotates in the opposite direction (Speed increases as value drops).

## 🔌 Pin Mapping
| Component | ESP32 GPIO |
| :--- | :--- |
| **Servo PWM Signal** | GPIO 13 |
| **VCC** | Vin / 5V |
| **GND** | GND |

## 📖 How to Setup
1. Clone the repository.
2. Open in **Arduino IDE**.
3. Update `ssid` and `pw` in the `.ino` file with your credentials.
4. Upload to ESP32.
5. Open the **Serial Monitor** (9600 baud) to get the IP Address.
6. Open the IP in your browser and use the slider to control the rotation.

## 📂 Project Structure
- `main.ino`: Server logic and WiFi management.
- `sliderPage.h`: HTML/JavaScript interface for the slider control.

---
*Developed as part of my learning progress in Electrical Engineering and Embedded Systems.*
