#include "NimBLEDevice.h"
#include <NimBLEAdvertisedDevice.h>
#include "NimBLEBeacon.h"

NimBLEScan* pBLEScan;

BLEUUID keys[2] = { BLEUUID("09c7a7dd-9e55-42d4-a47f-afac8a343b2d"),
                    BLEUUID("eb7239b6-deda-427c-bafd-0d04fd532a5a") };

unsigned long lastSeen = 0;
BLEUUID pairedKey = BLEUUID("00000000-0000-0000-0000-00000000000");

class MyAdvertisedDeviceCallbacks: public NimBLEAdvertisedDeviceCallbacks {
    void onResult(NimBLEAdvertisedDevice* advertisedDevice) {

      if (advertisedDevice->haveManufacturerData() == true)
      {
        std::string strManufacturerData = advertisedDevice->getManufacturerData();

        uint8_t cManufacturerData[100];
        strManufacturerData.copy((char *)cManufacturerData, strManufacturerData.length(), 0);

        if (strManufacturerData.length() == 25 && cManufacturerData[0] == 0x4C && cManufacturerData[1] == 0x00)
        {
          BLEBeacon oBeacon = BLEBeacon();
          oBeacon.setData(strManufacturerData);

          const auto uuid = oBeacon.getProximityUUID();

          // 1 of the 2 know keys?
          auto gevonden = false;
          for (int i = 0; i < sizeof(keys); i++) {
            if (uuid.equals(keys[i])) {
              gevonden = true;
              break;
            }
          }

          if (gevonden)
          {
            if (pairedKey != uuid)
            {
              pairedKey = uuid;
              digitalWrite(LED_BUILTIN, HIGH); // TODO Fire event : found device
            }
            lastSeen = millis();
          }

          // check for removed key
          if (pairedKey != BLEUUID("00000000-0000-0000-0000-00000000000"))
          {
            if ((lastSeen + 2000) < millis())
            {
              digitalWrite(LED_BUILTIN, LOW); // TODO Fire event : lost device
              pairedKey = BLEUUID("00000000-0000-0000-0000-00000000000");
            }
          }
        }
      }
    }
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(115200);
  Serial.println("booting...");

  NimBLEDevice::init("");

  pBLEScan = NimBLEDevice::getScan(); //create new scan
  // Set the callback for when devices are discovered, no duplicates.
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks(), true);
  pBLEScan->setActiveScan(false); // Set active scanning, this will get more data from the advertiser.
  pBLEScan->setInterval(1250); // How often the scan occurs / switches channels; in milliseconds,
  pBLEScan->setWindow(650);  // How long to scan during the interval; in milliseconds.
}

void loop() {
  // If an error occurs that stops the scan, it will be restarted here.
  if (pBLEScan->isScanning() == false) {
    // Start scan with: duration = 0 seconds(forever), no scan end callback, not a continuation of a previous scan.
    Serial.println("Scanning...");
    pBLEScan->start(0, nullptr, false);
  }
}
