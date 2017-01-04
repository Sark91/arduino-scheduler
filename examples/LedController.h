#ifndef _FKR_LED_CONTROLLER_H_
#define _FKR_LED_CONTROLLER_H_

#include "Arduino.h"
#include <Scheduler.h>
#include <SchedulerTask.h>

namespace FKR {
  class LedController : public SchedulerTask {
    protected:
		int led;
		bool isHigh;
		bool isBlinkEnabled;
		unsigned long lowTimeoutMS;
		unsigned long highTimeoutMS;
		
		
    public:
	  LedController(int led);
	  virtual void run();
	  void setBlink(unsigned long lowTimeoutMS, unsigned long highTimeoutMS);
	  void start();
	  void start(int percentage);
	  void stop();
	  void setState(int);
  };
}

#endif _FKR_LED_CONTROLLER_H_