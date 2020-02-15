#define trigPin 4
#define echoPin 5

//obstacle indicator RED LED
#define led 8

//NO obstacle indicator Green LED
#define led2 7
 

//Walker Motor
int MotorA1 = 9;
int MotorA2 = 10;
 
//Base wheel Motor
int MotorB1 = 11;
int MotorB2 = 12;

 
 void setup() {
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(led, OUTPUT);
   pinMode(led2, OUTPUT);

   pinMode (MotorA1, OUTPUT);
   pinMode (MotorA2, OUTPUT);  
  
 
   pinMode (MotorB1, OUTPUT);
   pinMode (MotorB2, OUTPUT);  
 }

 void loop() {
   
   long duration, distance;
 
   digitalWrite (MotorA1, HIGH);
   digitalWrite (MotorA2, LOW);

   digitalWrite(led,LOW);
   digitalWrite(led2,HIGH);

   //Base wheel motor or steering motor will be kept off initially
   digitalWrite (MotorB1, LOW);
   digitalWrite (MotorB2, LOW);

   
   digitalWrite(trigPin, LOW);  
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distance = (duration/2) / 29.1;
   if (distance <20 ) {  // This is where the LED On/Off happens
   digitalWrite(led,HIGH); // When the obstacle condition is met, the RED LED switches on and Green LED should turn off
   digitalWrite(led2,LOW); // Green LED
  
    digitalWrite (MotorB1, HIGH);
    digitalWrite (MotorB2, LOW);
  
    delay(10);
 }
 
 } 
