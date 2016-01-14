typedef struct element{
  void *value;
  struct element *next;
}Element;
typedef struct{
  Element *head;
  Element *tail;
  int number_of_elements;
}LinkedList;
typedef void (*ElementProcessor)(void*);


LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void forEach(LinkedList, ElementProcessor);
void *getElementAt(LinkedList,int);
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int);
