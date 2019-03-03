/*
Ethan Paek, November 9th, 2017; this is a program designed as a restaurant waiting list to be used with the addition of binary files and recursion
Lab #8
Lab Section 3 (Wednesdays)
*/
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
void read_file(char* fileName);
void print_file(char* fileName);
void reverse();
void changePointers(node* temp);
void writeBinary(char* binaryName);
void readBinary(char* binaryName);

node* head[4];
node* tail[4];

int main(int argc, char* argv[]){
  if(argc == 1){
    puts("The name of the file is missing! Lo siento.");
    return 0;
  }
  else{
    read_file(argv[1]);
  }
  int input, num, inputNum;
  int run = 1;
  char *someName = malloc(20);
  puts("Welcome to the Waiting List!");
  puts("1 = input a person, 2 = delete a person, 3 = print list, \n4 = change the size of a group, 5 = reverse the lists, 6 = read contents of binary file, \n7 = quit");
  while (run == 1){//run code infintely
    scanf("%d", &input);
    switch(input){
    case 1://1 for insert
      puts("What is the name for your party fam?");
      scanf("%s", someName);//input for name
      puts("How many people are in your party fam?");
      scanf("%d", &num);//input for number of people
      if(num < 1){
	puts("That party won't work. Smh");
	break;
      }
      insert(someName, num);
      break;
    case 2://2 for deletion
      puts("What's the biggest party we can seat?");
      scanf("%d", &inputNum);
      if(inputNum < 1){//do nothing if the party is below 1
	puts("That party won't work fam. Smh");
	break;
      }
      delete(inputNum);
      break;
    case 3://3 for print
      print();
      break;
    case 4://4 to change the size of a group already in the list
      change();
      break;
    case 5://5 to quit and free all nodes
      reverse();
      puts("Lists reversed!");
      break;
    case 6:
      readBinary(argv[2]);
      break;
    case 7:
      print_file(argv[1]);
      writeBinary(argv[2]);
      deleteAll();
      run = 0;
      break;
    default://run again if it's an unknown command 
      puts("Oh no! You accidentally downloaded a virus to your computer!");
      puts("Jk. That's just the wrong command. Try again");
    }
    puts("1 = input a person, 2 = delete a person, 3 = print list, \n4 = change the size of a group, 5 = reverse the lists, 6 = read from binary file, \n7 = quit");
  }
  return 0;
}

