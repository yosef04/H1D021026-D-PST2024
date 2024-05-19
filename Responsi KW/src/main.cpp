#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

int echoPin = D0;
int trigPin = D1;

long duration;
int distance;

int redLed = D7;
int greenLed = D8;

Servo servo;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D5;
int SCL_pin = D6;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);

  servo.attach(D4);

  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;

  Serial.println("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm");

  if (distance <= 10)
  {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    servo.write(180);
  }
  else
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    servo.write(0);
  }

  delay(1000);
}