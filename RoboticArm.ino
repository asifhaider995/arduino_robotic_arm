#define SERVOPIN_1 2 // Base Servo
#define SERVOPIN_2 3 // Hinge Servo
#define SERVOPIN_3 4 // Arm Servo

#define JOYSTICK_LEFT_X A0
#define JOYSTICK_MID_X A1
#define JOYSTICK_RIGHT_X A2


#define JOYSTICK_THRESH 150

int joyStickData = [0,0,0];

// Function to move servo forward
// @params: Servo Number, delay time, angle in degrees
void moveServoForward (int servoNum, int delay, int angle) {
  
}


// Function to move servo backward (reverse)
// @params: Servo Number, delay time, angle in degrees
void moveServoBackward (int servoNum, int delay, int angle) {
  
}
 
int getJoystickValue(int joyStickNumber) {
  // returns joystick position
  return analogRead(joyStickNumber);
}



void setup() {
  // put your setup code here, to run once:
  pinMode(SERVOPIN_1, OUTPUT);
  pinMode(SERVOPIN_2, OUTPUT);
  pinMode(SERVOPIN_3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i < joyStickData.length() ; i++) {
    joyStickData[i] = getJoystickValue(A0);
  }
}
