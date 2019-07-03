#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

TinyGPSPlus gps;
SoftwareSerial ss(3,4);
Adafruit_SSD1306 display(128,32,&Wire,4);


float mileage=0;
float longitude;
float latitude;

void setup() {
Serial.begin(115200);
ss.begin(9600);
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Allocation failed"));
    for(;;);
}
display.clearDisplay();

longitude = gps.location.lng();
latitude = gps.location.lat();

}

void loop() {
  gps.encode(ss.read());
  display.clearDisplay();
  float newlong = gps.location.lng();
  float newlat = gps.location.lat();

  mileage = mileage + gps.distanceBetween(newlat, newlong, latitude, longitude);
  
  latitude = newlat;
  longitude = newlong;
  display.setCursor(0,0);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  
  display.print(mileage,10);
  display.display();
  delay(1000);
  
 }
