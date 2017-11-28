#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "********";   //server ssid
const char* password = "*********";  //server password
const char* host = "http://192.168.4.1"; //deault ip address
HTTPClient http;

void rptaSrv(int httpCode){
  if(httpCode == 200) {
           String payload = http.getString();
           Serial.println(payload);
        } else {
            Serial.print("[HTTP] GET... failed, no connection or no HTTP server\n");
        }
}

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println("proyecto inv client-server");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);  //sin esta no funciona
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop(){
if(WiFi.status() != WL_CONNECTED){
  WiFi.begin(ssid, password);
  delay(500);
}else{
  //HTTPClient http;
        Serial.print("[HTTP] begin...\n");
        
        int a=http.begin("192.168.4.1", 80, "/data"); //pinging the url
        int httpCode1 = http.GET();
        Serial.println(a);
        if(a==1)
        {
          //actions
        }
        else
        {
          //actions
        }
        
        rptaSrv(httpCode1);
        delay(1000);
        }
}
