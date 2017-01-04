#ifndef _FKR_LIST_ITEM_H_
#define _FKR_LIST_ITEM_H_

#include "Arduino.h"

namespace FKR {
  template <typename T> class List;
	
  template <typename T> class ListItem {
    public:
      T item = NULL;
      ListItem<T> *prev = NULL;
      ListItem<T> *next = NULL;
      List<T> *parent = NULL;
  
      void remove();
	};
}

#include "ListItem.cpp"

#endif _FKR_LIST_ITEM_H_