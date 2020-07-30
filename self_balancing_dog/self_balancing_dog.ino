#include <Servo.h>

Servo frontLeftTopServo;  // create servo object to control a servo
Servo frontRightTopServo;
Servo backLeftTopServo;
Servo backRightTopServo;

Servo frontLeftBottomServo;
Servo frontRightBottomServo;
Servo backLeftBottomServo;
Servo backRightBottomServo;

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Timers
unsigned long timer = 0;
float timeStep = 0.01;

// Pitch, Roll and Yaw values

float pitch = 0;
float roll = 0;
float yaw = 0;


#include <PID_v1.h>

double Setpoint ; // will be the desired value
double Input; // photo sensor
double Output ; //LED
//PID parameters
double Kp=0.5, Ki=0, Kd=0; 
//double Kp=0, Ki=10, Kd=0;
 
//create PID instance 
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{ //start Serial in case we need to print debugging info
  Serial.begin(115200);

  // Initialize MPU6050
  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  pitch = 0;
  roll = 0;
  yaw = 0;
  mpu.calibrateGyro();
  delay(1000);

  Setpoint = 0;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);
  myPID.SetOutputLimits(-20, 50);

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

  frontLeftBottom(0);
  backLeftBottom(8);
  frontRightBottom(0);
  backRightBottom(8);
  delay(1000);
}
void loop()
{
  timer = millis();
  Vector norm = mpu.readNormalizeGyro();
  
  pitch = pitch + norm.XAxis * timeStep;
  roll = roll + norm.YAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;
  
  Serial.print(" Pitch = ");
  Serial.print(pitch);
  
  Input = pitch;
  myPID.Compute();
  
  Serial.print("         pid output = "); Serial.println(Output);

  frontLeftTop(35);
  backLeftTop(55);
  frontRightTop(35);
  backRightTop(55);

  frontLeftBottom(0);
  backLeftBottom(Output);
  frontRightBottom(0);
  backRightBottom(Output);
  
  delay((timeStep * 1000) - (millis() - timer));
}

void frontLeftTop(int input) {
  frontLeftTopServo.write((input * -1) + 200);
}

void frontRightTop(int input) {
  frontRightTopServo.write(input - 35);
}

void backLeftTop(int input) {
  backLeftTopServo.write((-input) + 155);
}

void backRightTop(int input) {
  backRightTopServo.write((input * 1.09) + 19);
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
