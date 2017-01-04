#ifndef _FKR_DHT_CONTROLLER_H_
#define _FKR_DHT_CONTROLLER_H_

#include "Arduino.h"
#include <Scheduler.h>
#include <SchedulerTask.h>
#include <DHT.h>

namespace FKR {
  class DHTController : public SchedulerTask {
    protected:
      int dhtType;
      int dhtPin;
      int receiveTimeMS;
			void (*prepareCallback)() = NULL;
			void (*dataCallback)(float, float) = NULL;
			bool isReceiving;
			bool isRepeating;
			bool isStarted;
			DHT *dht;
			float humidity;
			float temperature;

		
    public:
		  DHTController(int, int, int);
		  void setPrepareCallback(void (*)());
		  void setDataCallback(void (*)(float, float));
		  void start();
		  void start(bool);
		  void stop();
		  virtual void run();
//	  void setBlink(unsigned long lowTimeoutMS, unsigned long highTimeoutMS);
//	  void start();
//	  void start(int percentage);
//	  void stop();
  };
}

#endif _FKR_DHT_CONTROLLER_H_