void insert(char *nodeName, int party){
  int found;
  for(int i = 0; i < 4; i++){
    node* temp = head[i];
    while(temp != NULL){//checking the first linked list for a duplicate name
      if(strcmp(temp->name,nodeName) == 0){
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
    node* p = NULL;
    p = (node*)malloc(sizeof(node));
    p->data = party;
    strcpy(p->name, nodeName);
    p->next = NULL;
    p->prev = NULL;
    switch(party){
    case 1:
    case 2://adding for parties between 1 and 2
      if(head[0] == NULL){
	head[0] = p;
	tail[0] = p;
      }
      else{
	tail[0]->next = p;
	p->prev = tail[0];
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
	p->prev= tail[1];
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
	p->prev = tail[2];
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
	p->prev = tail[3];
	tail[3] = p;
	tail[3]->next = NULL;
      }
      break;
    }
    puts("Party successfully added! You deserve a cookie");
  }
}

void delete(int input){
  int run = 1;
  while(run == 1){//run infinitely in order to look through all lists
    node* current0 = head[0];
    node* current1 = head[1];
    node* current2 = head[2];
    node* current3 = head[3];
    switch(input){
    case 1:
    case 2://checks for any party within 1 and 2
      while(current0 != NULL){
	if(current0->data <= input){
	  break;
	}
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
      else if(current0 == head[0]){//if the desired node is the heads
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current0->name, current0->data);
	head[0] = head[0]->next;
	run = 0;
      }
      else if(current0 == tail[0]){//if the desired node is the tail
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", tail[0]->name, tail[0]->data);
	tail[0] = current0->prev;
	current0->prev->next = NULL;
	run = 0;
      }
      else{//if the desired node is somewhere in the middle of the list
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current0->name, current0->data);
	current0->prev->next = current0->next;
	current0->next->prev = current0->prev;
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
	tail[1] = current1->prev;
	current1->prev->next = NULL;
	run = 0;
      }
      else{
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current1->name, current1->data);
	current1->prev->next = current1->next;
	current1->next->prev = current1->prev;
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
	tail[2] = current2->prev;
	current2->prev->next = NULL;
	run = 0;
      }
      else{
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current2->name, current2->data);
	current2->prev->next = current2->next;
	current2->next->prev = current2->prev;
	run = 0;
      }
      free(current2);
      break;
    default://check for parties above 6
      while(current3 != NULL){
	if(current3->data <= input){
	  break;
	}
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
	tail[3] = current3->prev;
	current3->prev->next = NULL;
	run = 0;
      }
      else{
	printf("%s for %d successfully deleted! You deserve a pat on the back\n", current3->name, current3->data);
	current3->prev->next = current3->next;
	current3->next->prev = current3->prev;
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
  node* current = NULL;
  for(int i = 0; i < 4; i++){
    current = head[i];
    while(current != NULL){//check for a matching node
      if(strcmp(current->name, inputName) == 0){
	found = 1;
	pos = i;
	intCopy = current->data;
	break;
      }
      else{
	current = current->next;
      }
    }
    if(found == 1){
      break;
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
      if(head[pos] == tail[pos]){//if there's only one node in the list
	head[pos] = tail[pos] = NULL;
      }
      else if(current == head[pos]){//if the desired node is the head
	head[pos] = current->next;
	head[pos]->prev = NULL;
      }
      else if(current == tail[pos]){//if the desired node is the tail
	tail[pos] = current->prev;
	tail[pos]->next = NULL;
      }
      else{//if the desired node is somewhere in the middle of the list
	current->prev->next = current->next;
	current->next->prev = current->prev;
      }
      free(current);
      
      //now add the node back to the desired list
      insert(inputName, inputParty);
      puts("Party successfully changed! You deserve a cookie");
    }
  }
  return;
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

void read_file(char* fileName){//read the file when you start the program
  FILE* fp = fopen(fileName, "r");
  int number;
  char *input = malloc(20);
  fseek(fp, 35, SEEK_SET);//skip the first 35 characters
  if(fp == NULL){//if the file cannot be opened, do nothing
    puts("File cannot be opened. Smh fam");
    return;
  }
  while(fscanf(fp, "%s %d", input, &number) > 0){//insert all of the names and parties into the linked lists
    insert(input, number);
  }
  fclose(fp);
}

void print_file(char* fileName){//print the linked lists into a text file
  FILE* fp = fopen(fileName, "w");
  fprintf(fp, "Name\tGroup Size\n------------------\n");
  for(int i = 0; i < 4; i++){
    node* current = head[i];
    while(current != NULL){
      fprintf(fp, "%s\t%d\n", current->name, current->data);
      current = current->next;
    }
  }
  fclose(fp);
}

void reverse(){//reverse the orders of the linked lists
  node* current = NULL;
  for(int i = 0; i < 4; i++){
    if(head[i] == NULL || head[i] == tail[i]){
      continue;//move on if there's nothing or one thing in a list because you don't need to do anything
    }
    current = tail[i]->prev;//current is equal to second to last thing in list
    tail[i]->prev = NULL;
    tail[i]->next = current;
    changePointers(current);
  }
}

void changePointers(node* temp){
  node* tempHead;
  node* tempTail;
  for(int i = 0; i < 4; i++){
    if(temp == head[i]){
      head[i]->prev = head[i]->next;
      head[i]->next = NULL;
      tempHead = head[i];//switch the head and the tail of the designated list
      tempTail = tail[i];
      head[i] = tempTail;
      tail[i] = tempHead;
      return;
    }
  }
  node* previous = temp->prev;
  temp->prev = temp->next;//change the direction of the pointers for temp
  temp->next = previous;
  changePointers(previous);//use recursion
}

void writeBinary(char* binaryName){//write to the binary file when you quit
  FILE* fp = fopen(binaryName, "wb");
  for(int i = 0; i < 4; i++){
    node* current = head[i];
    while(current != NULL){
      fwrite(current, sizeof(node), 1, fp);//writes to the binary file
      current = current->next;//traverse the rest of the linked lists
    }
  }
  fclose(fp);
}

void readBinary(char* binaryName){//read from the binary file and print out the contents
  FILE* fp = fopen(binaryName, "rb");
  node current;
  if(fp == NULL){
    puts("Not able to print binary file. Lo siento");
    return;
  }
  printf("Name\tGroup Size\n------------------\n");
  while(fread(&current, sizeof(node), 1, fp) > 0){
    printf("%s\t%d\n", current.name, current.data);//since node is not node*, no need for ->
  }
  fclose(fp);
}
