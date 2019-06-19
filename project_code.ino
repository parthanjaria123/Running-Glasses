#include "MPU9250.h"\

MPU9250 IMU(Wire,0x68);
float velocity = 0;

void setup() {
Serial.begin(115200);
int status;
status = IMU.begin();
//Serial.print(status);
//Serial.println();
IMU.calibrateAccel();
}
void loop() {

IMU.readSensor();
/*int status = IMU.calibrateAccel();*/
float axb,axs,ayb,ays,azb,azs;
axb = IMU.getAccelBiasX_mss();
axs = IMU.getAccelScaleFactorX();
ayb = IMU.getAccelBiasY_mss();
ays = IMU.getAccelScaleFactorY();
//azb = IMU.getAccelBiasZ_mss();
//azs = IMU.getAccelScaleFactorZ();
IMU.setAccelCalX(axb,axs);
IMU.setAccelCalY(ayb,ays);
//IMU.setAccelCalZ(azb,azs);
//print acceleration in all three directions
float ax = IMU.getAccelX_mss();
float ay = IMU.getAccelY_mss();
//float az = IMU.getAccelZ_mss();
//prints out acceleration
ax-=0.67;//0.75
ay-=1.13;//1.05
/*Serial.print("X:");
Serial.println(ax);
Serial.print("Y:");
Serial.println(ay);*/
delay(0.5);

//prints out velocity

float axf = IMU.getAccelX_mss();
float ayf = IMU.getAccelY_mss();
axf-=0.75;
ayf-=1.05;

float avgaccx = (ax+axf)/2;
float avgaccy = (ay+ayf)/2;

if(avgaccx<0.10&&avgaccx>-0.10){
  avgaccx=0;
}
if(avgaccy<0.10&&avgaccy>-0.10){
  avgaccy=0;
}

float avgvelx = avgaccx*0.0005;
float avgvely = avgaccy*0.0005;

float change = sqrt(pow(avgvelx,2)+pow(avgvely,2));

if(avgaccx<0){
  velocity = velocity - change;
}

else{
velocity = velocity + change;
}
Serial.println((2.23694*velocity));


}
