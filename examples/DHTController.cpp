#ifndef _FKR_DHT_CONTROLLER_CPP_
#define _FKR_DHT_CONTROLLER_CPP_

#include "DHTController.h"

namespace FKR {
	DHTController::DHTController(int dhtPin, int dhtType, int receiveTimeMS) {
	  this->dhtType = dhtType;
	  this->dhtPin = dhtPin;
	  this->receiveTimeMS = receiveTimeMS;
	  this->dht = new DHT(dhtPin, dhtType);
	  this->dht->begin();
	}

	void DHTController::setPrepareCallback(void (*prepareCallback)()) {
		this->prepareCallback = prepareCallback;
	}

	void DHTController::setDataCallback(void (*dataCallback)(float temperature, float humidity)) {
		this->dataCallback = dataCallback;
	}

  void DHTController::start() {
    this->start(false);
  }

  void DHTController::start(bool repeat) {
		this->isRepeating = repeat;
		this->isStarted = true;
		Scheduler::schedule(this, 0);
  }

  void DHTController::stop() {
    this->isStarted = false;
  }

  void DHTController::run() {
    if (!this->isStarted) return;

    if (!this->isReceiving) {
      if (this->prepareCallback) {
        this->prepareCallback();
      }

			this->temperature = this->dht->readTemperature();
			this->humidity = this->dht->readHumidity();
			this->isReceiving = true;
			Scheduler::schedule(this, this->receiveTimeMS);
    } else {
      this->humidity = this->dht->readHumidity();
      this->temperature = this->dht->readTemperature();
      this->isReceiving = false;

      if (this->dataCallback) {
        this->dataCallback(this->temperature, this->humidity);
      }

      if (this->isRepeating) {
        Scheduler::schedule(this, 0);
      }
    }
  }
}

#endif _FKR_DHT_CONTROLLER_CPP_