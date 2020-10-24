 
//Spider bot program by MakeIt author
//link :
#include <Servo.h>

// creating the servo objects for front, rear and mid servo
Servo frontLeg;
Servo rearLeg;
Servo midLeg;
// setting the servo angle to 90° for startup
byte frontAngle = 90;
byte rearAngle = 90;
byte midAngle = 88;
// setting the delay value
byte delayWalk = 3; 
byte delayTurn = 3;
byte delayDance = 15;
// Analog sensor pins
int left = 0;
int right = 0;


char val; // variable to receive data from the serial port


void setup(){
  // serial connection for debugging
  Serial.begin(9600);
  // attaching the servos to their pins  
  frontLeg.attach(3);
  rearLeg.attach(4);
  midLeg.attach(5);
  // move servos to center position -> 90°
  frontLeg.write(frontAngle);
  rearLeg.write(rearAngle);
  midLeg.write(midAngle);
  delay(2000);

}
// Light detection and filtering
//Start dancig///
void dabRight(){

midAngle=55;
 midLeg.write(midAngle);
  for (frontAngle = 120; frontAngle > 60; frontAngle -= 1){
    rearLeg.write(frontAngle);
    delay(delayDance);
  }
    for (frontAngle = 60; frontAngle < 120; frontAngle += 1){
    rearLeg.write(frontAngle);
     delay(delayDance);
    }

    rearLeg.write(90);
  
}

void dabLeft(){

midAngle=110;
 midLeg.write(midAngle);
 

    for (frontAngle = 120; frontAngle > 60; frontAngle -= 1){
    frontLeg.write(frontAngle);
     delay(delayDance);
  }
    for (frontAngle = 60; frontAngle < 120; frontAngle += 1){
    frontLeg.write(frontAngle);
     delay(delayDance);
  }
  frontLeg.write(90);
}


void dabMiddle(){

  frontLeg.write(90);
  rearLeg.write(90);
  for (midAngle = 55; midAngle < 110; midAngle +=1){
    midLeg.write(midAngle);
    delay(delayDance);
  }
  for (midAngle = 110; midAngle > 55; midAngle -=1){
    midLeg.write(midAngle);
    delay(delayDance);
  }

  midLeg.write(88);
  
}

