#include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;
SoftwareSerial ss(3,4);
double latini;
double lngini;
double latfin;
double lngfin;

void setup(){
  ss.begin(9600);
  Serial.begin(115200);
  
  latini = getlat();
  lngini = getlng();
  
  Serial.print(latini,6);
  Serial.print(lngini,6);
  
  for(int i=10;i>0;i--){
    Serial.println(i);
    delay(1000);
  }

  lngfin = getlng();
  latfin = getlat();
  
  Serial.println(latfin,6);
  Serial.println(lngfin,6);
  Serial.println(gps.distanceBetween(latini,lngini,latfin,lngfin),6);

  }

void loop()
{
  
}

/*void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}*/
double getlat(){
  boolean check = true;
  while(check){
    if(ss.available()>0){
    if(gps.encode(ss.read())){
    if(gps.location.isValid()){
    Serial.println(gps.location.lat());
    return gps.location.lat();
  }
  }
  }
  }
}

double getlng(){
    boolean check = true;
    while(check){
    if(ss.available()>0){
    if(gps.encode(ss.read())){
    if(gps.location.isValid()){
    return gps.location.lng();
  }
  }
  }
}
}
/*double getlat(){
  if(gps.location.isValid()){
    return gps.location.lat();
  }
}

double getlng(){
  if(gps.location.isValid()){
    return gps.location.lng();
  }
}
void getPosIni(){
   boolean check = true;
   while(check){
  if(ss.available()>0){
    if(gps.encode(ss.read())){
      getlatini();
      getlngini();
      check = false;
    }
  }
  } 
}
void getPos(){
  boolean check = true;
   while(check){
  if(ss.available()>0){
    if(gps.encode(ss.read())){
      getlat();
      getlng();
      check = false;
    }
  }
  }
}

void getAPos(){
  boolean check = true;
  while(check){
    if(ss.available()>0){
      if(gps.encode(ss.read())){
        if(gps.location.isValid()){
          Serial.print(gps.location.lng());
          Serial.println(gps.location.lat());
          check = false;
        }
      }
    }
  }
}*/

boolean x(int k){
  while(true){
    if(k==1){
      return true;
    }
  }
}
