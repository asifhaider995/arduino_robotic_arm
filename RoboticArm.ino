#include <Servo.h>


#define SERVOPIN_1 4 // Base Servo
#define SERVOPIN_2 7 // Hinge Servo
#define SERVOPIN_3 11 // Arm Servo

#define JOYSTICK_LEFT_X A0
#define JOYSTICK_MID_X A1
#define JOYSTICK_RIGHT_X A2


#define JOYSTICK_THRESH 150

Servo servo1;
Servo servo2;
Servo servo3;




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
 
int getJoystickValue(int joyStickNumber) {
  // returns joystick position
  return analogRead(joyStickNumber);
}



void setup() {
  // put your setup code here, to run once:
  servo1.attach(SERVOPIN_1);
  servo2.attach(SERVOPIN_2);
  servo3.attach(SERVOPIN_3);

}

void loop() {
  // put your main code here, to run repeatedly:
  testCase1();
}
