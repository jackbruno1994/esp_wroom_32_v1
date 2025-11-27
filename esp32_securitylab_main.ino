// Main ESP32 Security Lab Firmware (premium) v1.0
// Full-feature demo; expand attacks/file mgmt later as needed

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <ArduinoJson.h>
#define OLED_RESET -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* admin_user = "jackbruno1994";
const char* admin_pass = "Bicky@_900";
const char* apSSID = "ESP32_SecurityLab";
const char* apPASS = "SecurityLab@123";
AsyncWebServer server(80);
String session_id = "";
String eventLog = "[\n";
unsigned long uptime_start;
int nscan = 0;

void logEvent(String evt) {
  String ts = String(millis()/1000);
  eventLog += "{\"ts\":" + ts + 