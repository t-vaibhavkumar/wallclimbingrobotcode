#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h> // Include the ESP32 Servo library

const char* ssid = "";
const char* password = "";

WebServer server(80);

const int servoPin = 13; // Adjust pin number as needed
const int resolution = 8;
const int freq = 50; // Servo PWM frequency (Hz)

Servo myServo;

void setup() {
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/cleaning", HTTP_GET, []() {
    cleaning();
    server.send(200, "text/plain", "Cleaning");
  });

  server.begin();
  Serial.println("HTTP server started");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Configure LEDC PWM
  ledcSetup(0, freq, resolution); // Channel 0
  ledcAttachPin(servoPin, 0); // Attach servo to channel 0


  myServo.attach(servoPin);

}

void loop() {
  server.handleClient();
}

void cleaning() {
  // Move the servo to 180 degrees
  Serial.println("performing cleaning");
  myServo.write(180); // Full duty cycle (180 degrees)
  delay(1000); // Adjust delay as needed

  // Move the servo back to 0 degrees
  myServo.write(0);// Zero duty cycle (0 degrees)
  delay(1000); // Adjust delay as needed
  Serial.println("cleaning performed");

}
