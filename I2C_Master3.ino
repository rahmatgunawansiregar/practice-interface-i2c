#include <Wire.h>
void setup() {
  Wire.begin();
}
void loop() {
  Wire.beginTransmission(4);
  unsigned dataADC = analogRead(A0);
  unsigned char dataI2C[2];
  dataI2C[0] = lowByte(dataADC);
  dataI2C[1] = highByte(dataADC);
  Wire.write(dataI2C[0]);
  Wire.write(dataI2C[1]);
  Wire.endTransmission();
  delay(500);
}
  
