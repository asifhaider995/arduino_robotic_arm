#include <Servo.h>


#define SERVOPIN_1 4 // Base Servo
#define SERVOPIN_2 7 // Hinge Servo
#define SERVOPIN_3 11 // Arm Servo

#define JOYSTICK_1_X A0
#define JOYSTICK_1_Y A1
#define JOYSTICK_2_X A2
#define JOYSTICK_3_X A3


#define JOYSTICK_UP_THRESH 20
#define JOYSTICK_DOWN_THRESH 200

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int joyStickValues[4];
int servoPos[4];


// Function to move servo forward
// @params: Servo Number, delay time, angle in degrees
void moveServo (int servoNum, int angle) {
  if(servoNum == 1) {
    servo1.write(angle);
    delay(15);
  }
  else if(servoNum == 2) {
    servo2.write(angle);
    delay(15);
  }
  else if(servoNum == 3) {
    servo3.write(angle);
    delay(15);
  }
  else if(servoNum == 4) {
    servo4.write(angle);
    delay(15);
  }
  else if(servoNum == 0) {
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
    delay(15);
  }
  else if(servoNum == 100) {
    servo1.write(170);
    servo2.write(170);
    servo3.write(170);
    delay(15);
  }
  else {
    
  }
}

void testCase1() {
  moveServo(1,40);
  moveServo(2,40);
  moveServo(3,40);
  delay(2000);
  moveServo(1,140);
  moveServo(2,140);
  moveServo(3,140);
  delay(2000);
  moveServo(1,20);
  moveServo(2,20);
  moveServo(3,20);
  delay(2000);
  moveServo(0,0);
  moveServo(0,0);
  moveServo(0,0);
  delay(4000);
}
 
void getJoystickValues() {
  // returns joystick position
  joyStickValues[0] = analogRead(JOYSTICK_1_X);
  joyStickValues[1] = analogRead(JOYSTICK_1_Y);
  joyStickValues[2] = analogRead(JOYSTICK_2_X);
  joyStickValues[3] = analogRead(JOYSTICK_3_X);
  
}

void printJsValues() {
  for (int i=0; i<4; i++) {
    Serial.print("JoyStick "+(i+1));
    Serial.println(joyStickValues[i]);
  }
}

void decodeJsValues() {
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(SERVOPIN_1);
  servo2.attach(SERVOPIN_2);
  servo3.attach(SERVOPIN_3);
  getJoystickValues();
  printJsValues();
}

void loop() {
  // put your main code here, to run repeatedly:
  testCase1();
}
