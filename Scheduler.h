#ifndef _FKR_SCHEDULER_H_
#define _FKR_SCHEDULER_H_

typedef unsigned long timeType;

#include "Arduino.h"
#include "List.h"
#include "SchedulerFuncListItem.h"
#include "SchedulerTaskListItem.h"
#include "SchedulerTask.h"

namespace FKR {
  class Scheduler {
    public:
      static List<SchedulerListItem*> *queue;
	  
    public:
      static void schedule(void (*func)(), timeType _millis);
      static void schedule(SchedulerTask* func, timeType _millis);
	  static timeType nextTick();
	  static unsigned int getQueueSize();
  };
  
  // Scheduler::queue = new List<SchedulerListItem*>();
}
#endif _FKR_SCHEDULER_H_
