#ifndef _FKR_SCHEDULER_TASK_LIST_ITEM_H_
#define _FKR_SCHEDULER_TASK_LIST_ITEM_H_

#include "Arduino.h"
#include "SchedulerListItem.h"
#include "SchedulerTask.h"

namespace FKR {
  class SchedulerTaskListItem : public SchedulerListItem {
    public:
      SchedulerTask *func = NULL;
	  virtual void run();
  };
}

#endif _FKR_SCHEDULER_TASK_LIST_ITEM_H_