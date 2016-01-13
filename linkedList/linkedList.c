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

void* getElementAt(LinkedList list,int index_no){
  int count = 0;
  Element *start = list.head;
  if (index_no >= list.number_of_elements)
    return NULL;
  while( start!= NULL ) {
    if (index_no == count)
      return start->value;
		start = start->next;
    count++;
	}
  return NULL;
}

int indexOf(LinkedList list, void *item){
  int count = 0;
  Element *start = list.head;
  while( start!= NULL ) {
    if (start->value==item)
      return count;
		start = start->next;
    count++;
	}
  return -1;
}

void * deleteElementAt(LinkedList *list, int index_no){
  int count = 0;
  Element *previous;
  Element *temp = list->head;
  while (temp != NULL) {
    if (index_no == count) {
      if (index_no == 0) {
        list->head = temp->next;
        (list->number_of_elements)--;
        return temp->value;
      }
      if(index_no == list->number_of_elements-1){
        previous->next = NULL;
        return temp->value;
      }
      previous->next = temp->next;
      (list->number_of_elements)--;
      return temp->value;
    }
    previous = temp;
    temp = temp->next;
    count++;
  }
  return NULL;
}
