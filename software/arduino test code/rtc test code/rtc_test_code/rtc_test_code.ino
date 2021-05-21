#include <RTCZero.h>

RTCZero rtc;
const byte minutes = 0;

void setup()
{
  Serial.begin(9600);
  rtc.begin(); // initialize RTC
}

void loop()
{
  int timer = rtc.getMinutes() % 2;
  if (timer == 1)
  {
    Serial.println("2 minuuten gepaseerd ");
  }

}
