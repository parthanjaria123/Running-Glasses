#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define color WHITE

//variables for pace data
float spd;
float pace;
float mlge;

//variables for mileage data
float mileage=0;
float longitude;
float latitude;

//variables for altitude data
float altini;
float deltalt;

SoftwareSerial ss(3,4);
TinyGPSPlus gps;

Adafruit_SSD1306 display(128,32,&Wire,4);

void setup()
{
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

void loop()
{
 //if software serial is working
 while(ss.available()>0){
  
  //read the data
  gps.encode(ss.read());
  
  //check if location is being recieved
  if(gps.location.isUpdated()){
    Serial.print("Latitude = ");
    Serial.print(gps.location.lat(),6);
    Serial.print("Longitude = ");
    Serial.println(gps.location.lng(),6);
    Serial.print("Speed = ");
    Serial.println(gps.speed.mph(),6);
    spd = gps.speed.mph();
    pace = ((1/spd)*60);
    Serial.println(pace,3);
    display.clearDisplay();

    float newlong = gps.location.lng();
    float newlat = gps.location.lat();

    Serial.print("Mileage: ");
    mileage += gps.distanceBetween(newlat, newlong, latitude, longitude)/1000;
    Serial.println(mileage);
    
    latitude = newlat;
    longitude = newlong;

    Serial.print("Change in altitude (m): ");
    float newalt = gps.altitude.meters();
    deltalt = newalt - altini;
    Serial.println(deltalt);
    
    printPacebyPRINT(0,0);
    printMLGEbyPRINT(0,10);
    printPOSTbyPRINT(0,21);
    
    delay(2000);
    
  }
 }
}
void printPacebyPRINT(int xCursor, int yCursor){
display.setCursor(xCursor,yCursor);
display.setTextSize(1);
display.setTextColor(color);
display.print("P A C E : ");
if (pace>30){
  display.print(">30 ");
}
else if(pace>20){
  display.print((int) pace);
}
else if(pace>10){
  display.print(pace,1);
}
else{
  display.print(pace,2);
}
display.display();

}
void printMLGEbyPRINT(int xCursor, int yCursor){
display.setCursor(xCursor,yCursor);
display.setTextSize(1);
display.setTextColor(color);
display.print("M L G E : ");
display.print(mileage, 3);
display.display();
}
void printPOSTbyPRINT(int xCursor,int yCursor){
display.setCursor(xCursor,yCursor);
display.setTextSize(1);
display.setTextColor(color);
display.print(" A L T: ");
display.print(deltalt);
display.display();
  }
