// ****************************************************************** 
// COMP-10184 
// External LED Wiring, PIR Sensor Test Program 
// 
// @author Mohawk College 

//I, Noe Puna, 000781646, I acknowledge that this my own work and no other
// person's work has been copied without acknowledgement.
 
#include <Arduino.h> 
#include <ESP8266WiFi.h> 
 
// pin assignments for external LEDs 
#define PIN_LED_GREEN   D1 
#define PIN_LED_YELLOW  D2 
#define PIN_LED_RED     D3 

const char* ssid = "xxxxx"; 
const char* password = "xxxxx"; 

WiFiServer server(80); 
 
// pin assignment for PIR input 
#define PIN_PIR         D5  
 
void setup() { 
  // setup LED outputs 
  pinMode(PIN_LED_GREEN, OUTPUT); 
  pinMode(PIN_LED_YELLOW, OUTPUT); 
  pinMode(PIN_LED_RED, OUTPUT); 
 
  // setup PIR input 
  pinMode(PIN_PIR, INPUT); 
 
  // built-in LED 
  pinMode(LED_BUILTIN, OUTPUT); 

  Serial.println("Noe Puna, 000781646");

  Serial.printf("\nConnecting to %s ", ssid); 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) 
  { 
    delay(500); 
    Serial.print("."); 
  } 
  Serial.println(" connected"); 
 
  server.begin(); 
  Serial.printf("Web server started, open %s in a web browser\n", 
WiFi.localIP().toString().c_str()); 
} 
 
void loop() { 
  // cycle through LED colours, one at a time.. 
  // GREEN ON 
  // digitalWrite(PIN_LED_GREEN, HIGH); 
  // digitalWrite(PIN_LED_YELLOW, LOW); 
  // digitalWrite(PIN_LED_RED, LOW); 
  // delay(200); 
  // // YELLOW 
  // digitalWrite(PIN_LED_GREEN, LOW); 
  // digitalWrite(PIN_LED_YELLOW, HIGH); 
  // digitalWrite(PIN_LED_RED, LOW); 
  // delay(200); 
  // // RED 
  // digitalWrite(PIN_LED_GREEN, LOW); 
  // digitalWrite(PIN_LED_YELLOW, LOW); 
  // digitalWrite(PIN_LED_RED, HIGH); 
  // delay(200); 
 
  // echo PIR input to built-in LED OUTPUT (note: invert the sense of the PIR sensor!) 
  digitalWrite(LED_BUILTIN, !digitalRead(PIN_PIR)); 

  while (WiFi.status() != WL_CONNECTED) 
  { 
    digitalWrite(PIN_LED_GREEN, LOW); 
    digitalWrite(PIN_LED_YELLOW, HIGH); 
  } 

  while (!(WiFi.status() != WL_CONNECTED)){

  digitalWrite(PIN_LED_GREEN, HIGH); 
  digitalWrite(PIN_LED_YELLOW, LOW); 
  digitalWrite(PIN_LED_RED, LOW);

  // If motion detected
  if(digitalRead(PIN_PIR)){
    Serial.println("LOG: 1");
    digitalWrite(PIN_LED_RED, HIGH);
    delay(2000);
    digitalWrite(PIN_LED_RED, LOW);
  }
  }
} 