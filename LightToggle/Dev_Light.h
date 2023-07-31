
////////////////////////////////////
//   DEVICE-SPECIFIC LED SERVICES //
////////////////////////////////////


struct Dev_Light : Service::LightBulb {  // ON/OFF LED
  const int ledPin;                      // pin number defined for this LED
  SpanCharacteristic *power;             // reference to the On Characteristic
  int currentState;
  Dev_Light( int ledPin)
    : Service::LightBulb(), ledPin(ledPin) {  // constructor() method
    
    power = new Characteristic::On();
    currentState = digitalRead(3);

    pinMode(ledPin, OUTPUT);
  }

  boolean update() {
    digitalWrite(ledPin, power->getNewVal());
    return (true);
  }
  void loop() {
    int newSwitchState = digitalRead(3);

    if (currentState != newSwitchState) {
      currentState = newSwitchState;
      power->setVal(!power->getVal()); // Toggle the power value
      digitalWrite(ledPin, power->getNewVal());
    }
  }
};
