#include <ESP8266WiFi.h>
 
const char* ssid = "vinay-t";
const char* password = "test@123";
 
int ledPin = 5; // GPIO13
int ledPin1 = 4; // GPIO13

int ledg = 14;
int ledr = 12;
 

int ledy = 13;
int ledb = 15;


 
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
    pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, LOW);
   pinMode(ledg, OUTPUT);
   digitalWrite(ledg, LOW);
    pinMode(ledr, OUTPUT);
    digitalWrite(ledr, LOW);
     pinMode(ledy, OUTPUT);
     digitalWrite(ledy, LOW);
      pinMode(ledb, OUTPUT);
      digitalWrite(ledb, LOW);
 
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
  int gvalue=0;
  int rvalue=0;
  int yvalue=0;
  int bvalue=0;

  
  if (request.indexOf("/GREEN") != -1 && gvalue == 0 )  {
    digitalWrite(ledPin, HIGH);
    digitalWrite (ledg,HIGH);
    gvalue =1;   
  }
  else if(request.indexOf("/GREEN") != -1 && gvalue == 0) 
  {
    digitalWrite (ledg,LOW);
    gvalue =0;   
  }
  
 /*if (request.indexOf("/BACKWORD") != -1)  {
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

*/
 
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
  client.println("<a href=\"/GREEN\"\"><button><h1>Forward</h1> </button></a><br />");
  client.println("<a href=\"/RED\"\"><button><h1>Backword</h1> </button></a><br />");  
  client.println("<a href=\"/YELLOW\"\"><button><h1>Left </h1></button></a><br />");  
  client.println("<a href=\"/BLUE\"\"><button><h1>Right</h1> </button></a><br />");  
  client.println("<a href=\"/STOP\"\"><button><h1>STOP</h1> </button></a><br />");  
  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}