// Walk forward //////////////////////////////////////////////////////////
void forward(){

  for (midAngle = 55; midAngle < 110; midAngle +=1){
    midLeg.write(midAngle);
    delay(delayWalk);
  }
  for (frontAngle = 120; frontAngle > 60; frontAngle -= 1){
    frontLeg.write(frontAngle);
    rearLeg.write(frontAngle);
    delay(delayWalk);
  }
  for (midAngle = 110; midAngle > 55; midAngle -=1){
    midLeg.write(midAngle);
    delay(delayWalk);
  }
  for (frontAngle = 60; frontAngle < 120; frontAngle += 1){
    frontLeg.write(frontAngle);
    rearLeg.write(frontAngle);
    delay(delayWalk);
  }
}
// Walk reverse //////////////////////////////////////////////////////////
void reverse(){

  for (midAngle = 55; midAngle < 110; midAngle +=1){
    midLeg.write(midAngle);
    delay(delayWalk);
  }
  for (frontAngle = 60; frontAngle < 120; frontAngle += 1){
    frontLeg.write(frontAngle);
    rearLeg.write(frontAngle);
    delay(delayWalk);
  }

  for (midAngle = 110; midAngle > 55; midAngle -=1){
    midLeg.write(midAngle);
    delay(delayWalk);
  }
  for (frontAngle = 120; frontAngle > 60; frontAngle -= 1){
    frontLeg.write(frontAngle);
    rearLeg.write(frontAngle);
    delay(delayWalk);
  }
}
// Left Turn //////////////////////////////////////////////////////////
void leftTurn(){

  rearLeg.write(90);
  for (midAngle = 70; midAngle < 110; midAngle += 1){
    midLeg.write(midAngle);
    delay(delayTurn); 
  } 
  for (frontAngle = 70; frontAngle < 110; frontAngle +=1){
    frontLeg.write(frontAngle);
    delay(delayTurn); 
  }
  for (rearAngle = 110; rearAngle > 70; rearAngle -=1){
    rearLeg.write(rearAngle);
    delay(delayTurn); 
  }
  for (midAngle = 110; midAngle > 70; midAngle -= 1){
    midLeg.write(midAngle);
    delay(delayTurn); 
  }
  for (frontAngle = 110; frontAngle > 70; frontAngle -=1){
    frontLeg.write(frontAngle);
    delay(delayTurn); 
  }
  for (rearAngle = 70; rearAngle < 110; rearAngle +=1){
    rearLeg.write(rearAngle);
    delay(delayTurn); 
  }
}
// Right Turn //////////////////////////////////////////////////////////
void rightTurn(){

  frontLeg.write(90);
  for (midAngle = 70; midAngle < 110; midAngle += 1){
    midLeg.write(midAngle);
    delay(delayTurn); 
  }
  for (rearAngle = 70; rearAngle < 110; rearAngle +=1){
    rearLeg.write(rearAngle);
    delay(delayTurn); 
  }
  for (frontAngle = 110; frontAngle > 70; frontAngle -=1){
    frontLeg.write(frontAngle);
    delay(delayTurn); 
  }
  for (midAngle = 110; midAngle > 70; midAngle -= 1){
    midLeg.write(midAngle);
    delay(delayTurn); 
  } 
  for (rearAngle = 110; rearAngle > 70; rearAngle -=1){
    rearLeg.write(rearAngle);
    delay(delayTurn); 
  }
  for (frontAngle = 70; frontAngle < 110; frontAngle +=1){
    frontLeg.write(frontAngle);
    delay(delayTurn); 
  }
}
// Stop walking
void stay(){
    frontLeg.write(90);
    midLeg.write(90);
    rearLeg.write(90);
}

void letsDance()
{
  dabRight();
  delay(1000);
  dabLeft();
  delay(1000);
  dabMiddle();
  delay(1000);
  forward();
  delay(500);
  reverse();
  delay(500);
  rightTurn();
  delay(500);
  leftTurn();
  delay(500);
  
}
////////////////////////////////////////////////////////////////
void loop(){

// if data is available to read
// read it and store it in 'val'
  if( Serial.available() )       
  {
    val = Serial.read();
  }


//Steering Controls

  if( val == 'U' )               // if 'U' received move up
  {
    forward(); 
   Serial.print(val);
  }
 
  if( val == 'D' )              // if 'D' received move down
  { 
    reverse();  
    Serial.print(val);
  }
 
  if( val == 'L' )               // if 'L' received move left
  {
    leftTurn(); 
    Serial.print(val);
  }
  if( val == 'R' )              // if 'R' received move right
  { 
    rightTurn();
    Serial.print(val);  
  }
 
  if( val == 'S' )               // if 'S' received stop the bot
  {
    stay();
      // move servos to center position -> 90°
    Serial.print(val);
  } 


//Flight Mode settings

  if( val == 'f' )               // if 'f' received move forward
  {
    forward(); 
    Serial.print(val);
  }

  if( val == 'b' )               // if 'b' received move backward
  { 
    reverse();
    Serial.print(val); 
  }
 
  if( val == 'l' )               // if 'l' received move left
  {
    leftTurn(); 
    Serial.print(val);
  }
  
  if( val == 'r' )              // if 'r' received move right
  { 
    rightTurn();
    Serial.print(val); 
  }
 
  if( val == 'd' )               // if 'd' received set dance mode
  {
    letsDance();    
    Serial.print(val);
  } 

  
  //stay();
  //delay(1000);
  //forward();
  //reverse();
  //rightTurn();
}





