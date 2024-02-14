#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

struct node {
  unsigned int data;
  struct node * next;
};

typedef struct node Node;

struct list {
  Node * head;
};

typedef struct list List;

List * makelist();
void add(unsigned int data, List * list);
void add_node(Node * node, List * list);
void delete_node(unsigned int data, List * list);
void display(List * list);
void reverse(List * list);
void reverse_using_two_pointers(List * list);
unsigned int find(unsigned int data, List * list);
void destroy(List * list);

#endif
