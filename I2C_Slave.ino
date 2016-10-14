#include <Wire.h>
void setup()
{
  Wire.begin(2);
  Wire.onRequest(requestEvent);
}
void loop()
{
  delay(100);
}
void requestEvent()
{
  unsigned int dataADC = analogRead(A0);
  unsigned char dataI2C[2];
  dataI2C[0] = lowByte(dataADC);
  dataI2C[1] = highByte(dataADC);
  Wire.write(dataI2C,2);
}
