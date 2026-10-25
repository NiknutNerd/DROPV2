#include <Arduino.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include <Wire.h>
#include <SPI.h>
#include "SHC_M9N.cpp" 
#include "Utils.cpp" 
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include "Servo.h"

// #define BME_SCK 13
// #define BME_MISO 15
// #define BME_MOSI 14
// #define BME_CS 10

#define SEALEVELPRESSURE_HPA (1026.75)

const int SERVO_PIN = 20; //physical 26

// double latitude = 0.0;
// double longitude = 0.0;
// double gpsAlt = 0.0;
// int SIV = 0;

double bmeAlt = 0.0;

const double RELEASE_ALT = 650.0;
const double GROUND_ALT = 244.0;

//M9N gps = M9N();
Adafruit_BME680 bme; 
Servo MG995; 

void setup() {
  // put your setup code here, to run once:

  //Serial.begin(9600);
  delay(2000);

  pinMode(25, OUTPUT);
  digitalWrite(25, HIGH);

  //MG995.attach(SERVO_PIN);

  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();
    
  
  //Serial.println(F("M9N test"));

  // while (gps.init() == M9N_ERROR){
  //   Serial.print("M9N Not Initialized");
  // }

  bme=Adafruit_BME680(&Wire);

  while (!bme.begin()) {
    //Serial.println(F("Could not find a valid BME680 sensor, check wiring!"));
    delay(500);
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms

  bme.readAltitude(SEALEVELPRESSURE_HPA);
  delay(200);
  bme.readAltitude(SEALEVELPRESSURE_HPA);
  delay(200);
  bme.readAltitude(SEALEVELPRESSURE_HPA);
  delay(200);
  bme.readAltitude(SEALEVELPRESSURE_HPA);
  delay(200);

  // MG995.write(179);
  // delay(500);
  // MG995.write(0);
  // delay(3000);
}

enum FlightState {
    STANDBY = 0,
    RELEASE = 1,
};

FlightState state = STANDBY;

void stateMachine(){
    switch(state){
        case STANDBY:
        //do nothing
        if(bmeAlt >= (RELEASE_ALT + GROUND_ALT)){
          MG995.attach(SERVO_PIN);
          delay(500);
          MG995.write(179);
          delay(5000);
          MG995.write(0);
          delay(5000);
          MG995.write(179);
          delay(5000);
          MG995.write(0);
          delay(5000);
          state = RELEASE;
        }
        break;

        case RELEASE:
        MG995.write(179);
        delay(5000);
        MG995.write(0);
        delay(5000);
        MG995.write(179);
        delay(5000);
        MG995.write(0);
        delay(5000);
        
        break;

      }  
}

void loop()
{
  // Serial.print("entering loop");
  // gps.prefetchData();
  bme.performReading();

  bmeAlt = bme.readAltitude(SEALEVELPRESSURE_HPA);

  // latitude = gps.getLatitude();
  // longitude = gps.getLongitude();
  // gpsAlt = gps.getAltitude();

  // Serial.print(bmeAlt);
  // Serial.print("\n");

  stateMachine();

  delay(100);

}
