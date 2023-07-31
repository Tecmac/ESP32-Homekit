

#include "HomeSpan.h"
#include "Dev_Light.h"

const int ledPin = 1; // Relay Lamp
const int togglePinOut = 4; // Manual Toggle Button out
const int togglePinIn = 3; // Manual Toggle Button in

void setup() {
  Serial.begin(115200);

  homeSpan.begin(Category::Lighting, "E.K. Lights"); 
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new Dev_Light(ledPin); 

  pinMode(togglePinOut, OUTPUT);
  pinMode(togglePinIn, INPUT);
}

void loop() {
  homeSpan.poll();
}
