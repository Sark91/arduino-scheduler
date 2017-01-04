#ifndef _FKR_SCHEDULER_FUNC_LIST_ITEM_CPP_
#define _FKR_SCHEDULER_FUNC_LIST_ITEM_CPP_

#include "SchedulerFuncListItem.h"

namespace FKR {
  void SchedulerFuncListItem::run() {
    (this->func)();
  }
}

#endif _FKR_SCHEDULER_FUNC_LIST_ITEM_CPP_
