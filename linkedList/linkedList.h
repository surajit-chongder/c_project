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
typedef int(MatchFunc)(void*,void*);
typedef void(ConvertFunc)(void*,void*,void*);
typedef void* (Reducer)(void*,void*,void*);



LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void forEach(LinkedList, ElementProcessor);
void *getElementAt(LinkedList,int);
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int);
LinkedList  filter(LinkedList, MatchFunc, void * );
LinkedList reverse(LinkedList);
LinkedList map(LinkedList, ConvertFunc, void * );
void *reduce(LinkedList, Reducer, void *, void *);
