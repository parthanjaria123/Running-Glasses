#include "MPU9250.h"

MPU9250 IMU(Wire,0x68);
float velocity = 0;
void setup() {
Serial.begin(115200);
int status = IMU.begin();
IMU.calibrateAccel();
}

void loop() {
IMU.readSensor();
float ab = IMU.getAccelBiasX_mss();
float as = IMU.getAccelScaleFactorX();

IMU.setAccelCalX(ab,as);
float a = IMU.getAccelX_mss();
a-=0.67;
delay(0.5);

float aFinal = IMU.getAccelX_mss();
aFinal-=0.67;

float avgacc = (a+aFinal)/2;
if(avgacc<0.10&&avgacc>-0.10){
  avgacc=0;
}

float avgvel = avgacc*0.0005;

velocity = velocity+avgvel;

Serial.println(abs(2.23694*velocity));

}
