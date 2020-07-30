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

  frontLeftTop(35);
  backLeftTop(55);
  frontRightTop(35);
  backRightTop(55);

  frontLeftBottom(-10);
  backLeftBottom(-5);
  frontRightBottom(-10);
  backRightBottom(-5);

  delay(1000);
}

int timeBetweenWalk = 0;

void loop()
{
/*
  frontLeftTop(45);
  backLeftTop(45);
  frontRightTop(45);
  backRightTop(45);

  frontLeftBottom(-10);
  backLeftBottom(-10);
  frontRightBottom(-10);
  backRightBottom(-10);

  delay(1000);
*/
  translateUpDown(100);

  delay(10000);
  
}


void translateUpDown(int z3) {
  
  float thighLength = 110;
  float shinLength = 114;
  float testShin = 114;

  //acb solving for A
   float shoulderAngle1a = sq(shinLength) + sq(z3) - sq(thighLength);
   float shoulderAngle1b = 2*z3*shinLength;
   float shoulderAngle1c = shoulderAngle1a / shoulderAngle1b;
   float shoulderAngle1 = acos(shoulderAngle1c);     // radians

  //sovling for C
   float kneeAngle1a = sq(thighLength) + sq(shinLength) - sq(z3);
   float kneeAngle1b = 2 * thighLength * shinLength;
   float kneeAngle1c = kneeAngle1a / kneeAngle1b;
   float kneeAngle = acos(kneeAngle1c);     // radians

    //calc degrees from angles
   float shoulderAngle1Degrees = shoulderAngle1 * (180/PI);    // degrees
   float kneeAngleDegrees = kneeAngle * (180/PI);              // degrees

  Serial.print("shoulder = ");
  Serial.print(shoulderAngle1Degrees, 5);
  Serial.print("  knee = ");
  Serial.println(kneeAngleDegrees, 5);

  frontLeftTop(90-(shoulderAngle1Degrees+1));
  frontLeftBottom(kneeAngleDegrees-100);
}






void walkFrontLeft() {
  frontLeftBottom(-40);
  delay(150);
  frontLeftTop(90);
  delay(50);
  frontLeftBottom(0);
  delay(100);
  frontLeftTop(25);
}

void walkFrontRight() {
  frontRightBottom(-40);
  delay(150);
  frontRightTop(90);
  delay(50);
  frontRightBottom(0);
  delay(100);
  frontRightTop(25);
}

void walkBackLeft() {
  backLeftBottom(-40);
  delay(150);
  backLeftTop(90);
  delay(50);
  backLeftBottom(0);
  delay(100);
  backLeftTop(25);
}

void walkBackRight() {
  backRightBottom(-40);
  delay(150);
  backRightTop(90);
  delay(50);
  backRightBottom(0);
  delay(100);
  backRightTop(25);
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
