#include <ESP8266WebServer.h>
#include "controls.h"

const char* ssid = "ssid";
const char* password = "password";

uint8_t LED1 = 12;
bool LED1Status = LOW;
uint8_t LED2 = 13;
bool LED2Status = LOW;

ESP8266WebServer server(80);
void rootpage() {
    server.send(200, "text/html", controlpage);
}
void bothLEDon() {
    digitalWrite(LED1, HIGH);
    LED1Status = HIGH;
    digitalWrite(LED2, HIGH);
    LED2Status = HIGH;
    server.send(200, "text/html", controlpage);
}
void bothLEDoff() {
    digitalWrite(LED1, LOW);
    LED1Status = LOW;
    digitalWrite(LED2, LOW);
    LED2Status = LOW;
    server.send(200, "text/html", controlpage);
}
void LED1Toggle() {
    if (LED1Status == HIGH) {
        digitalWrite(LED1, LOW);
        LED1Status = LOW;
    } else {
        digitalWrite(LED1, HIGH);
        LED1Status = HIGH;
    }
    server.send(200, "text/html", controlpage);
}
void LED2Toggle() {
    if (LED2Status == HIGH) {
        digitalWrite(LED2, LOW);
        LED2Status = LOW;
    } else {
        digitalWrite(LED2, HIGH);
        LED2Status = HIGH;
    }
    server.send(200, "text/html", controlpage);
}
void setup() {
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    Serial.begin(9600);
    Serial.println("Starting");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to:");
    Serial.println(ssid);
    Serial.print("NodeMCU IP:");
    Serial.println(WiFi.localIP());
    server.on("/",rootpage);
    server.on("/bothOn", bothLEDon);
    server.on("/bothOff", bothLEDoff);
    server.on("/l1Toggle", LED1Toggle);
    server.on("/l2Toggle", LED2Toggle);
    server.begin();
}
void loop() {
    server.handleClient();
}