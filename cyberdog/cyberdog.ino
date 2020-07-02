#include <Servo.h>

Servo frontLeftTop;  // create servo object to control a servo
Servo frontRightTop;
Servo backLeftTop;
Servo backRightTop;

Servo frontLeftBottom;
Servo frontRightBottom;
Servo backLeftBottom;
Servo backRightBottom;

int state = 0;
int runOnce = 0;
int runOnce2 = 1;

void setup()
{
  Serial.begin(115200);  //start Serial in case we need to print debugging info
  pinMode(2, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  
  frontLeftTop.attach(12);
  frontRightTop.attach(13);
  backLeftTop.attach(11);
  backRightTop.attach(10);

  frontLeftBottom.attach(7);
  frontRightBottom.attach(6);
  backLeftBottom.attach(5);
  backRightBottom.attach(2);

  ////////////////////////

  frontLeftTop.write(160);
  backLeftTop.write(160);
  
  frontRightTop.write(0);
  backRightTop.write(0);

  ///////////////////////////
  
  frontLeftBottom.write(70);
  backLeftBottom.write(70);
  
  frontRightBottom.write(110);
  backRightBottom.write(110);

  //////////////////////////
  
  delay(5000);
}

int timeBetweenWalks = 0;

void loop()
{ 
  walk1();
  delay(timeBetweenWalks);
  walk2();
  delay(timeBetweenWalks);
}

void walk1(){
  frontLeftBottom.write(50);
  backRightBottom.write(130);
  delay(100);
  frontLeftTop.write(140);
  backRightTop.write(20);
  delay(100);
  frontLeftTop.write(160);
  backRightTop.write(0);
  frontLeftBottom.write(70);
  backRightBottom.write(110);
}

void walk2(){
  frontRightBottom.write(130);
  backLeftBottom.write(50);
  delay(100);
  frontRightTop.write(20);
  backLeftTop.write(140);
  delay(100);
  frontRightBottom.write(110);
  backLeftBottom.write(70);
  frontRightTop.write(0);
  backLeftTop.write(160);
}

void startingUpTone() {
  tone(12, 220);
  delay(250);
  noTone(12);
  delay(50);
  tone(12, 220);
  delay(25);
  tone(12, 261);
  delay(250);
  tone(12, 329);
  delay(250);
  noTone(12);
  runOnce = 1;
}

void shuttingDownTone() {
  tone(12, 329);
  delay(250);
  noTone(12);
  delay(50);
  tone(12, 329);
  delay(25);
  tone(12, 261);
  delay(250);
  tone(12, 220);
  delay(250);
  noTone(12);
  runOnce2 = 1;
}


void frontLeftWalk() {
  frontLeftTop.write(180);
  frontLeftBottom.write(60);
  delay(500);
  frontLeftTop.write(150);
  frontLeftBottom.write(30);
  delay(500);
}


/*

void frontLeftWalk() {
  frontLeftTop.write(180);
  frontLeftBottom.write(60);
  delay(2000);
  frontLeftBottom.write(0);
  delay(500);
  frontLeftTop.write(50);
  delay(500);
  frontLeftBottom.write(0);
  delay(1000);
}

*/
