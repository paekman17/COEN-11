/*
Ethan Paek, November 29th, 2017; this is a program designed as a restaurant waiting list that is automatically saved every five seconds
Lab #10
Lab Section 3 (Wednesdays)
*/
#include "lists.h"
#include "files.h"

int main(int argc, char* argv[]){
  pthread_t thr;
  pthread_mutex_init(&mutex, NULL);//initializing mutex
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
  pthread_create(&thr, NULL, autosave, NULL);//creating the thread
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
      pthread_mutex_lock(&mutex);
      insert(someName, num);
      pthread_mutex_unlock(&mutex);
      break;
    case 2://2 for deletion
      puts("What's the biggest party we can seat?");
      scanf("%d", &inputNum);
      if(inputNum < 1){//do nothing if the party is below 1
	puts("That party won't work fam. Smh");
	break;
      }
      pthread_mutex_lock(&mutex);
      delete(inputNum);
      pthread_mutex_unlock(&mutex);
      break;
    case 3://3 for print
      print();
      break;
    case 4://4 to change the size of a group already in the list
      pthread_mutex_lock(&mutex);
      change();
      pthread_mutex_unlock(&mutex);
      break;
    case 5://5 to quit and free all nodes
      pthread_mutex_lock(&mutex);
      reverse();
      pthread_mutex_unlock(&mutex);
      puts("Lists reversed!");
      break;
    case 6:
      readBinary(argv[2]);
      break;
    case 7:
      pthread_mutex_lock(&mutex);
      print_file(argv[1]);
      writeBinary(argv[2]);
      deleteAll();
      pthread_mutex_unlock(&mutex);
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
