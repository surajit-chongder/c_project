typedef struct{
  void *base;
  int typeSize;
  int length;
}ArrayUtil;

ArrayUtil create(int, int);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize(ArrayUtil, int);
