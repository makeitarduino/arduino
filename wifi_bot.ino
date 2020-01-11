#include <ESP8266WiFi.h>
 
const char* ssid = "Redmi";
const char* password = "test1234";
 
int ledPin =14; // GPIO13
int ledPin1 =5; // GPIO13


//Define Pins
//Motor A
//int enableA = 5;
int MotorA1 = 14;
int MotorA2 = 12;
 
//Motor B
//int enableB = 8;
int MotorB1 = 13;
int MotorB2 = 15;


 
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
    pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
     digitalWrite(ledPin1, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

 // pinMode (enableA, OUTPUT);
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);  
  
//  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT);  

 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = 0;
  if (request.indexOf("/FORWORD") != -1)  {
    digitalWrite(ledPin, HIGH);
    digitalWrite (MotorA1, HIGH);
    digitalWrite (MotorA2, LOW);
 
    digitalWrite (MotorB1, HIGH);
    digitalWrite (MotorB2, LOW);
    value = 1;
  }
  if (request.indexOf("/BACKWORD") != -1)  {
    digitalWrite(ledPin, HIGH);
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, HIGH);
 
    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, HIGH);
    value = 2;
  }

if (request.indexOf("/RIGHT") != -1)  {
    digitalWrite(ledPin, HIGH);
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, HIGH);
 
    digitalWrite (MotorB1, HIGH);
    digitalWrite (MotorB2, LOW);
    value = 3;
  }


  if (request.indexOf("/LEFT") != -1)  {
    digitalWrite(ledPin, HIGH);
    digitalWrite (MotorA1, HIGH);
    digitalWrite (MotorA2, LOW);
 
    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, HIGH);
    value = 4;
  }
  if (request.indexOf("/STOP") != -1)  {
    digitalWrite(ledPin, HIGH);
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, LOW);
 
    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, LOW);
    value = 5;
  }


 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("BOT MOVING: ");
 
  if(value == 1) {
    client.print("FORWARD");
  }
  if (value == 2)
  {
    client.print("BACKWORD");
  }
  if (value == 3)
  {
    client.print("RIGHT");
  }
  if (value == 4)
  {
    client.print("LEFT");
  }
  if (value == 5)
  {
    client.print("STOP");
  }



  
  client.println("<br><br>");
  client.println("<a href=\"/FORWORD\"\"><button><h1>Forward</h1> </button></a><br />");
  client.println("<a href=\"/BACKWORD\"\"><button><h1>Backword</h1> </button></a><br />");  
  client.println("<a href=\"/LEFT\"\"><button><h1>Left </h1></button></a><br />");  
  client.println("<a href=\"/RIGHT\"\"><button><h1>Right</h1> </button></a><br />");  
  client.println("<a href=\"/STOP\"\"><button><h1>STOP</h1> </button></a><br />");  
  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}

