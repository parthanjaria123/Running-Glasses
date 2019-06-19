#include "MPU9250.h"\

MPU9250 IMU(Wire,0x68);
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
azb = IMU.getAccelBiasZ_mss();
azs = IMU.getAccelScaleFactorZ();
IMU.setAccelCalX(axb,axs);
IMU.setAccelCalY(ayb,ays);
IMU.setAccelCalZ(azb,azs);
//print acceleration in all three directions
Serial.print("X: ");
Serial.print(IMU.getAccelX_mss());
Serial.print("        ");
Serial.print("Y: ");
Serial.print(IMU.getAccelY_mss());
Serial.print("        ");
Serial.print("Z: ");
Serial.print(IMU.getAccelZ_mss());
Serial.print("        ");
Serial.println();
}
