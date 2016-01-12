typedef struct element{
  void *value;
  struct element *next;
}Element;
typedef struct{
  Element *head;
  Element *tail;
  int number_of_elements;
}LinkedList;

LinkedList createList(void);
int add_to_list(LinkedList *,void *);
