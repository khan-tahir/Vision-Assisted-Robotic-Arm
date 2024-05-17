#include <Servo.h>

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo gripServo;

int basePin = 9;
int shoulderPin = 10;
int elbowPin = 11;
int gripPin = 12;

void setup() {
  baseServo.attach(basePin);
  shoulderServo.attach(shoulderPin);
  elbowServo.attach(elbowPin);
  gripServo.attach(gripPin);
}

void loop() {
 
if (Serial.available() > 0) {
    char color = Serial.read();
    if (color == 'R') {
      moveArmToRed();
    } else if (color == 'G') {
      moveArmToGreen();
    } else if (color == 'B') {
      moveArmToBlue();
    }
  }
}
  
  char color = Serial.read();
  
  if (color == 'R') {
    moveArmToRed();
  } else if (color == 'G') {
    moveArmToGreen();
  } else if (color == 'B') {
    moveArmToBlue();
  }
}

void moveArmToRed() {
  // Write code to move the robotic arm to handle red objects
  baseServo.write(90);
  shoulderServo.write(90);
  elbowServo.write(90);
  gripServo.write(180);
}

void moveArmToGreen() {
  // Write code to move the robotic arm to handle green objects
  baseServo.write(180);
  shoulderServo.write(45);
  elbowServo.write(135);
  gripServo.write(0);
}

void moveArmToBlue() {
  // Write code to move the robotic arm to handle blue objects
  baseServo.write(0);
  shoulderServo.write(135);
  elbowServo.write(45);
  gripServo.write(0);
}
