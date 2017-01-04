#ifndef _FKR_SCHEDULER_TASK_LIST_ITEM_CPP_
#define _FKR_SCHEDULER_TASK_LIST_ITEM_CPP_

#include "SchedulerTaskListItem.h"

namespace FKR {
  void SchedulerTaskListItem::run() {
    this->func->run();
  }
}

#endif _FKR_SCHEDULER_TASK_LIST_ITEM_CPP_
