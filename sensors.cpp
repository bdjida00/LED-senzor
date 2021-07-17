#include "Sensors.h"

CRGB leds[NUM_LEDS];

SENSORS::SENSORS() {}
SENSORS::~SENSORS() {}

void SENSORS::HCSR04_init()
{
  const int trigPin = 2; // Trigger
  const int echoPin = 3;
  //Serial Port begin
  Serial.begin(9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void SENSORS::LED_init()
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

int SENSORS::readDist()
{
  const int trigPin = 2; // Trigger
  const int echoPin = 3; // Echo
  int buzzer = 6; 
  long duration;
  int cm;

  //Racunanje udaljenosti u cm

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration / 2) / 29.1; // Divide by 29.1 or multiply by 0.0343

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(350);

  //Racunanje boje LED stripa
  if (cm > 150)
  {
    {

    } {
      for (int i = 0; i <= 40; i++)
      {
        {
          leds[i] = CRGB::Green;
          FastLED.show();
        }
      }
    }
  }
  else if (cm < 150 && cm > 70)
  {
    {
      tone(buzzer, 1000);
      delay(100);     // ...for 1 sec
      noTone(buzzer); // Stop sound...
      delay(20);
    }
    {
      for (int i = 0; i <= 40; i++)
      {
        leds[i] = CRGB::Yellow;
        FastLED.show();
      }
    }
  }
  else if (cm <= 60)
  {
    {
      tone(buzzer, 1000);
    }
    {
      for (int i = 0; i <= 40; i++)
      {
        leds[i] = CRGB::Red;
        FastLED.show();
      }
    }
  }
    return cm;
}
