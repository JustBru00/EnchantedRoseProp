#include "Boards.h"
#include "Servo.h"

/*
 * Original Code by @stevemurch on github.com 
 * Modifications for Lancaster Academy for the Performing Art's 
 * production of B&B 2020 by Justin Brubaker (@justbru00)
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
  moveServo(5, 0);
  moveServo(6, 0);
}

void moveServo(int servoPin, int drop1reset0)
{
  Serial.println("Move servo [servoPin, state]");
  Serial.println(servoPin);
  Serial.println(drop1reset0);

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

  Serial.println("RESETTING FROM STARTING SERVO STATE, WHICH IS ");
  Serial.println(startingPos);
  
  for (pos = startingPos; pos >=0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  myservo.detach();
  } 

  else 
  {
    pinMode(servoPin, OUTPUT);
    myservo.attach(servoPin);
    int startingPos = myservo.read();

  Serial.println("MOVING TO 180 FROM STARTING SERVO STATE, WHICH IS ");
  Serial.println(startingPos);
    
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

  if (toPosition<= startingPos) 
  {
  for (pos = startingPos; pos >=toPosition; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  myservo.detach();
  } else 
  {

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

void loop() { 
 
  // TODO Watch for digital inputs and detach petals based on them.

}
