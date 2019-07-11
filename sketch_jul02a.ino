#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

SoftwareSerial ss(3,4);
TinyGPSPlus gps;
Adafruit_SSD1306 display(128,32,&Wire,4);

float inilat;
float inilong;
float finallat;
float finallong;

float distance=0;
float altIni;

int buttonPin = 5;

void setup() {
  ss.begin(9600);
  Serial.begin(9600);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  altIni = alt();

  inilong = longitude();
  inilat = latitude();
}

void loop() {

  if(digitalRead(buttonPin)== HIGH){
    finallong = longitude();
    finallat = latitude();

    Serial.println(inilat,10);
    Serial.println(inilong,10);
    Serial.println(finallat,10);
    Serial.println(finallong,10);
    
    while(true){
      
    }
  }

  else{
  
  float lat1 = latitude();
  float lng1 = longitude();

  delay(10000);

  float lat2 = latitude();
  float lng2 = longitude();
  
  float changeInDistance = gps.distanceBetween(lat1,lng1,lat2,lng2);
  distance += changeInDistance;
  float distanceInKM = distance/1000;

  display.clearDisplay();  

  display.setCursor(0,0);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  
  display.print("P A C E: ");

  float runningPace = (1/gps.speed.mph())*60;

  if(runningPace>30){
    display.print(" >30");
  }
  else if(runningPace>10){
    display.print((int) runningPace);
  }
  else{
    display.print(runningPace,2);
  }
    
  display.setCursor(0,10);
  display.print("M L G E: ");
  display.print(distanceInKM,2);

  float altnew = alt();
  float changeInAlt = altnew - altIni;
  
  display.setCursor(0,21);
  display.print(" A L T: ");
  display.print(changeInAlt,2);
  display.display();
  }
}

float latitude(){
  while(true){
    if(ss.available()>0){
      if(gps.encode(ss.read())){
        if(gps.location.isUpdated()){
          return (gps.location.lat());
        }
      }
    }
  }
}

float longitude(){
  while(true){
    if(ss.available()>0){
      if(gps.encode(ss.read())){
        if(gps.location.isUpdated()){
          return (gps.location.lng());
        }
      }
    }
  }
}

float alt(){
  while(true){
    if(ss.available()>0){
      if(gps.encode(ss.read())){
        if(gps.altitude.isUpdated()){
          return (gps.altitude.meters());
        }
      }
    }
  }
}
