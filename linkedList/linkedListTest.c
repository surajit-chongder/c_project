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

void test_asArray(){
  int maxElements = 4;
  int item = 15;
  int secondItem = 23;
  int thirdItem = 29;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  void* storingArray[maxElements] ;
  int result = asArray(list,storingArray,maxElements);
  assert(result == 3);
  assert(15 == *(int*)storingArray[0]);
  assert(23 == *(int*)storingArray[1]);
  assert(29 == *(int*)storingArray[2]);
}

int isDivisible(void* hint, void* item){
  int *h = (int *)hint;
  int *i = (int *)item;
  if (*i % *h == 0) {
    return 1;
  }
  return 0;
}

void test_filter(){
  int hint = 3;
  int maxElements = 4;
  int item = 15;
  int secondItem = 23;
  int thirdItem = 30;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  LinkedList result = filter(list,isDivisible,&hint);
  assert(*(int *)result.head->value == 15);
  assert(*(int *)result.tail->value == 30);
}

void convert_plus(void* hint, void* sourceItem, void* destinationItem){
  int *h = (int *)hint;
  int *s = (int *)sourceItem;
  int *dest = (int *)destinationItem;
  int value = *h + *s;
  *dest = value;
}

void test_reverse(){
  int maxElements = 4;
  int item = 15;
  int secondItem = 23;
  int thirdItem = 29;
  int forthItem = 34;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  add_to_list(&list,&forthItem);

  LinkedList result = reverse(list);

  int *position1 = getElementAt(result,1);
  int *position2 = getElementAt(result,2);
  assert(*position1 == 29);
  assert(*position2 == 23);

  assert(result.number_of_elements == 4);
  assert(*(int *)result.head->value == 34);
  assert(*(int *)result.tail->value == 15);
}


void test_map(){
  int hint = 3;
  int maxElements = 4;
  int item = 15;
  int secondItem = 23;
  int thirdItem = 30;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  LinkedList result = map(list,convert_plus,&hint);
  assert(*(int *)result.head->value == 18);
  assert(*(int *)result.tail->value == 33);
}

void* reduce_sum(void* hint, void* previousItem, void* item){
  int *h = (int *)hint;
  int *previous = (int *)previousItem;
  int *i = (int *)item;
  *previous+=*i;
  return previous;
}

void test_reduce(){
  int initialValue = 0;
  int hint = 3;
  int maxElements = 4;
  int item = 15;
  int secondItem = 23;
  int thirdItem = 30;
  LinkedList list = createList();
  add_to_list(&list,&item);
  add_to_list(&list,&secondItem);
  add_to_list(&list,&thirdItem);
  void* result =  reduce(list, reduce_sum ,&hint,&initialValue);
  assert(68 == initialValue);
  assert(68 == *(int*)result);
}
