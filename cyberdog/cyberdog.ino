#include <Servo.h>

Servo frontLeftTopServo;  // create servo object to control a servo
Servo frontRightTopServo;
Servo backLeftTopServo;
Servo backRightTopServo;

Servo frontLeftBottomServo;
Servo frontRightBottomServo;
Servo backLeftBottomServo;
Servo backRightBottomServo;

int state = 0;
int runOnce = 0;
int runOnce2 = 1;

void setup()
{
  Serial.begin(9600);  //start Serial in case we need to print debugging info
  pinMode(2, INPUT_PULLUP);
  pinMode(12, OUTPUT);

  frontLeftTopServo.attach(12);
  frontRightTopServo.attach(13);
  backLeftTopServo.attach(11);
  backRightTopServo.attach(10);

  frontLeftBottomServo.attach(7);
  frontRightBottomServo.attach(6);
  backLeftBottomServo.attach(5);
  backRightBottomServo.attach(2);

  frontLeftTop(25);
  backLeftTop(55);
  frontRightTop(25);
  backRightTop(55);

  frontLeftBottom(0);
  backLeftBottom(0);
  frontRightBottom(0);
  backRightBottom(0);


  delay(3000);
}

int timeBetweenWalk = 0;

void loop()
{
 
 walk1();
 delay(timeBetweenWalk);
 walk2();
 delay(timeBetweenWalk);
 
}

void walk1() {
  backLeftTop(45);
  frontRightTop(45);
  backLeftBottom(-10+30);
  frontRightBottom(-10 + 30);
  delay(100);
  backLeftBottom(-28+30);
  frontRightBottom(-28+30);
  delay(100);
  backLeftTop(75);
  frontRightTop(75);
}

void walk2() {
  backRightTop(45);
  frontLeftTop(45);
  backRightBottom(-10+30);
  frontLeftBottom(-10+30);
  delay(100);
  backRightBottom(-28+30);
  frontLeftBottom(-28+30);
  delay(100);
  backRightTop(75);
  frontLeftTop(75);
}

void bottoms(int frontLeft, int frontRight, int backLeft, int backRight) {
  frontLeftBottom(frontLeft);
  backLeftBottom(backLeft);
  frontRightBottom(frontRight);
  backRightBottom(backRight);
}

void frontLeftTop(int input) {
  frontLeftTopServo.write((input * -1) + 200);
  Serial.println(input + 10);
}

void frontRightTop(int input) {
  frontRightTopServo.write(input - 35);
  //Serial.println((-input) + 150);
}

void backLeftTop(int input) {
  backLeftTopServo.write((-input) + 155);
  //Serial.println((-input) + 155);
}

void backRightTop(int input) {
  backRightTopServo.write((input * 1.09) + 19);
  //Serial.println((input * 1.09) + 19);
}

void frontLeftBottom(int input) {
  frontLeftBottomServo.write(input + 65);
}

void frontRightBottom(int input) {
  frontRightBottomServo.write((input * -0.946) + 108);
}

void backLeftBottom(int input) {
  backLeftBottomServo.write(input + 55);
}

void backRightBottom(int input) {
  backRightBottomServo.write((input * -0.946) + 108);
}
