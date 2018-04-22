#include <IRremote.h>
#include <Arduino.h>
/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int alarmPin = 11;
int bathroomPin = 10;
int fridgePin = 9;
int loungePin = 8;
int kidPin = 7;

int buttonPin = 12;
int prevPress = 0;

void setup()
{
  pinMode(alarmPin, OUTPUT);
  pinMode(bathroomPin, OUTPUT);
  pinMode(fridgePin, OUTPUT);
  pinMode(loungePin, OUTPUT);
  pinMode(kidPin, OUTPUT);

  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop()
{
  int val = digitalRead(buttonPin); // read the input pin
  if (prevPress != val && val == 1) // User has pressed the button
  {
    Serial.println("Buttom press changed!");

    digitalWrite(alarmPin, HIGH); // Alarm - ON
    delay(1000);
    digitalWrite(bathroomPin, HIGH); // Bathroom - ON
    delay(1000);
    digitalWrite(fridgePin, HIGH); // Fridge - ON
    delay(1000);
    digitalWrite(fridgePin, LOW); // Fridge - OFF
    delay(1000);
    digitalWrite(loungePin, HIGH); // Lounge - ON
    delay(1000);
    digitalWrite(fridgePin, HIGH); // Fridge - ON
    delay(1000);
    digitalWrite(fridgePin, LOW); // Fridge - OFF
    delay(1000);
    digitalWrite(alarmPin, LOW); // Alarm - OFF
    delay(1000);
    digitalWrite(bathroomPin, LOW); // Bathroom - OFF
    delay(1000);
    digitalWrite(kidPin, HIGH); // Kid's Room - ON
    delay(1000);
    digitalWrite(bathroomPin, HIGH); // Bathroom - ON
    delay(1000);
    digitalWrite(bathroomPin, LOW); // Bathroom - OFF
    delay(1000);
    digitalWrite(kidPin, LOW); // Kid's Room - OFF
    delay(1000);
    digitalWrite(fridgePin, HIGH); // Fridge - ON
    delay(1000);
    digitalWrite(fridgePin, LOW); // Fridge - OFF
    delay(1000);
    digitalWrite(bathroomPin, HIGH); // Bathroom - OFF
    delay(1000);
    digitalWrite(bathroomPin, LOW); // Bathroom - OFF
    delay(1000);
    digitalWrite(loungePin, LOW); // Lounge - OFF
  }
  if (val == 0)
  {
    digitalWrite(alarmPin, LOW);
    digitalWrite(bathroomPin, LOW);
    digitalWrite(fridgePin, LOW);
    digitalWrite(loungePin, LOW);
    digitalWrite(kidPin, LOW);
  }
  prevPress = val;
}