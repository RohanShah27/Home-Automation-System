#include "ThingSpeak.h"
#include "MQ2.h"
int smokeA0 = D3;
int sensorThres = 200;
const char* ssid = "Ais";
const char* password = "aishwarya19";
unsigned long channel = 559553;
 unsigned int led1 = 1;
unsigned int led2 = 2;
//unsigned int led3 = 3;
bool toggle = false;
bool toggle1 = false;
 
#define USE_WIFI101_SHIELD
#define USE_ETHERNET_SHIELD

#if !defined(USE_WIFI101_SHIELD) && !defined(USE_ETHERNET_SHIELD) && !defined(ARDUINO_SAMD_MKR1000) && !defined(ARDUINO_AVR_YUN) && !defined(ARDUINO_ARCH_ESP8266) && !defined(ARDUINO_ARCH_ESP32)
  #error "Uncomment the #define for either USE_WIFI101_SHIELD or USE_ETHERNET_SHIELD"
#endif

#if defined(ARDUINO_AVR_YUN)
    #include "YunClient.h"
    YunClient client;
#else
  #if defined(USE_WIFI101_SHIELD) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
    // Use WiFi
    #ifdef ARDUINO_ARCH_ESP8266
      #include <ESP8266WiFi.h>
  #elif defined(ARDUINO_ARCH_ESP32)
      #include <WiFi.h>
    #else
      #include <SPI.h>
      #include <WiFi101.h>
    #endif
       // your network password
    int status = WL_IDLE_STATUS;
    WiFiClient  client;
  #elif defined(USE_ETHERNET_SHIELD)
    // Use wired ethernet shield
    #include <SPI.h>
    #include <Ethernet.h>
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
    EthernetClient client;
  #endif
#endif

unsigned long myChannelNumber = 559553;
const char * myReadAPIKey = "TKY11USIM6YL24B3";

void setup() {

   //Serial.begin(115200);
   pinMode(D2, OUTPUT);
  Serial.begin(9600);
   digitalWrite(D2, 0);
  delay(100);
  
  pinMode(D1, OUTPUT);
  pinMode(D6, OUTPUT);
  //pinMode(D3, OUTPUT);
  digitalWrite(D1, 0);
  digitalWrite(D6, 0);
//  digitalWrite(D3, 0);
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);
}

void loop() {
    int Sensor = digitalRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(Sensor);
  // Checks if it has reached the threshold value
  if (Sensor > sensorThres)
  {
    digitalWrite(D2, HIGH);
  }
  else
  {
    digitalWrite(D2, LOW);
   
  }
  delay(100);
  int led_1 = ThingSpeak.readFloatField(channel,led1,myReadAPIKey);
  int led_2 = ThingSpeak.readFloatField(channel,led2,myReadAPIKey);
  //int led_3 = ThingSpeak.readFloatField(channel, led3);

  if(led_1 == 1)
  {
    if(toggle==false)
    {
      toggle=true;
    digitalWrite(D6, 1);
    Serial.println("D6 is On..!");  
      }
    }
  else if(led_1==2){
    digitalWrite(D6, 0);
    toggle= false;
    Serial.println("D6 is Off..!");
  }

  if(led_2 == 1){
    if(toggle1==false)
    {
      toggle1=true;
    digitalWrite(D1, 1);
    Serial.println("D1 is On..!");
    }
    }
  else if(led_2==2) {
    toggle1=false;
    digitalWrite(D1, 0);
    Serial.println("D1 is Off..!");
  }

  /*if(led_3 == 1){
    digitalWrite(D3, 1);
    Serial.println("D3 is On..!");
  }
  else if(led_3 == 0){
    digitalWrite(D3, 0);
    Serial.println("D3 is Off..!");
  }
    */
  Serial.println(led_1);
  Serial.println(led_2);
  //Serial.println(led_3);
  delay(5000);

}
