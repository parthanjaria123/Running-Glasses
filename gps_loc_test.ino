#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 3, TXPin =4;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop() {
  if(ss.available()>0){
    gps.encode(ss.read());
    if(gps.location.isUpdated()){
      Serial.print("Latitude = ");
      Serial.print(gps.location.lat(),6);
      Serial.print("Longitude = ");
      Serial.println(gps.location.lng(),6);
      Serial.print("Speed = ");
      Serial.println(gps.speed.mph());
    }

  }
}
