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
void test_add_to_list_when_more_element(){
  int item = 15;
  int secondItem = 23;
  LinkedList list = createList();
  add_to_list(&list,&item);
  int result = add_to_list(&list,&secondItem);
  assert(*(int *)list.head->value == 15);
  assert(*(int *)list.tail->value == 23);
  assert(list.number_of_elements == 2);
  assert(result == 2);
}
void test_get_first_element(){
  int item = 15;
  int secondItem = 23;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  int *result = get_first_element(list);
  assert(*result == 15);
}
void test_get_last_element(){
  int item = 15;
  int secondItem = 23;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  int *result = get_last_element(list);
  assert(*result == 23);
}

void increment(void *item){
  int *value = (int *)item;
  *value =  ++(*value);
}
void printList (LinkedList list){
  Element *start = list.head;
  while( start!= NULL ) {
    printf("%d\n",*(int*)start->value);
			start = start->next;
	}
}

void test_forEach(){
  int item = 15;
  int secondItem = 23;
  int thirdItem = 29;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  forEach(list,&increment);
  assert(*(int *)list.head->value == 16);
  assert(*(int *)list.tail->value == 30);
  assert(list.number_of_elements == 3);
}

void test_getElementAt(){
  int item = 15;
  int secondItem = 23;
  int thirdItem = 29;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  int *result = getElementAt(list,1);
  assert(*result == 23);
  int *result2 = getElementAt(list,2);
  assert(*result2 == 29);
  int *result3 = getElementAt(list,3);
  assert(result3 == NULL);
}

void test_indexOf(){
  int searchElement = 13;
  int item = 15;
  int secondItem = 23;
  int thirdItem = 29;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  int result = indexOf(list,&secondItem);
  assert(result == 1);
  int result2 = indexOf(list,&searchElement);
  assert(result2 == -1);
}

void test_delete_element(){
  int item = 15;
  int secondItem = 23;
  int thirdItem = 29;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  int *result = deleteElementAt(&list,1);
  assert(*result == 23);
}
