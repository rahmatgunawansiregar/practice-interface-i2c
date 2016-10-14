#include <Wire.h>
void setup()
{
  Wire.begin();
  Serial.begin(9600);
}
void loop()
{
  Wire.requestFrom(2,2);
  while(Wire.available())
  {
    unsigned char dataI2C[2];
    dataI2C[0] = Wire.read();
    dataI2C[1] = Wire.read();
    unsigned int dataADC = word(dataI2C[1],dataI2C[0]);
    Serial.println(dataADC);
  }
  delay(500);
}
