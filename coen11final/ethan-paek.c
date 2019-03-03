/*
Ethan Paek
Dr. Yi Fang
This is the COEN 11 Final!
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int biggest = 0;

struct node{//set up the data each node contains
  char task[200];
  int number;
  struct node* next;
  struct node* prev;
};

void add();
void delete();
void print();
void find(struct node* current);
void save();

//setup head and tail pointers
struct node* head = NULL;
struct node* tail = NULL;

int main(){
  int input, run = 1;
  puts("What would you like to do?\n1:add a new task to end of list\n2:delete a task\n3:show all tasks\n4:find the max task\n5:save\
 all tasks to text file\n6:exit");
  while (run == 1){
    scanf("%d", &input);
    switch(input){
    case 1:
      add();
      break;
    case 2:
      delete();
      break;
    case 3:
      print();
      break;
    case 4:
      biggest = 0;
      find(head);
      break;
    case 5:
      save();
      break;
    case 6:
      run = 0;
      break;
    default:
      puts("Command not valid. Try again por favor");
      break;
    }
    puts("\nWhat would you like to do?\n1:add a new task to end of list\n2:delete a task\n3:show all tasks\n4:find the max task\n5:save all tasks to text file\n6:exit");
  }
  return 0;
}

void add(){//add a node to the end of the list
  struct node* current = NULL;
  current = (struct node*)malloc(sizeof(struct node));
  puts("What task would you like to give this node?");
  char charInput[200];
  scanf("%s", charInput);
  puts("What number would you like to give this node?");
  int intInput;
  scanf("%d", &intInput);
  strcpy(current->task, charInput);
  current->number = intInput;
  current->next = NULL;
  current->prev = NULL;
  if(head == NULL){
    head = current;
    tail = current;
  }
  else{
    tail->next = current;
    current->prev = tail;
    tail = current;
    tail->next = NULL;
  }
  puts("Node successfully added! You're a rockstar! :D");
  return;
}

void delete(){//delete a task when give a number
  struct node* current = head;
  if(head == NULL){
    puts("Nothing to delete fam");
  }
  else{
    puts("What number are you looking to delete?");
    int numInput;
    scanf("%d", &numInput);
    int found = 0;
    while(current != NULL){
      if(current->number == numInput){
	found = 1;
	break;
      }
      current = current->next;
    }
    if(found == 1){
      if(head == tail){
	head = tail = NULL;
      }
      else if(current == head){
	head = head->next;
      }
      else if(current == tail){
	tail = current->prev;
	current->prev->next = NULL;
      }
      else{
	current->prev->next = current->next;
	current->next->prev = current->prev;
      }
      puts("Node successfully deleted! You're so cool");
      free(current);
    }
    else{
      puts("Unable to find that node. Lo siento");
    }
  }
  return;
}

void print(){//show all tasks
  struct node* current = head;
  while(current != NULL){
    printf("%s, %d\n", current->task, current->number);
    current = current->next;
  }
}

void find(struct node* current){//find the max priority number through recursion
  if(head == NULL){
    puts("The list is empty so it would be impossible to find the biggest number!");
    return;
  } 
  else if(current->next == NULL){
    if(current->number > biggest){
      biggest = current->number;
    }
    printf("The biggest number is: %d\n", biggest);
    return;
  }
  else{
    if(current->number > biggest){
      biggest = current->number;
    }
    find(current->next);//recursion
  }
}

void save(){//save the linkedlist to a text file
  FILE* fp = fopen("tasks.txt", "w");
  if(fp == NULL){
    puts("File is not able to open. Sorry my dude");
    return;
  }
  struct node* current = head;
  while(current != NULL){
    fprintf(fp, "%s, %d\n", current->task, current->number);
    current = current->next;
  }
  puts("File is saved! Good job!");
  return;
}
