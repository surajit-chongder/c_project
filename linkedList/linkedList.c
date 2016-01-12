#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LinkedList createList(void){
  LinkedList *list;
  list = (LinkedList *)malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->number_of_elements = 0;
  return *list;
}

int add_to_list(LinkedList *list,void *item){
  Element *e;
  e = (Element *)malloc(sizeof(Element));
  e->value = item;
  e->next = NULL;
  if (list->head == NULL) {
    list->head = list->tail = e;
  }
  else{
    list->tail->next = e;
    list->tail = e;
  }
  list->number_of_elements = ++list->number_of_elements;
  return list->number_of_elements;
}

void *get_first_element(LinkedList list){
  return list.head->value;
}

void *get_last_element(LinkedList list){
  return list.tail->value;
}

void forEach(LinkedList list, ElementProcessor process){
  Element *start = list.head;
  while( start!= NULL ) {
      process(start->value);
			start = start->next;
	}
}
