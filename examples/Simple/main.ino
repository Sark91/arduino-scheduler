#include <Scheduler.h>

using namespace FKR;

int printACount = 0;
int printBCount = 0;

void printA() {
  Serial.print("A ");
  Serial.println(++printACount);
  Serial.flush();
  Scheduler::schedule(&printA, 50);
}

void printB() {
  Serial.print("B ");
  Serial.println(++printBCount);
  Serial.flush();
  Scheduler::schedule(&printB, 70);
}

void setup() {
	Scheduler::schedule(&printA, 0);
	Scheduler::schedule(&printB, 0);
}

void loop() {
  delay(Scheduler::nextTick());
}
