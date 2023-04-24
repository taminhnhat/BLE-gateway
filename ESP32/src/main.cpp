#include <Arduino.h>
#include <BLEDevice.h>
// #include <BLEUtils.h>
// #include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <WiFi.h>
#include <HTTPClient.h>
#define WIFI_SSID "fahasa"
#define WIFI_PASSWORD "fahasa@387"
#define REQUEST_URL "http://192.168.1.42:3003/ble-scan/"
int scanTime = 5; // In seconds
BLEScan *pBLEScan;
class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks
{
  void onResult(BLEAdvertisedDevice advertisedDevice)
  {
    Serial.printf("%s \n", advertisedDevice.toString().c_str());
    if (WiFi.status() == WL_CONNECTED)
    {
      HTTPClient http;
      http.begin(REQUEST_URL);
      // http.addHeader("Content-Type", "text/plain");
      // int httpCode = http.POST(advertisedDevice.toString().c_str());
      http.addHeader("Content-Type", "application/json");
      std::string msg = "{\"message\":\"ble result\"}";
      // std:sprintf()
      int httpCode = http.POST(msg);
      // http.addHeader("Content-Type", "application/json");
      // int httpCode = http.GET();

      String payload = "{}";

      if (httpCode > 0)
      {
        Serial.print("HTTP Response code: ");
        Serial.println(httpCode);
        payload = http.getString();
      }
      else
      {
        Serial.print("Error code: ");
        Serial.println(httpCode);
      }
      Serial.println(httpCode);
      http.end();
    }
  }
};
void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  // setup wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // setup bluetooth
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();                                           // create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks()); // Init Callback Function
  pBLEScan->setActiveScan(true);                                             // active scan uses more power, but get results faster
  pBLEScan->setInterval(100);                                                // set Scan interval
  pBLEScan->setWindow(99);                                                   // less or equal setInterval value
}
void loop()
{
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  pBLEScan->clearResults(); // delete results fromBLEScan buffer to release memory
}