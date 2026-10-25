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

  Wire1.setSDA(14);
  Wire1.setSCL(15);
  Wire1.begin();
    
  Serial.begin(9600);
  //Serial.println(F("M9N test"));

  while (gps.init() == M9N_ERROR){
    Serial.print("M9N Not Initialized");
  } 
  
}

void loop() {
  gps.prefetchData();

  latitude = gps.getLatitude();
  longitude = gps.getLongitude();
  altitude = gps.getAltitude();

  Serial.print("Lat: ");
  Serial.println(latitude);

  Serial.print("Lon: ");
  Serial.println(longitude);

  Serial.print("Alt: ");
  Serial.println(altitude);

  Serial.print("SIV: ");
  Serial.print(gps.getSIV());
  Serial.println("\n");

  delay(100);

}