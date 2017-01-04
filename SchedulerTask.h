#ifndef _FKR_SCHEDULER_TASK_H_
#define _FKR_SCHEDULER_TASK_H_

#include "Arduino.h"

namespace FKR {
  class SchedulerTask {
    public:
      virtual void run() = 0;
  };
}

#endif _FKR_SCHEDULER_TASK_H_