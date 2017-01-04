#ifndef _FKR_SCHEDULER_FUNC_LIST_ITEM_H_
#define _FKR_SCHEDULER_FUNC_LIST_ITEM_H_

#include "Arduino.h"
#include "SchedulerListItem.h"

namespace FKR {
  class SchedulerFuncListItem : public SchedulerListItem {
    public:
      void (*func)() = NULL;
	  virtual void run();
  };
}

#endif _FKR_SCHEDULER_FUNC_LIST_ITEM_H_