//#include <ESP8266WiFi.h>
//#include <SoftwareSerial.h>

char val; // variable to receive data from the serial port
int ledg = 5; // LED connected to pin 48 (on-board LED) 
int ledr = 4;
int ledy = 14;
int ledb = 12;

void setup() { 
  pinMode(ledg, OUTPUT);
    pinMode(ledr, OUTPUT);
      pinMode(ledy, OUTPUT);
        pinMode(ledb, OUTPUT);



  // pin 48 (on-board LED) as OUTPUT
  Serial.begin(9600);       // start serial communication at 9600bps
digitalWrite(ledg, LOW); 
digitalWrite(ledr, LOW); 
digitalWrite(ledy, LOW); 
digitalWrite(ledb, LOW); 

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
    digitalWrite(ledg, HIGH); 
   Serial.print(val); // turn ON the LED
  }
  if( val == 'g' )   { 
    digitalWrite(ledg, LOW);   // otherwise turn it OFF
  }
  delay(100);    
  
    if( val == 'R' )               // if 'H' was received
  {
    digitalWrite(ledr, HIGH); 
   Serial.print(val); // turn ON the LED
  }
  if( val == 'r' )  
  { 
    digitalWrite(ledr, LOW);   // otherwise turn it OFF
  }
  delay(100);    
  
    if( val == 'Y' )               // if 'H' was received
  {
    digitalWrite(ledy, HIGH); 
   Serial.print(val); // turn ON the LED
  } 
  if( val == 'y' )  
  { 
    digitalWrite(ledy, LOW);   // otherwise turn it OFF
  }
  delay(100);    

   if( val == 'B' )               // if 'H' was received
  {
    digitalWrite(ledb, HIGH); 
   Serial.print(val); // turn ON the LED
  } 
  if( val == 'b' ){ 
    digitalWrite(ledb, LOW);   // otherwise turn it OFF
  }
  delay(100);    


} 

