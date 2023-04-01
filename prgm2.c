#define LEFT_IR A0
#define RIGHT_IR A1
#define LEFT_ENA 6
#define RIGHT_ENA 5
#define LEFT_SPEED 255
#define RIGHT_SPEED 255
int LEFT_MOTOR[]={12,11};
int RIGHT_MOTOR[] ={10,9};

#define IR_ON LOW
bool leftData,rightData;
void foward(){
  Serial.print("FORWORD");
  digitalWrite(LEFT_MOTOR[0], HIGH);
  digitalWrite(LEFT_MOTOR[1], LOW);
  digitalWrite(RIGHT_MOTOR[0], HIGH);
  digitalWrite(RIGHT_MOTOR[1], LOW);
}
void backword(){
  Serial.print("BACKWARD");
  digitalWrite(LEFT_MOTOR[0], LOW);
  digitalWrite(LEFT_MOTOR[1], HIGH);
  digitalWrite(RIGHT_MOTOR[0], LOW);
  digitalWrite(RIGHT_MOTOR[1], HIGH);
}
void right(){
  Serial.print("RIGHT");
  digitalWrite(LEFT_MOTOR[0], HIGH);
  digitalWrite(LEFT_MOTOR[1], LOW);
  digitalWrite(RIGHT_MOTOR[0], LOW);
  digitalWrite(RIGHT_MOTOR[1], HIGH);
}
void left(){
  Serial.print("LEFT");
  digitalWrite(LEFT_MOTOR[0], LOW);
  digitalWrite(LEFT_MOTOR[1], HIGH);
  digitalWrite(RIGHT_MOTOR[0], HIGH);
  digitalWrite(RIGHT_MOTOR[1], LOW);
}
void stop(){
  Serial.print("LEFT");
  digitalWrite(LEFT_MOTOR[0], LOW);
  digitalWrite(LEFT_MOTOR[1], LOW);
  digitalWrite(RIGHT_MOTOR[0], LOW);
  digitalWrite(RIGHT_MOTOR[1], LOW);
}
void setup() {
  pinMode(LEFT_IR,INPUT);
  pinMode(RIGHT_IR,INPUT);
  pinMode(LEFT_ENA, INPUT);  
  pinMode(RIGHT_ENA, INPUT);
  analogWrite(RIGHT_ENA, RIGHT_SPEED);
  analogWrite(LEFT_ENA, LEFT_SPEED);  
  for(int i=0;i<2;i++){
    pinMode(LEFT_MOTOR[i],OUTPUT);
    pinMode(RIGHT_MOTOR[i],OUTPUT);
  }
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