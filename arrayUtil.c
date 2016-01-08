#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ArrayUtil create(int typeSize, int length){
  ArrayUtil *new;
  new = (ArrayUtil *)malloc(sizeof(ArrayUtil));
  new->base = calloc(length,typeSize);
  new->length = length;
  new->typeSize = typeSize;
  return *new;
}

int areEqual(ArrayUtil a, ArrayUtil b){
  if (a.typeSize == b.typeSize && a.length == b.length && (memcmp(a.base,b.base,a.typeSize)==0))
    return 1;
  return 0;
}

ArrayUtil resize(ArrayUtil util, int length){
  ArrayUtil *new;
  new = realloc(util.base,length);
  new->length = length;
  return *new;
}

void dispose(ArrayUtil util){
  free(util.base);
}

int findIndex(ArrayUtil util,void *element){
  void *base = (void *)util.base;
   for (int index = 0; index < util.length; index++) {
     if (memcmp(base,element,util.typeSize)==0)
       return index;
     base+=util.typeSize;
   }
   return -1;
}
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
  void *base = (void *)util.base;
  for (int index = 0; index < util.length; index++) {
    if (match(hint,base)==1){
      return base;
    }
    base+=util.typeSize;
  }
  return NULL;
}
void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
  void *base = (void *)util.base + (util.length-1 * util.typeSize);
  for (int index = 0; index < util.length; index++) {
    if (match(hint,base)==1){
      return base;
    }
    base-=util.typeSize;
  }
  return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
  int count = 0;
  void *base = (void *)util.base;
  for (int index = 0; index < util.length; index++) {
    if (match(hint,base)==1){
      count++;
    }
    base+=util.typeSize;
  }
  return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
  int count = 0;
  void *base = (void *)util.base;
  void **dest = destination;
  for (int index = 0; index < util.length; index++) {
    if (match(hint,base)==1 && count<maxItems){
      *dest = base;
      count++;
      dest++;
    }
    base+=util.typeSize;
  }
  return count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
  void *sourceBase = (void *)source.base;
  void *destinationBase = (void *)destination.base;
  for (int index = 0; index < source.length; index++) {
        convert(hint,sourceBase,destinationBase);
        sourceBase+=source.typeSize;
        destinationBase+=destination.typeSize;
    }
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
  void *base = (void *)util.base;
  for (int index = 0; index < util.length; index++) {
        operation(hint,base);
        base+=util.typeSize;
    }
}
