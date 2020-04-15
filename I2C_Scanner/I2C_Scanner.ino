
/*
     Title: I2C scanner
     Author: Saurabh Patil
     e-mail: er.saurabhpatil@gmail.com
     
*/

#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}


void loop()
{
  byte error, address;
  int total_devices;

  Serial.println("Scanning...");

  total_devices = 0;
  for (address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      total_devices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (total_devices == 0)
    Serial.println("No I2C total_devices found\n");
  else
    Serial.println("done\n");

  delay(2000);           // wait 2 seconds for next scan
}
