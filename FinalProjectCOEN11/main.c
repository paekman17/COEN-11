/*
Ethan Paek
Final Project for COEN 11
Dr. Yi Fang
December 9th, 2017
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void read_file(char* fileName);
void write_file(char* key, char* fileName);

char charArray[10000];

int main(int argc, char* argv[]){
  if(argc != 4){//command line must consist of the key and two other files
    puts("You're missing a file and/or the key! Smh.");
    return 0;
  }
  read_file(argv[2]);//read in the contents of file1
  write_file(argv[1], argv[3]);//encrypt/decrypt file2 with the key
  return 0;
}

void read_file(char* fileName){
  FILE* fp = fopen(fileName, "rb");//open the file to be read in binary
  if(fp == NULL){//if the file cannot be opened, do nothing
    puts("File cannot be opened. Lo siento.");
    return;
  }
  while(1){
    fread(charArray, 100, 10000, fp);//read the text file 100 bytes at a time
    if(feof(fp)){//keep reading until you reach the end of the file
      break;
    }
  }
  fclose(fp);
}

void write_file(char* key, char* fileName){
  FILE* fp = fopen(fileName, "wb");//open the file to be written in binary
  int theKey = atoi(key);
  char writeArray[10000];
  if(fp == NULL){
    puts("File cannot be opened. Lo siento.");
    return;
  }
  int length = strlen(charArray);
  for(int i = 0; i < length; i++){
    writeArray[i] = charArray[i]^theKey;//encrypt/decrypt the file's contents
    fwrite(&writeArray[i], sizeof(char), 1, fp);//save the encrypted/decryped data to the second file
  }  
  puts("You have successfully encrypted/decypted your file! You're a rockstar! :D");
  fclose(fp);
  return;
}
