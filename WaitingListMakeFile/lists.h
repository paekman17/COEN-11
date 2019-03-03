/*Ethan Paek, November 15th, 2017
Lab #9
Lab Section 3 (Wednesdays)
*/
//lists.h which defines all of the functions to change the linked list
#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_list{
  int data;
  char name[20];
  struct node_list* next;
  struct node_list* prev;
}node;

void insert(char *nodeName, int party);
void delete(int input);
void print();
void change();
void deleteAll();
void reverse();
void changePointers(node* temp);

node* head[4];
node* tail[4];

#endif
