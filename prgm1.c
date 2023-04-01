#include <AFMotor.h>
#define LEFT_IR A0
#define RIGHT_IR A1
AF_DCMotor LEFT_MOTOR(2);
AF_DCMotor RIGHT_MOTOR(3);
#define IR_ON LOW
bool leftData,rightData;
void foward(){
  Serial.print("FORWORD");
  LEFT_MOTOR.run(FORWARD);
  RIGHT_MOTOR.run(FORWARD);
}
void backword(){
  Serial.print("BACKWARD");
  LEFT_MOTOR.run(BACKWARD);
  RIGHT_MOTOR.run(BACKWARD);
}
void left(){
  Serial.print("LEFT");
  LEFT_MOTOR.run(BACKWARD);
  RIGHT_MOTOR.run(FORWARD);
  
}
void right(){
  Serial.print("RIGHT");
  LEFT_MOTOR.run(FORWARD);
  RIGHT_MOTOR.run(BACKWARD);
}

void stop(){
  Serial.print("LEFT");
  LEFT_MOTOR.run(RELEASE);
  RIGHT_MOTOR.run(RELEASE);
}
void setup() {
  pinMode(LEFT_IR,INPUT);
  pinMode(RIGHT_IR,INPUT);
  LEFT_MOTOR.setSpeed(200);
	RIGHT_MOTOR.run(RELEASE);
 
  Serial.begin(9600);

}

void loop() {
  leftData=digitalRead(LEFT_IR);
  rightData=digitalRead(RIGHT_IR);
  if(leftData==IR_ON&&rightData==IR_ON)
    foward();
  else if (leftData!=IR_ON&&rightData==IR_ON)
    left();
  else if (leftData==IR_ON&&rightData!=IR_ON)
    right();
  else if(leftData!=IR_ON&&rightData!=IR_ON)
    stop();
}