#include "FastLED.h"
#define NUM_LEDS 120
#define DATA_PIN 13
#define BRIGHTNESS 255
#define chipset WS2812B

CRGB leds[NUM_LEDS];

#define echoPin 32 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 33 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int x=0;


void setup()
{
  delay(2000);
  FastLED.addLeds<chipset, DATA_PIN, RGB>(leds, NUM_LEDS);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop()
{
  int dis = calculateDistance();
  int lightcon = dis*6;
  leds[lightcon] = CRGB::Red;
  FastLED.show();
}

int calculateDistance()
{
    // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  //Serial.println(distance);
  //Serial.flush();

  return distance;
}
