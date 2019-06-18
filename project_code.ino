#include "MPU9250.h"\

MPU9250 IMU(Wire,0x68);
void setup() {
Serial.begin(115200);
int status;
status = IMU.begin();
Serial.print(status);
Serial.println();
}
void loop() {
IMU.readSensor();
//print acceleration in all three directions
Serial.print("X: ");
Serial.print(IMU.getAccelX_mss(),6);
Serial.print("        ");
Serial.print("Y: ");
Serial.print(IMU.getAccelY_mss(),6);
Serial.print("        ");
Serial.print("Z: ");
Serial.print(IMU.getAccelZ_mss(),6);
Serial.print("        ");
Serial.println();
delay(1000);

/*//print the gyroscope value for the degree of turn in the respective axes
Serial.print("GX: ");
Serial.print(IMU.getGyroX_rads(),6);
Serial.print("       ");
Serial.print("GY: ");
Serial.print(IMU.getGyroY_rads(),6);
Serial.print("       ");
Serial.print("GZ: ");
Serial.print(IMU.getGyroZ_rads(),6);
Serial.print("       ");
Serial.println();
delay(1000);

Serial.print(IMU.getTemperature_C(),6);
Serial.println();
delay(1000);*/
}
