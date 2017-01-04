#ifndef _FKR_LED_CONTROLLER_CPP_
#define _FKR_LED_CONTROLLER_CPP_

#include "LedController.h"

namespace FKR {
	LedController::LedController(int led) {
		pinMode(led, OUTPUT);
		this->led = led;
		this->isHigh = false;
		this->isBlinkEnabled = false;
		this->lowTimeoutMS = 0;
		this->highTimeoutMS = 0;
	}
	
	void LedController::run() {
		if (!this->isBlinkEnabled) return;
		
		if (this->isHigh) {
			if (this->highTimeoutMS) {
				digitalWrite(this->led, HIGH);
			}
			Scheduler::schedule(this, this->highTimeoutMS);
		} else {
			if (this->lowTimeoutMS) {
				digitalWrite(this->led, LOW);
			}
			Scheduler::schedule(this, this->lowTimeoutMS);
		}
		
		this->isHigh = !this->isHigh;
	}
	
	void LedController::setBlink(unsigned long lowTimeoutMS, unsigned long highTimeoutMS) {
		this->lowTimeoutMS = lowTimeoutMS;
		this->highTimeoutMS = highTimeoutMS;
	}
	
	void LedController::start() {
		if (this->isBlinkEnabled) return;
		this->isBlinkEnabled = true;
		Scheduler::schedule(this, 0);
	}
	
    void LedController::start(int percentage) {
    	this->setBlink(
			(20 * percentage / 100),
			20 - (20 * percentage / 100)
		);
		this->start();
    }
	
	void LedController::stop() {
		this->isBlinkEnabled = false;
	}

	void LedController::setState(int state) {
	  digitalWrite(this->led, state);
	}
}

#endif _FKR_LED_CONTROLLER_CPP_