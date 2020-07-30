#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

uint8_t servonum = 0;

void setup() 
{
Serial.begin(9600);
Serial.println("16 channel Servo test!");
pwm.begin();
pwm.setPWMFreq(FREQUENCY);


}
int pulseWidth(int angle)
{
int pulse_wide, analog_value;
pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
Serial.println(analog_value);
return analog_value;
pinMode(12, OUTPUT);



}

void frontLeft(int shoulder, int top, int bottom) {
  pwm.setPWM(15, 0, pulseWidth(shoulder));
  pwm.setPWM(14, 0, pulseWidth(top));
  pwm.setPWM(13, 0, pulseWidth(bottom));
}

int delayBetween = 100;

void loop() {
  
  /*
  frontLeft(60,150,75);
  delay(delayBetween + 145);
  frontLeft(60,120, 0);
  delay(delayBetween);
  frontLeft(60, 90, 37.5);
  delay(delayBetween);
  frontLeft(60, 90, 75);
  delay(delayBetween);
  */
}
