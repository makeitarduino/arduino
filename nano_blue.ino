char val; // variable to receive data from the serial port

//Motor A
int MotorA1 = 4;
int MotorA2 = 5;
 
//Motor B
int MotorB1 = 6;
int MotorB2 = 7;


void setup() { 
  
Serial.begin(9600);       // start serial communication at 9600bps

// pinMode (enableA, OUTPUT);
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);  
  
//  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT);  

} 


void loop() { 
  if( Serial.available() )       // if data is available to read
  {
    val = Serial.read();  
    
    
    // read it and store it in 'val'
  }
 
  
                   // wait 100ms for next reading


  if( val == 'G' )               // if 'H' was received
  {
    
    digitalWrite (MotorA1, HIGH);
    digitalWrite (MotorA2, LOW);
 
    digitalWrite (MotorB1, HIGH);
    digitalWrite (MotorB2, LOW);
   
  }
  if( val == 'g' )   { 
       digitalWrite (MotorA1, HIGH);
    digitalWrite (MotorA2, LOW);
 
    digitalWrite (MotorB1, HIGH);
    digitalWrite (MotorB2, LOW);  // otherwise turn it OFF
  }
  
  
    if( val == 'R' )               // if 'H' was received
  {

 
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, HIGH);
 
    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, HIGH);
   
  }

  
  if( val == 'r' )  
  { 
     
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, HIGH);
 
    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, HIGH);
   
  }
   
  
    if( val == 'Y' )               // if 'H' was received
  {
   
    digitalWrite (MotorA1, HIGH);
    digitalWrite (MotorA2, LOW);
 
    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, HIGH);
  } 
  if( val == 'y' )  
  { 
   
    digitalWrite (MotorA1, HIGH);
    digitalWrite (MotorA2, LOW);
 
    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, HIGH);
  }
    

   if( val == 'B' )               // if 'H' was received
  {
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, HIGH);
 
    digitalWrite (MotorB1, HIGH);
    digitalWrite (MotorB2, LOW);
  } 
  if( val == 'b' ){ 
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, HIGH);
 
    digitalWrite (MotorB1, HIGH);
    digitalWrite (MotorB2, LOW);
  }
   
  if( val == 'S' )               // if 'H' was received
  {
    
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, LOW);
 
    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, LOW);
   
  }

} 

