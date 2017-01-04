#include <Scheduler.h>
#include "../LedController.h"
#include "../DHTController.h"

using namespace FKR;

LedController *Biled = new LedController(BUILTIN_LED);
DHTController *dhtcr = new DHTController(D4, DHT11, 11000);

void printPrepare();
void printData();

void printPrepare() {
  Serial.println("Start getting temperature");
  Serial.flush();
  Biled->setBlink(100, 100);
}

void printData(float temperature, float humidity) {
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("*C Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  Serial.flush();
}

void setup() {
  Serial.begin(115200);
  Biled->start();
  dhtcr->start(true);
  dhtcr->setPrepareCallback(&printPrepare);
  dhtcr->setDataCallback(&printData);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(Scheduler::nextTick());
}
