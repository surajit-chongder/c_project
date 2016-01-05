#include "arrayUtil.h"
#include <stdlib.h>

ArrayUtil create(int typeSize, int length){
  ArrayUtil *array;
  array = (ArrayUtil *)calloc(length, typeSize);;
  array->base = array;
  array->length = length;
  array->typeSize = typeSize;
  return *array;
}

int areEqual(ArrayUtil a, ArrayUtil b){
  if (a.typeSize == b.typeSize && a.length == b.length)
    return 1;
  return 0;
}

ArrayUtil resize(ArrayUtil util, int length){
  ArrayUtil *new;
  new = realloc(util.base,length);
  new->length = length;
  return *new;
}
