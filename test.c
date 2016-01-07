#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arrayUtil.h"

int isDivisible(void* hint, void* item){
  int *h = (int *)hint;
  int *i = (int *)item;
  if (*i % *h == 0) {
    return 1;
  }
  return 0;
}
void test_create(){
  ArrayUtil util = create(2,4);
  assert(util.length == 4);
  assert(util.typeSize == 2);
}
void test_areEqual() {
  ArrayUtil a = create(2,4);
  ArrayUtil b = create(2,4);
  ArrayUtil c = create(3,6);
  assert(1 == areEqual(a,a));
  assert(1 == areEqual(a,b));
  assert(0 == areEqual(a,c));
  assert(0 == areEqual(b,c));
}
void test_resize() {
  ArrayUtil util = create(2,4);
  util = resize(util,6);
  assert(6 == util.length);
}
void test_findIndex(){
  ArrayUtil a = create(sizeof(int),5);
  int *new = (int *)a.base;
  new[1] = 23;
  new[3] = 17;
  int num1 = 17;
  int num2 = 23;
  assert(findIndex(a,&num2)==1);
  assert(findIndex(a,&num1)==3);
}

void test_findFirst_if_value_exist() {
  int hint = 3;
  ArrayUtil a = create(sizeof(int),5);
  int *new = (int *)a.base;
  new[0] = 19;
  new[1] = 21;
  new[3] = 18;
  int *result = findFirst(a,&isDivisible,&hint);
  assert(21 == *result);
}
void test_findFirst_if_value_not_exist() {
  int hint = 3;
  ArrayUtil a = create(sizeof(int),5);
  int *new = (int *)a.base;
  new[0] = 10;
  new[1] = 25;
  new[2] = 20;
  new[3] = 11;
  int *result = findFirst(a,&isDivisible,&hint);
  assert(0 == *result);
}
void test_findLast() {
  int hint = 3;
  ArrayUtil a = create(sizeof(int),4);
  int *new = (int *)a.base;
  new[0] = 15;
  new[1] = 21;
  new[2] = 2;
  new[3] = 15;
  int *result = findLast(a,&isDivisible,&hint);
  assert(15 == *result);
}
void test_count(){
  int hint = 3;
  ArrayUtil a = create(sizeof(int),4);
  int *new = (int *)a.base;
  new[0] = 12;
  new[1] = 21;
  new[2] = 2;
  new[3] = 18;
  int result = count(a,&isDivisible,&hint);
  assert(3 == result);
}
void test_filter_no_match_element() {
  int hint = 3;
  int maxItems = 4;
  ArrayUtil a = create(sizeof(int),4);
  int *new = (int *)a.base;
  new[0] = 10;
  new[1] = 20;
  new[2] = 2;
  new[3] = 11;
  ArrayUtil b = create(sizeof(int),maxItems);
  int result = filter(a,&isDivisible,&hint,b.base,maxItems);
  assert(0 == result);
}
void test_filter_match_element() {
  int hint = 3;
  int maxItems = 4;
  ArrayUtil a = create(sizeof(int),4);
  int *new = (int *)a.base;
  new[0] = 10;
  new[1] = 21;
  new[2] = 2;
  new[3] = 18;
  ArrayUtil b = create(sizeof(int*),maxItems);
  int **newb = (int **)b.base;
  int result = filter(a,&isDivisible,&hint,b.base,maxItems);
  assert(2 == result);
  assert(21 == *newb[0]);
  assert(18 == *newb[1]);
}
void convert_plus(void* hint, void* sourceItem, void* destinationItem){
  int *h = (int *)hint;
  int *s = (int *)sourceItem;
  int *dest = (int *)destinationItem;
  int value = *h + *s;
  *dest = value;
}
void test_map(){
  int hint = 3;
  ArrayUtil a = create(sizeof(int),4);
  ArrayUtil b = create(sizeof(int),4);
  int *newA = (int *)a.base;
  newA[0] = 10;
  newA[1] = 21;
  newA[2] = 2;
  newA[3] = 18;
  int *newB = (int *)b.base;
  map(a,b, &convert_plus,&hint);
  assert(13 == newB[0]);
  assert(24 == newB[1]);
  assert(5 == newB[2]);
  assert(21 == newB[3]);
}
