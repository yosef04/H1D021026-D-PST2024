#include <Arduino.h>

int redLED = D0;
int yelLED = D1;
int greLED = D2;

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(yelLED, OUTPUT);
  pinMode(greLED, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(greLED, LOW);
  digitalWrite(redLED, HIGH);
  digitalWrite(yelLED, HIGH);
  digitalWrite(greLED, HIGH);
  delay(5000);
  digitalWrite(redLED, LOW);
  digitalWrite(greLED, LOW);
  digitalWrite(yelLED, LOW);
  digitalWrite(yelLED, HIGH);
  delay(500);
  digitalWrite(yelLED, LOW);
  digitalWrite(greLED, HIGH);
  delay(500);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}