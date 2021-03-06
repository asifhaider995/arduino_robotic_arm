#include <Servo.h>


#define SERVOPIN_1 4 // Base Servo
#define SERVOPIN_2 7 // Hinge Servo
#define SERVOPIN_3 11 // Arm Servo
#define SERVOPIN_4 12 // Rotates Whole structure horizontally

 
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
    servo1.write(angle);
    servo2.write(angle);
    servo3.write(angle);
    servo4.write(angle);
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
    Serial.print("A");
    Serial.print(i);
    Serial.print("\t");
    Serial.println(joyStickValues[i]);
  }
}

int decodeJoystick(int number) {
  if(number == 1) {
    // Joystick 1
    int x = joyStickValues[0];
    int y = joyStickValues[1];
    
    if( x > 490 && x < 517 && y > 1000) {
      // Up
      return 1;
    } 
    else if (x > 490 && x < 517 && y < 10) {
      // Down
      return 2;
    }
    else if(y > 500 && y < 525 && x > 1000) {
      // Left
      return 3;
    }
    else if(y > 500 && y < 525 && x < 10) {
      // right
      return 4;
    }
    else {
      return 0;
    }
  }
  if(number == 2) {
    // Joystick 2
    int y = joyStickValues[2];
    
    if(y > 1000) {
      // Up
      return 1;
    } 
    else if (y < 10) {
      // Down
      return 2;
    }
    else {
      return 0;
    }
  }
  if(number == 3) {
    // Joystick 3
    int y = joyStickValues[3];
    
    if( y > 10) {
      // Up
      return 1;
    } 
    else if (y > 1000) {
      // Down
      return 2;
    }
    else {
      return 0;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(SERVOPIN_1);
  servo2.attach(SERVOPIN_2);
  servo3.attach(SERVOPIN_3);
  servo4.attach(SERVOPIN_4);
  getJoystickValues();
  printJsValues();
  moveServo(0,90);
  for(int i=0; i<4; i++) {
    servoPos[i] = 90;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  getJoystickValues();
  // printJsValues();
  int j1 = decodeJoystick(1);
  int j2 = decodeJoystick(2);
  int j3 = decodeJoystick(3);
  if( j1 == 1 ) {
    // up
    if(servoPos[1] != 170) {
      servoPos[1]++;  
    }
    moveServo(1,servoPos[1]);
  }
  else if( j1 == 2 ) {
    // down
    if(servoPos[1] != 0) {
      servoPos[1]--;
    }
    moveServo(1,servoPos[1]);
  }
  else if( j1 == 3 ) {
    // left
    if(servoPos[0] != 170){
      servoPos[0]++;  
    }
    moveServo(2,servoPos[0]);
  }
  else if( j1 == 4 ) {
    // left
    if(servoPos[0] != 0){
      servoPos[0]--;  
    }
    moveServo(2,servoPos[0]);
  }
  else {
    // stop
    
  }
  if( j2 == 1 ) {
    // up
    if(servoPos[2] != 170) {
      servoPos[2]++;  
    }
    moveServo(1,servoPos[2]);
  }
  else if( j2 == 2 ) {
    // down
    if(servoPos[2] != 0) {
      servoPos[2]--;
    }
    moveServo(1,servoPos[2]);
  }
  else {
    // stop
    
  }
  if( j3 == 1 ) {
    // up
    if(servoPos[3] != 170) {
      servoPos[3]++;  
    }
    moveServo(1,servoPos[3]);
  }
  else if( j3 == 2 ) {
    // down
    if(servoPos[3] != 0) {
      servoPos[3]--;
    }
    moveServo(1,servoPos[3]);
  }
  else {
    // stop
    
  }
  Serial.println(servoPos[3]);
  delay(100);
}
