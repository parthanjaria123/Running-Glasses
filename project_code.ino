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
ax-=0.84;
ay-=1.05;
Serial.print("X:");
Serial.println(ax);
Serial.print("Y:");
Serial.println(ay);

//prints out velocity

/*delay(100);
float axf = IMU.getAccelX_mss();
float ayf = IMU.getAccelY_mss();
//float azf = IMU.getAccelZ_mss();

float avgaccx = (ax+axf)/2;
float avgaccy = (ay+ayf)/2;
//float avgvelz = (az+azf)/2;

float avgvelx = avgaccx*0.1;
float avgvely = avgaccy*0.1;

velocity = (velocity + sqrt(pow(avgvelx,2)+pow(avgvely,2)));

Serial.println(2.23694*velocity);*/


}
