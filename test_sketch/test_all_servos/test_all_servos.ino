#include "Boards.h"
#include "Servo.h"

Servo myservo;
int pos = 0;
byte    pin_servo[4]; // holds the set rotation value of the servo

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Tested");    
  // Inputs 8,9,10,11
  //pinMode(8, INPUT_PULLUP);
  //pinMode(9, INPUT_PULLUP);
  //pinMode(10, INPUT_PULLUP);
  //pinMode(11, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  moveServoTest(11);
  moveServoTest(10);
  moveServoTest(9);
  moveServoTest(6);

  delay(4000);
}

void moveServoTest(int servoPin)
{
  pinMode(servoPin, OUTPUT);
  myservo.attach(servoPin);

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  myservo.detach();
  
}
