#include <ESP8266WiFi.h>

//WiFi hotspot username and password
const char* ssid = "Redmi";
const char* password = "test1234";

//WiFi connection idicators
int ledPin = 5; // D1


//NodeMCU and Arduino pinout
int ledg = 14;//D5
int ledr = 12;//D6
int ledy = 13;//D7
int ledb = 15;//D8
 
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);

//WiFi connection idicators
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
//LED colour indicators
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
  digitalWrite(ledPin, HIGH);
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

  //GREEN LED
  if (request.indexOf("/GREEN-ON") != -1 )  {
    digitalWrite (ledg,HIGH);
  }
  if (request.indexOf("/GREEN-OFF") != -1 )  {
    digitalWrite (ledg,LOW);
  }

  //RED LED
  if (request.indexOf("/RED-ON") != -1 )  {
    digitalWrite (ledr,HIGH);
  }
  if (request.indexOf("/RED-OFF") != -1 )  {
    digitalWrite (ledr,LOW);
  }


   //YELLOW LED
  if (request.indexOf("/YELLOW-ON") != -1 )  {
    digitalWrite (ledy,HIGH);
  }
  if (request.indexOf("/YELLOW-OFF") != -1 )  {
    digitalWrite (ledy,LOW);
  }

  //BLUE LED
  if (request.indexOf("/BLUE-ON") != -1 )  {
    digitalWrite (ledb,HIGH);
  }
  if (request.indexOf("/BLUE-OFF") != -1 )  {
    digitalWrite (ledb,LOW);
  }


  //BLUE LED
  if (request.indexOf("/START-ALL") != -1 )  {
    digitalWrite (ledg,HIGH);
    digitalWrite (ledr,HIGH);
    digitalWrite (ledy,HIGH);
    digitalWrite (ledb,HIGH);
  }
  if (request.indexOf("/STOP-ALL") != -1 )  {
    digitalWrite (ledg,LOW);
    digitalWrite (ledr,LOW);
    digitalWrite (ledy,LOW);
    digitalWrite (ledb,LOW);
  }


// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 

  
  client.println("<br><br>");
  client.println("<a href=\"/GREEN-ON\"\"><button><h1>GREEN-ON</h1> </button></a>");
  client.println("<a href=\"/GREEN-OFF\"\"><button><h1>GREEN-OFF</h1> </button></a><br />");
  client.println("<a href=\"/RED-ON\"\"><button><h1>RED-ON</h1> </button></a>");  
  client.println("<a href=\"/RED-OFF\"\"><button><h1>RED-OFF</h1> </button></a><br />");  
  client.println("<a href=\"/YELLOW-ON\"\"><button><h1>YELLOW-ON</h1></button></a>");  
  client.println("<a href=\"/YELLOW-OFF\"\"><button><h1>YELLOW-OFF</h1></button></a><br />");  
  client.println("<a href=\"/BLUE-ON\"\"><button><h1>BLUE-ON</h1> </button></a>");
  client.println("<a href=\"/BLUE-OFF\"\"><button><h1>BLUE-OFF</h1> </button></a><br />");
  client.println("<a href=\"/START-ALL\"\"><button><h1>START-ALL</h1> </button></a>");  
  client.println("<a href=\"/STOP-ALL\"\"><button><h1>STOP-ALL</h1> </button></a><br />");  
  
  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}

