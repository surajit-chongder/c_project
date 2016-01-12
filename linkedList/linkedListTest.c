#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"

void test_createList(){
  LinkedList list = createList();
  assert(list.head == NULL);
  assert(list.tail == NULL);
  assert(list.number_of_elements == 0);
}

void test_add_to_list(){
  int item = 15;
  LinkedList list = createList();
  int result = add_to_list(&list,&item);
  assert(*(int *)list.head->value == 15);
  assert(*(int *)list.tail->value == 15);
  assert(list.number_of_elements == 1);
}
void listPrint (LinkedList list){
  Element *start = list.head;
  while( start!= NULL )  {
			printf("%d\n",*(int *)start->value);
			start = start->next;
	}
}
void test_add_to_list_when_more_element(){
  int item = 15;
  int secondItem = 23;
  LinkedList list = createList();
  add_to_list(&list,&item);
  int result = add_to_list(&list,&secondItem);
  listPrint(list);
  assert(*(int *)list.head->value == 15);
  assert(*(int *)list.tail->value == 23);
  assert(list.number_of_elements == 2);
  assert(result == 2);
}
