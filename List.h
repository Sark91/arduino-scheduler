#ifndef _FKR_LIST_H_
#define _FKR_LIST_H_

#include "Arduino.h"
#include "ListItem.h"

namespace FKR {
  template <typename T> class List {
    protected:
      unsigned int size = 0;
      ListItem<T> *first = NULL;
      ListItem<T> *last = NULL;

    public:
      List();
      void checkFirst(ListItem<T> *item);
      void checkLast(ListItem<T> *item);
      void append(T item);
      ListItem<T> *getFirst();
      unsigned int getSize();
  };
}

#include "List.cpp"
#endif _FKR_LIST_H_