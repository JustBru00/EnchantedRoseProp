#include "Boards.h"
#include "Servo.h"

/*
 * Original Code by @stevemurch on github.com 
 * Modifications for Lancaster Academy for the Preforming Arts 
 * production of Beauty and the Beast 2020 by Justin Brubaker (@justbru00)
 */
 
// BOARD SETUP
// attach control pins for servos as follows:
// SERVO PINS:  2,3,4,5 -- THIS IS HARDCODED IN THE PROGRAM
// servos WILL NOT WORK on 0, 1 pins

#define PROTOCOL_MAJOR_VERSION   0 //
#define PROTOCOL_MINOR_VERSION   1 //
#define PROTOCOL_BUGFIX_VERSION  0 // bugfix

Servo myservo;
int pos = 0;
byte    pin_servo[4]; // holds the set rotation value of the servo

static byte buf_len = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enchanted Rose Prop - LAPA B&B");    
  // Inputs 8,9,10,11
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

  resetProp();
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

void resetProp() {  
  Serial.println("Resetting prop");

  // Reset all servos
  moveServo(2, 0);
  moveServo(3, 0);
  moveServo(4, 0);
  moveServo(5, 0);
}

void moveServo(int servoPin, int drop1reset0)
{
  Serial.println("Move servo [servoPin, state]");
  Serial.print(servoPin);
  Serial.print(" ");
  Serial.print(drop1reset0);
  Serial.print("\n");

  if (myservo.attached())
  {
    myservo.detach();
  }

  if (drop1reset0==0)
  {
    pinMode(servoPin, OUTPUT);
    myservo.attach(servoPin);

    int startingPos = myservo.read();
    // get to 0
  
    for (pos = startingPos; pos >=0; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    myservo.detach();
  } else {
    pinMode(servoPin, OUTPUT);
    myservo.attach(servoPin);
    int startingPos = myservo.read();
    
    for (pos = startingPos; pos <=180; pos += 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    myservo.detach();
  } 
  
}

void moveServoToPosition(int servoPin, int toPosition)
{
  Serial.println("Move servo to [servoPin, toPosition]");
  Serial.println(servoPin);
  Serial.println(toPosition);

  if (myservo.attached())
  {
    myservo.detach();
  }

  pinMode(servoPin, OUTPUT);
  myservo.attach(servoPin);

  int startingPos = myservo.read();
  // get to 0

  Serial.println("RESETTING FROM STARTING SERVO STATE, WHICH IS ");
  Serial.println(startingPos);

  if (toPosition<= startingPos) {
    for (pos = startingPos; pos >=toPosition; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
    myservo.detach();
    } else {
      for (pos = startingPos; pos < toPosition; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
      }
    myservo.detach();   
    }
}

// LOOP
// Watch for digital inputs.

int DROP = 1;
int RESET = 0;

void loop() {  
  // Watch for digital inputs and detach petals based on them.
  // Inputs 8,9,10,11
  // Servo Pins: 2,3,4,5 -- THIS IS HARDCODED IN THE PROGRAM
  int input1 = digitalRead(8);
  int input2 = digitalRead(9);
  int input3 = digitalRead(10);
  int input4 = digitalRead(11);

  if (input1 == LOW) {
    // Input 1 on pin 8 is closed.
    Serial.println("INPUT1 - PIN 8");
    moveServo(2, DROP);
    delay(1500);
    moveServo(2, RESET);
    Serial.println("READY FOR NEXT COMMAND");
  } else if (input2 == LOW) {
    // Input 2 on pin 9 is closed.
    Serial.println("INPUT2 - PIN 9");
    moveServo(3, DROP);
    delay(1500);
    moveServo(3, RESET);
    Serial.println("READY FOR NEXT COMMAND");
  } else if (input3 == LOW) {
    // Input 3 on pin 10 is closed.
    Serial.println("INPUT3 - PIN 10");
    moveServo(4, DROP);
    delay(1500);
    moveServo(4, RESET);
    Serial.println("READY FOR NEXT COMMAND");
  } else if (input4 == LOW) {
    // Input 4 on pin 11 is closed.
    Serial.println("INPUT4 - PIN 11");
    moveServo(5, DROP);
    delay(1500);
    moveServo(5, RESET);
    Serial.println("READY FOR NEXT COMMAND");
  }

  // TODO RESET
  
}
