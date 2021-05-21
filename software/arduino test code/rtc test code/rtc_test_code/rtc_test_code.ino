#include <RTCZero.h>

RTCZero rtc;
const byte seconds = 0;
const byte minutes = 00;
const byte hours = 00;

int value = 0;
void setup()
{
  Serial.begin(9600);
  rtc.begin(); // initialize RTC
  rtc.setAlarmSeconds(240);
  rtc.enableAlarm(rtc.MATCH_SS);
  rtc.attachInterrupt(alarmMatch);

  Serial.println("start ");
}

void loop()
{

  if (value == 1)
  {
    Serial.println("2 minuten gedaan ");
    value = 0;
  }
}
void alarmMatch()
{
  value = 1;

}
