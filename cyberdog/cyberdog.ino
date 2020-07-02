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

  frontLeftTop.write(162);
  backLeftTop.write(165);
  
  frontRightTop.write(0);
  backRightTop.write(0);

  ///////////////////////////
  
  frontLeftBottom.write(50);
  backLeftBottom.write(65);
  
  frontRightBottom.write(95);
  backRightBottom.write(110);

  //////////////////////////
  
  delay(2000);
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
  frontLeftBottom.write(0);
  backRightBottom.write(180);
  delay(100);
  frontLeftTop.write(100);
  backRightTop.write(30);
  delay(50);
  frontLeftBottom.write(40);
  backRightBottom.write(90);
  delay(100);
  frontLeftTop.write(163);
  backRightTop.write(0);
}

void walk2(){
  frontRightBottom.write(175);
  backLeftBottom.write(15);
  delay(100);
  frontRightTop.write(30);
  backLeftTop.write(100);
  delay(50);
  frontRightBottom.write(100);
  backLeftBottom.write(75);
  delay(100);
  frontRightTop.write(0);
  backLeftTop.write(163);
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
