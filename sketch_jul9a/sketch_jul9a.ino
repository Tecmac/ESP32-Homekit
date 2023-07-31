#include "HomeSpan.h" 
#include "Dev_Lamp.h"

void setup() {
    Serial.begin(115200);

  homeSpan.begin(Category::Bridges,"HomeSpan Bridge");

  new SpanAccessory();  
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 

  new SpanAccessory();                                                          
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("PushButton LED");
    
    new Dev_Lamp(17,23,5,18);   
  // put your setup code here, to run once:

}

void loop() {
 
  homeSpan.poll();
}
