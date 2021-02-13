/*
  Blink
*/
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

String apiKeyIn = "xxxxx"; // ThingSpeak API Key
const unsigned int writeInterval = 25000; // write interval (in ms)

HTTPClient ask;
WiFiMulti wifiMulti;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin ledPin as an output.
  pinMode(14, INPUT);
  delay(1000);
  Serial.begin(9600);
  wifiMulti.addAP("Wifi", "password");
  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  // connected
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// the loop function runs over and over again forever
void loop() {
  long state = digitalRead(14);
  Serial.println(state);
  delay(100);
  if((wifiMulti.run() == WL_CONNECTED) && state == 1) {
         // Create a URL for updating module 1 and module2 request
         String url = "https://api.thingspeak.com/update?api_key=";
         url += apiKeyIn;
         url += "&field1=";
         url += state;
         Serial.print("********** requesting URL: ");
         Serial.println(url);
          
         ask.begin(url); //Specify the URL
         //Check for the returning code
         int httpCode = ask.GET();
         if (httpCode > 0) {
            String payload = ask.getString();
            Serial.println(httpCode);
            Serial.println(payload);
         } else {
            Serial.println("Error on HTTP request");
         }
         ask.end(); //End
         Serial.println("********** End ");
         Serial.println("*****************************************************");
         delay(writeInterval); // delay
  } else {
         delay(100);
  }
  
}
