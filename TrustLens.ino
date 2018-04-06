#include <IRremote.h>
#include <Arduino.h>
/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int ledPin = 7;
int redPin = 2;
int greenPin = 3;
int bluePin = 4;

int RECV_PIN = 11;
bool state = false;

IRrecv irrecv(RECV_PIN);
decode_results results;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    state = !state;
    delay(250);
    irrecv.resume(); // Receive the next value
  }
  if (state)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  if (results.value == 0xFF30CF)
  {
    setColor(255, 0, 0);
  }
  if (results.value == 0xFF18E7)
  {
    setColor(0, 255, 0);
  }
  if (results.value == 0xFF7A85)
  {
    setColor(0, 0, 255);
  }
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}