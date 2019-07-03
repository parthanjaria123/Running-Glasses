#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define color WHITE

float spd;
float pace;
float mlge;
boolean post;

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
    printPacebyPRINT(0,0);
    printMLGEbyPRINT(0,10);
    printPOSTbyPRINT(0,21);
    
    delay(1000);
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
if(pace>20){
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
display.print("M L G E : here");
display.display();
}
void printPOSTbyPRINT(int xCursor,int yCursor){
display.setCursor(xCursor,yCursor);
display.setTextSize(1);
display.setTextColor(color);
display.print("P O S T : here");
display.display();
  }
