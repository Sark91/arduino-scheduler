#ifndef _FKR_LIST_CPP_
#define _FKR_LIST_CPP_

#include "List.h"

namespace FKR {
  template <typename T> List<T>::List() {};

  template <typename T> void List<T>::checkFirst(ListItem<T> *item) {
    if (item == this->first) {
      this->first = item->next;
    }
  }
  
  template <typename T> void List<T>::checkLast(ListItem<T> *item) {
    if (item == this->last) {
      this->last = item->prev;
    }
  }
  
  template <typename T> void List<T>::append(T item) {
    ListItem<T> *li = new ListItem<T>();
  
    if (this->size == 0) {
      this->first = li;
      this->last = li;
    } else {
      this->last->next = li;
      li->prev = this->last;
      this->last = li;
    }
      
    li->item = item;
    li->parent = this;
    this->size++;
  }
  
  template <typename T> ListItem<T> *List<T>::getFirst() {
    return this->first;
  }
  
  template <typename T> unsigned int List<T>::getSize() {
    return this->size;
  }
}

#endif _FKR_LIST_CPP_
