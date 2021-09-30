#include "EEPROM.h"

// the current address in the EEPROM
int addr = 0;

#define EEPROM_SIZE 1  // number of values between 0-254

void setup()
{
  Serial.begin(115200);
  Serial.println("start...");
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(10000);
  }
  Serial.println(" bytes READ from Flash . Values are:");
  int value = (byte(EEPROM.read(addr))*20);
  Serial.println(value);
  delay(7000);

}

void loop()
{
  // device maximal CO2 ppm (5000) value by 20
  int val = byte(5000/20);
  // write the value to the appropriate byte of the EEPROM.
  // these values will remain there when the board is
  // turned off.
  EEPROM.write(addr, val);
  Serial.println(val); Serial.println("-----------");

  EEPROM.commit();
  Serial.print("EEPROM SIZE:");
  Serial.println(EEPROM_SIZE);
  Serial.println(" bytes WRITTEN on Flash . Values are:");
  for (int i = 0; i <= EEPROM_SIZE; i++)
  {
    Serial.print(byte(EEPROM.read(addr))); Serial.print(" ");
  }
  Serial.println(); Serial.println("----------------------------------");


  delay(7000);
}
