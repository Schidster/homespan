struct DEV_SWITCH : Service::Switch {

  int ledPin;
  SpanCharacteristic* power;

  DEV_SWITCH(int ledPin) : Service::Switch() {

    power = new Characteristic::On();
    this->ledPin = ledPin;
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
  }

  boolean update() {
    digitalWrite(ledPin, (int)!(power->getNewVal<bool>()));
    return(true);
  }

};