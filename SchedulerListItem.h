#ifndef _FKR_SCHEDULER_LIST_ITEM_H_
#define _FKR_SCHEDULER_LIST_ITEM_H_

typedef unsigned long timeType;

#include "Arduino.h"

namespace FKR {
  class SchedulerListItem {
    public:
      timeType runAt = 0;
      virtual void run() = 0;
  };
}

#endif _FKR_SCHEDULER_LIST_ITEM_H_
