#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SoftwareSerial ss(3,4);
TinyGPSPlus gps;

void setup() {
ss.begin(9600);
Serial.begin(115200);

float lat1 = latitude();
float lng1 = longitude();

Serial.println(lat1,6);
Serial.println(lng1,6);

delay(10000);

float lat2 = latitude();
float lng2 = longitude();

Serial.println(lat2,6);
Serial.println(lng2,6);

Serial.println("Dist: ");
Serial.println(gps.distanceBetween(lat1,lng1,lat2,lng2));

}

void loop() {
/*if(gps.location.lat()==0){
}
else{
Serial.print("Latitude: ");
Serial.println(gps.location.lat());}
if(gps.location.lng()==0){
}
else{
Serial.print("Longitude: ");
Serial.println(gps.location.lng());}
if(ss.available()>0){
if(gps.encode(ss.read())){
if(gps.location.isValid()){
  Serial.print("Latitude: ");
  Serial.println(gps.location.lat());
  Serial.print("Longitude: ");
  Serial.println(gps.location.lng());
}
}
}*/
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
