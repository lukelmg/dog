#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

uint8_t servonum = 0;

int state = 1;

void setup() {
  //start serial connection
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(3, INPUT_PULLUP);

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

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
  Serial.println(sensorVal);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (state == 0 && sensorVal == 0) {
    state = 1;
    delay(200);
  } else if (state == 1 && sensorVal == 0) {
    state = 0;
    //Serial.println(state);
    delay(200);
  }

  if (state == 1) {
    digitalWrite(13, LOW);
    pwm.setPWM(1, 0, pulseWidth(0));
    delay(50);
  } else {
    digitalWrite(13, HIGH);
    pwm.setPWM(1, 0, pulseWidth(180));
    delay(50);
  }
}
