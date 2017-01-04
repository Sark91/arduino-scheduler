#ifndef _FKR_LIST_ITEM_CPP_
#define _FKR_LIST_ITEM_CPP_

#include "ListItem.h"

namespace FKR {
  template <typename T> void ListItem<T>::remove() {
    ListItem<T> *prev = this->prev;
    ListItem<T> *next = this->next;
    if (prev != NULL)  {
      prev->next = next;
    }

    if (next != NULL) {
      next->prev = prev;
    }

    parent->checkFirst(this);
    parent->checkLast(this);

    delete this; 
  }
}

#endif _FKR_LIST_ITEM_CPP_
