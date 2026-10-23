#include <Wire.h>
#include <SPI.h>
#include "SHC_M9N.cpp" 
#include "Utils.cpp" 

double latitude = 0.0;
double longitude = 0.0;
double altitude = 0.0;
int SIV = 0;


M9N gps = M9N(); 
//Adafruit_BME680 bme(BME_CS); // hardware SPI
//Adafruit_BME680 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);

void setup() {
  Serial.begin(9600);
  Serial.println(F("M9N test"));

  gps.init(); 
}

void loop() {
  latitude = gps.getLatitude();
  longitude = gps.getLongitude();
  altitude = gps.getAltitude();

  Serial.print("Lat: ");
  Serial.print(latitude);
  Serial.print("\n");

  Serial.print("Lon: ");
  Serial.print(longitude);
  Serial.print("\n");

  Serial.print("Alt: ");
  Serial.print(altitude);
  Serial.print("\n");

  delay(100);

}