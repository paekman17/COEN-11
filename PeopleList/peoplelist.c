/*Ethan Paek, October 11th, 2017; this is a people list to practice unions
Lab #3
Wednesdays
*/
#include <stdio.h>
#include <string.h>

typedef union{
  char school[21];
  float salary;
  int retirement;
}status;

typedef struct{
  char names[21];
  int age;
  status status_list;
}people;

int counter = 0;
people list[5];

void insert();
void delete();
void show();

int main(){
  int input;
  int run = 1;
  puts("Welcome to the People List!");
  puts("0 = input a person, 1 = delete a person, 2 = print list, 3 = quit");
  while (run == 1){//run code infintely
    scanf("%d", &input);
    switch(input){
    case 0://1 for insert
      insert();
      break;
    case 1://2 for deletion
      delete();
      break;
    case 2://3 for print
      show();
      break;
    case 3://4 to quit
      run = 0;
      break;
    default://run again if it's an unknown command 
      puts("Command not recognized. Try again por favor.");
    }
    puts("0 = input a person, 1 = delete a person, 2 = print list, 3 = quit");
  }
  return 0;
}

void insert(){
  char inputName[20];
  int pos = 0;
  if(counter >= 5){
    puts("You can't add anymore to the list!");
  }
  else{
    puts("What is the name of your person?");
    scanf("%s", inputName);
    for(int i = 0; i <= counter; i++){
      strcpy((list+counter)->names, inputName);
      int inputSize;
      puts("How old is this person?");
      scanf("%d", &inputSize);
      (list+counter)->age = inputSize;
      if(inputSize <= 21){//ask for school if 21 or younger
	puts("What school does this person go to?");
	char schoolInput[21];
	scanf("%s", schoolInput);
	strcpy((list+counter)->status_list.school,schoolInput);
      }
      else if(inputSize > 21 && inputSize < 65){//ask for salary if between 21 and 65
	float salaryInput;
	puts("How much does this person make per hour?");
	scanf("%f", &salaryInput);
	(list+counter)->status_list.salary = salaryInput;
      }
      else{//if the person is 65 or older, ask for years of retirement
	int yearsInput;
	puts("How long has this person been in retirement?");
	scanf("%d", &yearsInput);
	(list+counter)->status_list.retirement = yearsInput;
      }
      counter++;
      puts("Your person was successfully added to the list! You deserve a cookie.");
      break;
    }
  }
}

void delete(){
  char inputName[21];
  int found, pos;
  puts("Who is the lucky person to get deleted?");
  scanf("%s", inputName);
  for(int i = 0; i < counter; i++){
    if(strcmp((list+i)->names, inputName) == 0){//if the name exists, delete it
      found = 1;
      pos = i;
      break;
    }
  }
  if(found == 1){
    if(counter == 1){
      puts("The person has been deleted! You deserve a pat on the back");
      counter--;
    }
    else{
      for(int j = pos; j < counter; j++){
	strcpy((list+j)->names, (list+counter-1)->names);
	(list+j)->age = (list+counter-1)->age;
	(list+j)->status_list = (list+counter-1)->status_list;
	puts("The person has been deleted! You deserve a pat on the back");
	counter--;
	break;
      }
    }
  }
  else{//nothing happens if the person doesn't exist                                    
    puts("That person does not exist. What are you doing bruh");
  }
}

void show(){
  for(int i = 0; i < counter; i++){//prints out whole list based on counter
    printf("%s, %d, ", (list+i)->names, (list+i)->age);
    if((list+i)->age <= 21){
      printf("%s\n", (list+i)->status_list.school);
    }
    else if((list+i)->age > 21 && (list+i)->age < 65){
      printf("%0.2f\n", (list+i)->status_list.salary);
    }
    else{
      printf("%d\n", (list+i)->status_list.retirement);
    }
  }
}
