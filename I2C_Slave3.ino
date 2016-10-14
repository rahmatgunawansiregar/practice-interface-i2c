#include <Wire.h>
void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void loop() {
  delay(100);
}
void receiveEvent(int howMany)
{while(Wire.available()) {
  unsigned char dataI2C[2];
  dataI2C[0] = Wire.read();
  dataI2C[1] = Wire.read();
  unsigned int dataADC = word(dataI2C[1],dataI2C[0]);
  Serial.println(dataADC);
}
}
