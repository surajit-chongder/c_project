#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arrayUtil.h"

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
int isDivisible(void* hint, void* item){
  int *h = (int *)hint;
  int *i = (int *)item;
  if (*i % *h == 0) {
    return 1;
  }
  return 0;
}

void test_findFirst() {
  int hint = 3;
  ArrayUtil a = create(sizeof(int),5);
  int *new = (int *)a.base;
  new[0] = 19;
  new[1] = 21;
  new[3] = 18;
  int *result = findFirst(a,&isDivisible,&hint);
  assert(21 == *result);
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
int main(void) {
  test_create();
  test_areEqual();
  test_resize();
  test_findIndex();
  test_findFirst();
  test_findLast();
  test_count();
  return 0;
}
