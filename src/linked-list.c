#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

Node * createnode(unsigned int data);

Node * createnode(unsigned int data){
  Node * newNode = malloc(sizeof(Node));
  if (!newNode) {
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

List * makelist(){
  List * list = malloc(sizeof(List));
  if (!list) {
    return NULL;
  }
  list->head = NULL;
  return list;
}

void display(List * list) {
  Node * current = list->head;
  if(list->head == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    printf("%d\n", current->data);
  }
}

unsigned int find(unsigned int data_in, List * list){
  Node * current = list->head;
  if(list->head == NULL)
    return 0;

  for(; current != NULL; current = current->next) {
    if (current -> data = data_in)
	    return 1;
  }
  return 0;
}

void add_node(Node * node, List * list){
  Node * current = NULL;
  if(list->head == NULL){
    list->head = node;
  }
  else {
    current = list->head;
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = node;
  }
  node -> next = NULL;
}

void add(unsigned int data, List * list){
  Node * current = NULL;
  if(list->head == NULL){
    list->head = createnode(data);
  }
  else {
    current = list->head; 
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(data);
  }
}

void delete_node(unsigned int data, List * list){
  Node * current = list->head;            
  Node * previous = current;           
  while(current != NULL){           
    if(current->data == data){      
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }                               
    previous = current;             
    current = current->next;        
  }                                 
}                                   

void reverse(List * list){
  Node * reversed = NULL;
  Node * current = list->head;
  Node * temp = NULL;
  while(current != NULL){
    temp = current;
    current = current->next;
    temp->next = reversed;
    reversed = temp;
  }
  list->head = reversed;
}
//Reversing the entire list by changing the direction of link from forward to backward using two pounsigned inters
void reverse_using_two_pointers(List *list){
    Node *previous = NULL;
    while (list->head)
    {
        Node *next_node = list->head->next; //pounsigned ints to second node in list
        list->head->next = previous;//at initial making head as NULL
        previous = list->head;//changing the nextpounsigned inter direction as to pounsigned int backward node 
        list->head = next_node; //moving forward by next node
    }
    list->head=previous;
}
void destroy(List * list){
  Node * current = list->head;
  Node * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}
