#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include<MPU6050.h>

Adafruit_MPU6050 mpu;
//MPU6050 mp;
void setup(void) {
  Serial.begin(115200);
//  Wire.begin();
//  mp.initialize();
  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void loop() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.print(a.acceleration.z);
  Serial.print(", ");
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print(g.gyro.y);
  Serial.print(",");
  Serial.print(g.gyro.z);
  Serial.println("");

//int16_t ax, ay, az;
//  int16_t gx, gy, gz;
//
//  mp.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
//
//  Serial.print("Accel: ");
//  Serial.print(ax);
//  Serial.print(", ");
//  Serial.print(ay);
//  Serial.print(", ");
//  Serial.println(az);
//
//  Serial.print("Gyro: ");
//  Serial.print(gx);
//  Serial.print(", ");
//  Serial.print(gy);
//  Serial.print(", ");
//  Serial.println(gz);

//  delay(1000);

  delay(10);
}
