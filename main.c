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
  assert(1 == areEqual(a,b));
  assert(0 == areEqual(a,c));
  assert(0 == areEqual(b,c));
}
void test_resize() {
  ArrayUtil util = create(2,4);
  util = resize(util,6);
  assert(6 == util.length);
}
int main(void) {
  test_create();
  test_areEqual();
  test_resize();
  return 0;
}
