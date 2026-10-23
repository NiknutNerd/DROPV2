#include <Arduino.h>

#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include "SHC_M9N.cpp"

//test
M9N gps = M9N();

void setup() {
  // put your setup code here, to run once:
  gps.init();



}

const int LED = 1; //temp


enum FlightState {
    STANDBY = 0,
    RELEASE = 1,
};

FlightState state = STANDBY;

void updateFlightState(){
    switch(state){
        case STANDBY:
        //if(){

        //}//delta alt = positive)
        break;

        case RELEASE:
        //if(){

        //}
        break;

        default:

    }
}

void stateActions(){
    switch(state){
        case STANDBY:
        //if(){

        //}//delta alt = positive)
        break;

        case RELEASE:
        //if(){

        //}
        break;

        default:

    }
} 

int main()
{
  gps.prefetchData();
  updateFlightState();
  stateActions();

}
