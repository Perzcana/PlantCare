#include <DHT.h>
#include <Stepper.h>
#include "config.h"
//#define DEBUG
static byte state;
static volatile byte data=0;

DHT dht(DHTPIN, DHTTYPE);
Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);

void setup(){
    #ifdef DEBUG
        debug_init();
    #endif
    sensor_init();
    motor_init();
    energy_init();
    #ifdef DEBUG
        Serial.print("step:");
        Serial.print(LIFT_STEP);
        Serial.print("  round:");
        Serial.println(FEED_ROUND);
        Serial.println("**********************");
    #endif
}

void loop(){
    if(isReadyWake()){
        update_sensor();
        if(state){ motor_process(); }
        #ifdef DEBUG
            debug_process();
        #endif
        Sleep_avr();
    }
    else {
        Sleep_avr();
    }
}
