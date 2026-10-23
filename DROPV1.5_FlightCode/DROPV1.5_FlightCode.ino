#include "Zanshin_BME680.h"
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>

//test

void setup() {
  // put your setup code here, to run once:

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
        if(){

        }//delta alt = positive)
        break;

        case RELEASE:
        if(){

        }
        break;

        default:

    }
}

void stateActions(){
    switch(state){
        case STANDBY:
        if(){

        }//delta alt = positive)
        break;

        case RELEASE:
        if(){

        }
        break;

        default:

    }
} 

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

