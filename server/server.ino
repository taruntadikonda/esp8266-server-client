#include<WiFiClient.h> 
#include<ESP8266WebServer.h>`
int value1;

const char *ssid = "*******";     //intilize the server ssid
const char *password = "********";  //password of server

ESP8266WebServer server(80);
int sensor()
{
  value1=digitalRead(13);
  return value1;
}
void handle_data()  //handler function
{
  sensor();
  digitalWrite(2, 1);
  server.send(200, "text/plain", String(value1)); //sending data to url
}


void setup() {
  
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();
  Serial.println("HTTP server started");
  server.on("/data",handle_data);
  
}

void loop() {
  server.handleClient();
}
