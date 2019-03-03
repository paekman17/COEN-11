//Ethan Paek, September 27th, 2017; this is a program designed as a restaurant waiting list
#include <stdio.h>
#include <string.h>

int counter;
char names[10][21];//max of 20 chars for a name with 10 total names
int size[10];//max of double digit size

void delete();
void insert();
void print();

int main(){
  char input[10];
  int run = 1;
  puts("Welcome to the Restaurant Waiting List!");
  puts("Enter 1 to add a name and number of people to the list, 2 to remove a guest depending on the amount of guests, 3 to print out the list, and 4 to quit");
  while(run == 1){
    scanf("%s", input);
    if(!strcmp(input, "1")){//adding a party to the end of the list
      insert();
    }
    else if(!strcmp(input, "2")){//removes the oldest entry depending on the number
      delete();
    }
    else if(!strcmp(input, "3")){//prints out the entire list
      print();
    }
    else if(!strcmp(input, "4")){//quits
      run = 0;
      break;
    }
    else{//if the command is not recognized
      puts("Command not recognized. Try again por favor.");
    }
    puts("Enter 1 to add a name and number of people to the list, 2 to remove a guest depending on the amount of guests, 3 to print out the list, and 4 to quit");
  }
}

void delete(){
  int theSize, found, pos, i;
  puts("How many people are in the party?");
  scanf("%d", &theSize);
  for(i = 0; i < counter; i++){
    if(size[i] == theSize){//checking if the party exists
      found = 1;
      pos = i;
      puts("The party has been successfully deleted! You deserve a pat on the back");
      break;
    }
  }
  if(found == 1){//if found, delete it and move up all rows
    for(i = pos; i < counter; i++){
      strcpy(names[i], names[i+1]);
      size[i] = size[i+1];
    }
    counter--;//delete one from the counter
  }
  else{//nothing happens if party is not found
    puts("There is no party with that number. Try again por favor");
  }
}

void insert(){
  char inputName[20];
  int pos, found = 0;
  puts("What is the name for your group?");
  scanf("%s", inputName);
  for (int i = 0; i <= counter; i++){
    if(strcmp(names[i], inputName) == 0){//if a name exists, don't add it
      found = 1;
      break;
    }
  }
  if(found == 1){
    puts("That name already exists in the list! Smh");
  }
  else{//if it's a unique name, add it
    if(counter >= 10){//not allowed to add more than 5 names to the list so you can't overload the array
      puts("You can't add any more to the list!");
    }
    else{
      for(int j = 0; j <= counter; j++){
	strcpy(names[counter], inputName);
	int inputSize;
	puts("How many in your party?");
	scanf("%d", &inputSize);
	size[counter] = inputSize;
	counter++;
	puts("Your party was successfully added to the end of the list!");
	break;
      }
    }
  }
}

void print(){
  for(int i = 0; i < counter; i++){//prints out whole list based on counter
    printf("%s for %d\n", names[i], size[i]);
  }
}
