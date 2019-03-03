/*
Ethan Paek, October 18th, 2017; this is a program designed as a restaurant waiting list to be used with a linear linked list
Lab #5
Lab Section 3 (Wednesdays)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_list{
  int data;
  char name[20];
  struct node_list* next;
}node;

void insert();
void delete();
void print(node *head);

node* head = NULL;
node* tail = NULL;

int main(){
  int input;
  int run = 1;
  puts("Welcome to the Waiting List!");
  puts("0 = input a person, 1 = delete a person, 2 = print list, 3 = quit");
  while (run == 1){//run code infinitely
    scanf("%d", &input);
    switch(input){
    case 0://1 for insert
      insert();
      break;
    case 1://2 for deletion
      delete();
      break;
    case 2://3 for print
      print(head);
      break;
    case 3://4 to quit
      run = 0;
      break;
    default://run again if it's an unknown command 
      puts("Oh no! You accidentally downloaded a virus to your computer!");
      puts("Jk. That's just the wrong command. Try again");
    }
    puts("0 = input a person, 1 = delete a person, 2 = print list, 3 = quit");
  }
  return 0;
}

void insert(){
  //node *current = head;
  node *temp = head;
  int num, found;
  char inputName[20];
  puts("What is the name for your party fam?");
  scanf("%s", inputName);//input for name
  while(temp != NULL){
    if(strcmp(temp->name,inputName) == 0){
      found = 1;
    }
    temp = temp->next;
  }
  if(found == 1){//if the name exists, don't do anything
    puts("That name already exists fam. What are you doing");
  }
  else{
    puts("How many people are in your party fam?");
    scanf("%d", &num);//input for number of people
    node *p = NULL;
    p = (node*)malloc(sizeof(node));//allocates the space for the new node
    p->data = num;
    strcpy(p->name,inputName);
    p->next = NULL;
    if(head == NULL){//if this is the first node
      head = p;
      tail = p;
    }
    else{
      /*while(current->next != NULL){//get to the end of the list by traversing
	current = current->next;
      }
      current->next = p;*/
      tail->next = p;
      tail = p;
    }
    puts("Party successfully added! You deserve a cookie");
  }
}

void delete(){
  int input;
  puts("What's the biggest party we can seat?");
  scanf("%d", &input);
  node *current, *previous;
  current = previous = head;
  while(current != NULL){//traverse the linked list
    if(current->data <= input){
      break;
    }
    previous = current;
    current = current->next;
  }
  if(current == NULL){//return nothing if the party doesn't exist
    puts("There isn't a party that fits your input. Sorry fam");
    return;
  }
  else if(current == head){//if the desired node is the head
    printf("%s for %d successfully deleted! You deserve a pat on the back\n", head->name, head->data);
    head = head->next;
  }
  else if(current == tail){//if the desired node is the tail
    printf("%s for %d successfully deleted! You deserve a pat on the back\n", tail->name, tail->data);
    tail = previous;
    previous->next = NULL;
  }
  else{//if the node is in the middle, reconnect the list
    printf("%s for %d successfully deleted! You deserve a pat on the back\n", current->name, current->data);
    previous->next = current->next;
  }
  free(current);
}

void print(node *head){//prints from oldest to newest
  if(head == NULL){//nothing to print if there's no one in the list
    puts("List is empty! Lo siento...");
    return;
  }
  else{
    while(head != NULL){//print out the list if there are nodes in the list
      printf("%s for %d\n", head->name, head->data);
      head = head->next;
    }
  }
}
