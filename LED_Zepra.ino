#define BLYNK_PRINT Serial

#include <SPI.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <FastLED.h>

#define BLYNK_PRINT Serial
#define NUM_LEDS 11
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

char auth[] = "d5053a353c924f3895f168db5037f118";
char ssid[] = "";
char pass[] = "";

void setup()
{
  
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);


}


void loop()
{
  Blynk.run();


}


BLYNK_WRITE(V2)
{

int R = param[0].asInt();
int G = param[1].asInt();
int B = param[2].asInt();
Serial.println(R);
Serial.println(G);
Serial.println(B);
for(int i=0;i<NUM_LEDS;i++){

//leds[i].setRGB(R,G,B);
leds[i]=CRGB(R,G,B);
FastLED.show();
}
}


//// This is called for all virtual pins, that don't have BLYNK_WRITE handler
//BLYNK_WRITE_DEFAULT() {
//  Serial.print("input V");
//  Serial.print(request.pin);
//  Serial.println(":");
//  // Print all parameter values
//  for (auto i = param.begin(); i < param.end(); ++i) {
//    Serial.print("* ");
//    Serial.println(i.asString());
//  }
//}

//// This is called for all virtual pins, that don't have BLYNK_READ handler
//BLYNK_READ_DEFAULT() {
//  // Generate random response
//  int val = random(0, 100);
//  Serial.print("output V");
//  Serial.print(request.pin);
//  Serial.print(": ");
//  Serial.println(val);
//  Blynk.virtualWrite(request.pin, val);
//}
