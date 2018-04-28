#include <IRremote.h>
#include <Arduino.h>

// Constants used by TrustLens
const int alarmPin = 11;
const int bathroomPin = 10;
const int fridgePin = 9;
const int loungePin = 8;
const int kidPin = 7;
const int doorPin = 6;

// Length of delay between each
const int waitTime = 4000;

void setup()
{
  // First initialize output on all pins
  pinMode(alarmPin, OUTPUT);
  pinMode(bathroomPin, OUTPUT);
  pinMode(fridgePin, OUTPUT);
  pinMode(loungePin, OUTPUT);
  pinMode(kidPin, OUTPUT);

  // Initialize serial output for debugging purposes
  Serial.begin(9600);

  // Make sure that all leds are OFF when we start
  digitalWrite(alarmPin, LOW);
  digitalWrite(bathroomPin, LOW);
  digitalWrite(fridgePin, LOW);
  digitalWrite(loungePin, LOW);
  digitalWrite(kidPin, LOW);

  // Start the sequence
  turnOn(alarmPin);
  turnOn(bathroomPin);
  turnOn(fridgePin);
  turnOff(fridgePin);
  turnOn(loungePin);
  turnOn(fridgePin);
  turnOff(fridgePin);
  turnOff(alarmPin);
  turnOff(bathroomPin);
  turnOn(kidPin);
  turnOn(bathroomPin);
  turnOff(bathroomPin);
  turnOff(kidPin);
  turnOn(fridgePin);
  turnOff(fridgePin);
  turnOn(doorPin);
  turnOff(doorPin);
  turnOn(bathroomPin);
  turnOff(bathroomPin);
  turnOff(loungePin);
  turnOn(doorPin);
}

void loop()
{
}
void turnOn(int pin)
{
  digitalWrite(pin, HIGH);
  delay(waitTime);
}
void turnOff(int pin)
{
  digitalWrite(pin, LOW);
  delay(waitTime);
}