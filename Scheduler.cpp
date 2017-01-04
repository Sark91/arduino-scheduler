#ifndef _FKR_SCHEDULER_CPP_
#define _FKR_SCHEDULER_CPP_

#include "Scheduler.h"

namespace FKR {
  List<SchedulerListItem*>* Scheduler::queue = new List<SchedulerListItem*>();

  void Scheduler::schedule(void (*func)(), timeType _millis) {
     SchedulerFuncListItem* task = new SchedulerFuncListItem();
    
     task->runAt = millis() + _millis;
     task->func = func;
    
     Scheduler::queue->append(task);
  }
  
  void Scheduler::schedule(SchedulerTask* func, timeType _millis) {
    SchedulerTaskListItem* task = new SchedulerTaskListItem();
    
    task->runAt = millis() + _millis;
    task->func = func;
    
    Scheduler::queue->append(task);
  }
  
  timeType Scheduler::nextTick() {
    ListItem<SchedulerListItem*> *it = Scheduler::queue->getFirst();
    ListItem<SchedulerListItem*> *itProc;
    timeType min = 20;
    timeType _millis = millis();

    while (it != NULL) {
      if (_millis >= it->item->runAt) {
        itProc = it;
        itProc->item->run();
        delete itProc->item;
        itProc->remove();
      }
      else if(it->item->runAt - _millis <= min) {
        min = it->item->runAt - _millis;
      }

      it = it->next;
    }

    return min;
  }
  
  unsigned int Scheduler::getQueueSize() {
    return Scheduler::queue->getSize();
  }
}

#endif _FKR_SCHEDULER_CPP_
