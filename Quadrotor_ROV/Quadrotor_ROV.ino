#include <Servo.h>

#define ballJointControllerXPin A0
#define ballJointControllerYPin A1
#define ballJointControllerButtonPin A2

#define XYControllerXPin A3
#define XYControllerYPin A4
#define XYControllerButtonPin A5

#define ZControllerYPin A6
#define ZControllerButtonPin A7

/*
3 Joysticks - 1 Ball Joint, 1 X & Y axes, 1 Z-axis
6 Servos - 2 Ball Joint, 4 Propulsion
4 Thrusters (Propulsion)
*/

// Struct to hold the different outputs from the Joysticks
typedef struct Joystick {
  int X;
  int Y;
  int button;
} Joystick;

// Define the 3 Joysticks
Joystick ballJointController;
Joystick XYController;
Joystick ZController;

// Define the 2 Ball Joint Servos
Servo ballJointServo1;
Servo ballJointServo2;

// Define the 4 Propulsion Servos
Servo frontLeftServo;
Servo frontRightServo;
Servo backLeftServo;
Servo backRightServo;

// Define the 4 Thrusters
Servo frontLeftThruster;
Servo frontRightThruster;
Servo backLeftThruster;
Servo backRightThruster;

// Define Ball Joint Helper Variables
int mode = 0;
int flag = 0;

int X = 0;
int Y = 0;

void setup() {
  // Define Servo Pins
  int ballJointServo1Pin;
  int ballJointServo2Pin;

  int frontLeftServoPin;
  int frontRightServoPin;
  int backLeftServoPin;
  int backRightServoPin;

  int frontLeftThrusterPin;
  int frontRightThrusterPin;
  int backLeftThrusterPin;
  int backRightThrusterPin;

  // Attach Servos to Pins
  ballJointServo1.attach(ballJointServo1Pin);
  ballJointServo2.attach(ballJointServo2Pin);

  frontLeftServo.attach(frontLeftServoPin);
  frontRightServo.attach(frontRightServoPin);
  backLeftServo.attach(backLeftServoPin);
  backRightServo.attach(backRightServoPin);

  frontLeftThruster.attach(frontLeftThrusterPin);
  frontRightThruster.attach(frontRightThrusterPin);
  backLeftThruster.attach(backLeftThrusterPin);
  backRightThruster.attach(backRightThrusterPin);

  // Serial
  Serial.begin(9600);

  // Wait a while
  delay(100);
}

void loop() {
  // Ball Joint Control
  if (digitalRead(ballJointControllerButtonPin)) {
    if (flag == 0) {
      flag = 1;
      mode = !mode;
      delay(100);
    }
  } else {
    flag = 0;
  }

  if (mode == 0) {
    ballJointController.X = analogRead(ballJointControllerXPin);
    ballJointController.Y = analogRead(ballJointControllerYPin);

    X = map(ballJointController.X, 0, 1023, 20, 160);
    Y = map(ballJointController.Y, 0, 1023, 20, 160);
  }

  ballJointServo1.write(X);
  ballJointServo2.write(Y);

  delay(10);

  // Propulsion
  // TODO
}
