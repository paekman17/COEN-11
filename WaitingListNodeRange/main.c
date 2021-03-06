/*
Ethan Paek, October 25th, 2017; this is a program designed as a restaurant waiting list to be used with linear linked lists within an array
Lab #6
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
void print();
void change();
void deleteAll();

node* head[4];
node* tail[4];

int main(){
  int input;
  int run = 1;
  puts("Welcome to the Waiting List!");
  puts("1 = input a person, 2 = delete a person, 3 = print list, \n4 = change the size of a group, 5 = quit");
  while (run == 1){//run code infintely
    scanf("%d", &input);
    switch(input){
    case 1://1 for insert
      insert();
      break;
    case 2://2 for deletion
      delete();
      break;
    case 3://3 for print
      print();
      break;
    case 4://4 to change the size of a group already in the list
      change();
      break;
    case 5://5 to quit and free all nodes
      deleteAll();
      run = 0;
      break;
    default://run again if it's an unknown command 
      puts("Oh no! You accidentally downloaded a virus to your computer!");
      puts("Jk. That's just the wrong command. Try again");
    }
    puts("1 = input a person, 2 = delete a person, 3 = print list, \n4 = change the size of a group, 5 = quit");
  }
  return 0;
}

void insert(){
  int num, found;
  char inputName[20];
  puts("What is the name for your party fam?");
  scanf("%s", inputName);//input for name
  for(int i = 0; i < 4; i++){
    node* temp = head[i];
    while(temp != NULL){//checking the first linked list for a duplicate name
      if(strcmp(temp->name,inputName) == 0){
	found = 1;
      }
      temp = temp->next;
    }
  }
  if(found == 1){//if the name exists, don't do anything
    puts("That name already exists fam. What are you doing");
    return;
  }
  else{
    puts("How many people are in your party fam?");
    scanf("%d", &num);//input for number of people
    if(num < 1){
      puts("That party won't work. Smh");
      return;
    }
    else{
      node* p = NULL;
      p = (node*)malloc(sizeof(node));
      p->data = num;
      strcpy(p->name, inputName);
      p->next = NULL;
      switch(num){
      case 1:
      case 2://adding for parties between 1 and 2
	if(head[0] == NULL){
	  head[0] = p;
	  tail[0] = p;
	}
	else{
	  tail[0]->next = p;
	  tail[0] = p;
	  tail[0]->next = NULL;
	}
	break;
      case 3:
      case 4://adding for parties between 3 and 4
	if(head[1] == NULL){
	  head[1] = p;
	  tail[1] = p;
	}
	else{
	  tail[1]->next = p;
	  tail[1] = p;
	  tail[1]->next = NULL;
	}
	break;
      case 5:
      case 6://adding for parties between 5 and 6
	if(head[2] == NULL){
	  head[2] = p;
	  tail[2] = p;
	}
	else{
	  tail[2]->next = p;
	  tail[2] = p;
	  tail[2]->next = NULL;
	}
	break;
      default://adding for anything about 6
	if(head[3] == NULL){
	  head[3] = p;
	  tail[3] = p;
	}
	else{
	  tail[3]->next = p;
	  tail[3] = p;
	  tail[3]->next = NULL;
	}
	break;
      }
    }
    puts("Party successfully added! You deserve a cookie");
  }
}

void delete(){
  int input;
  int run = 1;
  puts("What's the biggest party we can seat?");
  scanf("%d", &input);
  if(input < 1){//do nothing if the party is below 1
    puts("That party won't work fam. Smh");
    return;
  }
  while(run == 1){//run infinitely in order to look through all lists
    node* current0 = head[0];
    node* current1 = head[1];
    node* current2 = head[2];
    node* current3 = head[3];
    node* prev0;
    node* prev1;
    node* prev2;
    node* prev3;
    switch(input){
    case 1:
    case 2://checks for any party within 1 and 2
      while(current0 != NULL){
	if(current0->data <= input){
	  break;
	}
	prev0 = current0;
	current0 = current0->next;
      }
      if(current0 == NULL){//do nothing if there is no party that is found
	puts("There isn't a party that fits your input. Sorry fam");
	return;
      }
      else if(head[0] == tail[0]){//if there's only one node in the list
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", head[0]->name, head[0]->data);
	head[0] = tail[0] = NULL;
	run = 0;
      }
      else if(current0 == head[0]){//if the desired node is the head
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current0->name, current0->data);
	head[0] = head[0]->next;
	run = 0;
      }
      else if(current0 == tail[0]){//if the desired node is the tail
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", tail[0]->name, tail[0]->data);
	tail[0] = prev0;
	prev0->next = NULL;
	run = 0;
      }
      else{//if the desired node is somewhere in the middle of the list
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current0->name, current0->data);
	prev0->next = current0->next;
	run = 0;
      }
      free(current0);
      return;
      break;
    case 3:
    case 4://check for parties between 3 and 4
      while(current1 != NULL){
	if(current1->data <= input){
	  break;
	}
	prev1 = current1;
	current1 = current1->next;
      }
      if(current1 == NULL){
	input = 2;//go to case 1 and 2
      }
      else if(head[1] == tail[1]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", head[1]->name, head[1]->data);
	head[1] = tail[1] = NULL;
	run = 0;
      }
      else if(current1 == head[1]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current1->name, current1->data);
	head[1] = head[1]->next;
	run = 0;
      }
      else if(current1 == tail[1]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", tail[1]->name, tail[1]->data);
	tail[1] = prev1;
	prev1->next = NULL;
	run = 0;
      }
      else{
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current1->name, current1->data);
	prev1->next = current1->next;
	run = 0;
      }
      free(current1);
      break;
    case 5:
    case 6://check for parties between 5 and 6
      while(current2 != NULL){
	if(current2->data <= input){
	  break;
	}
	prev2 = current2;
	current2 = current2->next;
      }
      if(current2 == NULL){
	input = 4;//go to case 3 and 4
      }
      else if(head[2] == tail[2]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", head[2]->name, head[2]->data);
	head[2] = tail[2] = NULL;
	run = 0;
      }
      else if(current2 == head[2]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current2->name, current2->data);
	head[2] = head[2]->next;
	run = 0;
      }
      else if(current2 == tail[2]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", tail[2]->name, tail[2]->data);
	tail[2] = prev2;
	prev2->next = NULL;
	run = 0;
      }
      else{
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current2->name, current2->data);
	prev2->next = current2->next;
	run = 0;
      }
      free(current2);
      break;
    default://check for parties above 6
      while(current3 != NULL){
	if(current3->data <= input){
	  break;
	}
	prev3 = current3;
	current3 = current3->next;
      }
      if(current3 == NULL){
	input = 6;//go to case 5 and 6
      }
      else if(head[3] == tail[3]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", head[3]->name, head[3]->data);
	head[3] = tail[3] = NULL;
	run = 0;
      }
      else if(current3 == head[3]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current3->name, current3->data);
	head[3] = head[3]->next;
	run = 0;
      }
      else if(current3 == tail[3]){
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", tail[3]->name, tail[3]->data);
	tail[3] = prev3;
	prev3->next = NULL;
	run = 0;
      }
      else{
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current3->name, current3->data);
	prev3->next = current3->next;
	run = 0;
      }
      free(current3);
      break;
    }
  }
}

void print(){//prints from oldest to newest by traversing through each list
  node* current0 = head[0];
  node* current1 = head[1];
  node* current2 = head[2];
  node* current3 = head[3];
  puts("List for parties of 1-2:");
  if(current0 == NULL){//printing for parties between 1 and 2
    puts(" ");
  }
  else{
    while(current0 != NULL){
      printf("%s for %d\n", current0->name, current0->data);
      current0 = current0->next;
    }
  }
  puts("List for parties of 3-4:");
  if(current1 == NULL){//printing for parties between 3 and 4
    puts(" ");
  }
  else{
    while(current1 != NULL){
      printf("%s for %d\n", current1->name, current1->data);
      current1 = current1->next;
    }
  }
  puts("List for parties of 5-6:");
  if(current2 == NULL){//printing for parties between 5 and 6
    puts(" ");
  }
  else{
    while(current2 != NULL){
      printf("%s for %d\n", current2->name, current2->data);
      current2 = current2->next;
    }
  }
  puts("List for all other parties:");
  if(current3 == NULL){//printing for all parties above 6
    puts(" ");
  }
  else{
    while(current3 != NULL){
      printf("%s for %d\n", current3->name, current3->data);
      current3 = current3->next;
    }
  }
}

void change(){//change a party's size by inputting a name
  puts("Who's party would you like to change?");
  char inputName[20];
  int found, pos, works, intCopy;
  scanf("%s", inputName);
  node* prev;
  node* current;
  for(int i = 0; i < 4; i++){
    current = head[i];
    while(current != NULL){//check for a matching node
      if(strcmp(current->name, inputName) == 0){
	found = 1;
	pos = i;
	intCopy = current->data;
	break;
      }
      prev = current;
      current = current->next;
    }
  }
  if(found != 1){
    puts("Party not found. Sorry fam");
    return;
  }
  else{
    int inputParty;
    puts("What is the new party size you'd like to assign?");
    scanf("%d", &inputParty);
    if(inputParty > 0){
      if(inputParty == intCopy){//do nothing if the party is the exact same number
        puts("You can't change the party to be the exact same thing. Smh");
        return;
      }
      else{
	works = 1;
      } 
    }
    else{//can't have a party below 1 exist
      puts("That party won't do. Smh");
      return;
    }
    if(works == 1){
      //delete the node and copy the name
      if(head[pos] == tail[pos]){//if there's only one node in the list
	head[pos] = tail[pos] = NULL;
      }
      else if(current == head[pos-1]){//if the desired node is the head
	head[pos] = head[pos]->next;
      }
      else if(current == tail[pos]){//if the desired node is the tail
	tail[pos] = prev;
	prev->next = NULL;
      }
      else{//if the desired node is somewhere in the middle of the list
	prev->next = current->next;
      }
      free(current);
      
      //now add the node back to the desired list
      node* p = NULL;
      p = (node*)malloc(sizeof(node));
      p->data = inputParty;
      strcpy(p->name, inputName);
      p->next = NULL;
      switch(inputParty){
      case 1:
      case 2://adding for parties between 1 and 2
	if(head[0] == NULL){
	  head[0] = p;
	  tail[0] = p;
	}
	else{
	  tail[0]->next = p;
	  tail[0] = p;
	  tail[0]->next = NULL;
	}
	break;
      case 3:
      case 4://adding for parties between 3 and 4
	if(head[1] == NULL){
	  head[1] = p;
	  tail[1] = p;
	}
	else{
	  tail[1]->next = p;
	  tail[1] = p;
	  tail[1]->next = NULL;
	}
	break;
      case 5:
      case 6://adding for parties between 5 and 6
	if(head[2] == NULL){
	  head[2] = p;
	  tail[2] = p;
	}
	else{
	  tail[2]->next = p;
	  tail[2] = p;
	  tail[2]->next = NULL;
	}
	break;
      default://adding for anything about 6
	if(head[3] == NULL){
	  head[3] = p;
	  tail[3] = p;
	}
	else{
	  tail[3]->next = p;
	  tail[3] = p;
	  tail[3]->next = NULL;
	}
	break;
      }
      puts("Party successfully changed! You deserve a cookie");
    }
  }
}

void deleteAll(){//function to free all nodes before quitting
  for(int i = 0; i < 4; i++){
    while(head[i] != NULL){
      node* temp = head[i];
      head[i] = head[i]->next;
      free(temp);
    }
  }
}
