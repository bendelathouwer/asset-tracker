
#include <RTCZero.h>

/* Create an rtc object */
RTCZero rtc;
const byte minutes = 0;




void setup() {

  Serial.begin(9600);
  rtc.begin(); // initialize RTC
  // Set the time
  rtc.setMinutes(minutes);


}

void loop() {
  if (rtc.getMinutes() % 2)
  {
    Serial.println("2 min gepaseerd");
  }
 
}
