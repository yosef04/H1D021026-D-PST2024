#include <Arduino.h>
#include <Servo.h>

Servo mservo;

void setup()
{
  mservo.attach(D4);
}

void loop()
{
  mservo.write(90);
  // mservo.write(180);
  // delay(1000);
  // mservo.write(0);
  // delay(1000);
  for (int pos = 0; pos <= 180; pos += 1)
  {
    mservo.write(pos);
    delay(100);
  }
  for (int pos = 180; pos >= 0; pos -= 1)
  {
    mservo.write(pos);
    delay(100);
  }
}