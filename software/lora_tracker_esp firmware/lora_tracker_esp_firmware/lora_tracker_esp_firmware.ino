/*
  
*/

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLEEddystoneURL.h>
#include <BLEEddystoneTLM.h>
#include <BLEBeacon.h>
#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00) >> 8) + (((x)&0xFF) << 8))

int scanTime = 5;  //In seconds
BLEScan *pBLEScan;

#define SETMAJOR 3840

class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    if (advertisedDevice.haveManufacturerData() == true) {
      std::string strManufacturerData = advertisedDevice.getManufacturerData();

      uint8_t cManufacturerData[100];
      strManufacturerData.copy((char *)cManufacturerData, strManufacturerData.length(), 0);
      BLEBeacon oBeacon = BLEBeacon();
      oBeacon.setData(strManufacturerData);
      uint16_t major = oBeacon.getMajor();
      uint16_t minor = oBeacon.getMinor();
      Serial.println(oBeacon.getMajor());
      Serial.println(oBeacon.getMinor());
      if (SETMAJOR == major) 
      {
        Serial.println("match");
        digitalWrite(LED_BUILTIN, HIGH);
      }
      else 
      {
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("NO match");
        
      }
    }
    return;
  }
};

void setup() 
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();  //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);  //active scan uses more power, but get results faster
  pBLEScan->setInterval(20);
  pBLEScan->setWindow(10);  // less or equal setInterval value
}

void loop() {
  // put your main code here, to run repeatedly:
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  pBLEScan->clearResults();  // delete results fromBLEScan buffer to release memory
  delay(100);
}
