#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define C WHITE

Adafruit_SSD1306 display(128,32,&Wire,4);

void setup() {
Serial.begin(9600);
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Allocation failed"));
    for(;;);
  }
display.clearDisplay();
printPacebyPRINT(0,0);
printMLGEbyPRINT(0,10);
printPOSTbyPRINT(0,21);
}

void loop() {

}
void printVelocitybyPIXEL(){
  
  for(int i=0;i<=6;i++){
    display.drawPixel(i,i,C);
  }
  int k=5;
  for(int i=7;i<=12;i++){
    display.drawPixel(i,k,C);
    k--;
  }
  for(int i=15;i<=26;i++){
    display.drawPixel(i,0,C);
  }
  for(int i=0;i<=6;i++){
    display.drawPixel(15,i,C);
  }
  for(int i=15;i<=26;i++){
    display.drawPixel(i,3,C);
    display.drawPixel(i,6,C);
  }
  for(int i=0;i<=6;i++){
    display.drawPixel(29,i,C);
  }
  for(int i=30;i<=37;i++){
    display.drawPixel(i,6,C);
  }
  display.drawPixel(40,2,C);
  display.drawPixel(40,4,C);
  display.display();
  delay(2000);
 display.clearDisplay();
}
void printPacebyPIXEL(){
  for(int i=0;i<=7;i++){
    display.drawPixel(0,i,C);
  }
  for(int i=1;i<=8;i++){
    display.drawPixel(i,0,C);
    display.drawPixel(i,4,C);
  }
  for(int i=0;i<=4;i++){
    display.drawPixel(8,i,C);
  }
  int k = 9;
  for(int i=7;i>=0;i--){
    display.drawPixel(k,i,C);
    k++;
  }
  k=17;
  for(int i=0;i<=7;i++){
    display.drawPixel(k,i,C);
    k++;
  }
  for(int i=14;i<=19;i++){
    display.drawPixel(i,4,C);
  }
  display.display();
}
void printPacebyPRINT(int xCursor, int yCursor){
display.setCursor(xCursor,yCursor);
display.setTextSize(1);
display.setTextColor(C);
display.print("P A C E :");
display.display();
}
void printMLGEbyPRINT(int xCursor, int yCursor){
display.setCursor(xCursor,yCursor);
display.setTextSize(1);
display.setTextColor(C);
display.print("M L G E :");
display.display();
}
void printPOSTbyPRINT(int xCursor,int yCursor){
display.setCursor(xCursor,yCursor);
display.setTextSize(1);
display.setTextColor(C);
display.print("P O S T :");
display.display();
}
