#include "HomeSpan.h"

#include "DEV_LED.h"
#include "DEV_SWITCH.h"

void setup() {
  Serial.begin(115200);

  homeSpan.begin(Category::Bridges, "Controller");


  new SpanAccessory();

    new Service::AccessoryInformation();
      new Characteristic::Identify();

  new SpanAccessory();

    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Board LED");
    
    new DEV_LED(2);


  new SpanAccessory();

    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Light 1");

    new DEV_SWITCH(25);


  new SpanAccessory();

    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Light 2");

    new DEV_SWITCH(26);


  new SpanAccessory();

    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Fan 1");

    new DEV_SWITCH(27);
      

  homeSpan.autoPoll();
}

void loop() {

}
