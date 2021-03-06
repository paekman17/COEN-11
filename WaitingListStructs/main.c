/*Ethan Paek, October 4th, 2017; this is a program designed as a restaurant waiting list to be used with structs
Lab #3
Lab Section: Wednesday
 */
#include <stdio.h>
#include <string.h>

typedef struct party{
  char names[21];
  int size;
} guests;

int counter = 0;
guests list[5];//initializing the struct array

void delete();
void insert();
void print();

int main(){
  int input;
  int run = 1;
  puts("Welcome to the Restaurant Waiting List!");
  puts("Enter 1 to add a name and number of people to the list, 2 to remove a guest depending on the amount of guests, 3 to print out the list, and 4 to quit");
  while(run == 1){//run the code infinitely
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
    case 4://4 to quit
      run = 0;
      break;
    default://run again if it's an unknown command
      puts("Command not recognized. Try again por favor.");
    }
    puts("Enter 1 to add a name and number of people to the list, 2 to remove a guest depending on the amount of guests, 3 to print out the list, and 4 to quit");
  }
}

void delete(){
  guests *p;
  p = list;
  int theSize, found, pos, i;
  puts("How many people are in the party?");
  scanf("%d", &theSize);
  for(i = 0; i < counter; i++){
    if((p+i)->size == theSize){//checking if the party exists
      found = 1;
      pos = i;
      puts("The party has been successfully deleted! You deserve a pat on the back");
      break;
    }
  }
  if(found == 1){//if found, delete it and move up all rows
    for(i = pos; i < counter; i++){
      strcpy((p+i)->names, (p+i+1)->names);
      (p+i)->size = (p+i+1)->size;
    }
    counter--;//delete one from the counter
  }
  else{//nothing happens if party is not found
    puts("There is no party with that number. Try again por favor");
  }
}

void insert(){
  guests *p;
  p = list;
  char inputName[20];
  int pos, found = 0;
  puts("What is the name for your group?");
  scanf("%s", inputName);
  for (int i = 0; i <= counter; i++){
    if(strcmp((p+i)->names, inputName) == 0){//if a name exists, don't add it
      found = 1;
      break;
    }
  }
  if(found == 1){
    puts("That name already exists in the list! Smh");
  }
  else{//if it's a unique name, add it
    if(counter >= 5){//not allowed to add more than 5 names to the list so you can't overload the array
      puts("You can't add any more to the list!");
    }
    else{
      for(int j = 0; j <= counter; j++){
	strcpy((p+counter)->names, inputName);
	int inputSize;
	puts("How many in your party?");
	scanf("%d", &inputSize);
	(p+counter)->size = inputSize;
	counter++;
	puts("Your party was successfully added to the end of the list!");
	break;
      }
    }
  }
}

void print(){
  guests *p;
  p = list;
  for(int i = 0; i < counter; i++){//prints out whole list based on counter
    printf("%s for %d\n", (p+i)->names, (p+i)->size);
  }
}
