#include <Arduino.h>
#include <LowPower.h>
#include "main.h"
#include "Sensors.h"
#include "Radio_nRF.h"

SENSORS sensor;
RADIO radioNRF;

SensorData dataToSend;
StateType state = READ_SERIAL;

void setup()
{
  Serial.begin(9600);
  sensor.HCSR04_init();
  sensor.LED_init();
  radioNRF.nRF_init();
}

void loop()
{

  switch (state)
  {
  case READ_SERIAL:

    state = READ_SENSORS;
    break;
  case READ_SENSORS:
    dataToSend.dst = sensor.readDist();

    state = RADIO_TX;
    break;
  case RADIO_TX:
    radioNRF.RF_send(dataToSend);

    state = SLEEP;
    break;
  case SLEEP:

    /*delay(50);
    LowPower.powerDown(SLEEP_250MS, ADC_OFF, BOD_OFF);
    delay(50);*/
    state = READ_SERIAL;
    break;
  default:
    break;
  }
}
