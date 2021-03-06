//Ethan Paek, September 20th, 2017; this is a program that is a guessing game and will tell you if you guessed the number correctly or not
//Wednesday Lab, COEN 11
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int divide(int a, int b);

int main(){
  srand((int)time(NULL));
  puts("Welcome to the Division Test!");
  int score = 0;
  for(int i = 0; i < 10; i++){//will run 10 times
    int divisor = rand()%12 + 1;
    int quotient = rand()%13;//generates the two numbers
    printf("Here is the divisor: %d\n", divisor);
    int right_wrong = divide(divisor, quotient);
    score += right_wrong;//add to the score
  }
  printf("You got %d out of 10 numbers correct! You deserve a cookie.\n", score);//counts the number of correct answers
}

int divide(int a, int b){//checks if the guess is right or wrong
  int right;
  int guess;
  int dividend;
  dividend = a*b;//gets the dividend                                                            
  printf("Here is the dividend: %d\n", dividend);
  puts("Please enter your guess for the quotient: ");
  scanf("%d", &guess);//input the answer
  if(guess == b){
    printf("Your guess was correct!\n\n");
    right = 1;//adds one if the guess is correct
  }
  else{
    printf("Your guess was wrong :(\n");
    printf("The actual quotient was: %d\n\n", b);//outputs the quotient if it's wrong     
    right = 0;
  }
  return right;
}
