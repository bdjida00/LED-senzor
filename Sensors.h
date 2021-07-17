#ifndef Sensors_h
#define Sensors_h

#include <Arduino.h>

#include <FastLED.h>
#define LED_PIN 7
#define NUM_LEDS 40
#define LED_TYPE WS2812

class SENSORS
{
public:
        SENSORS();
        ~SENSORS();
        void HCSR04_init();
        void LED_init();
        int readDist();        
};

#endif