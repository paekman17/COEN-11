//files.c which contains all of the functions to read and write to binary and text files
#include "files.h"
#include "lists.h"

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
    pthread_mutex_lock(&mutex);
    insert(input, number);
    pthread_mutex_unlock(&mutex);
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

void* autosave(void* arg){//function that autosaves data from the linkedlists to a text file every five seconds
  int running = 1;
  while(running == 1){
    sleep(5);//save every five seconds
    FILE*fp = fopen("auto-save.txt", "w");
    fprintf(fp, "Name\tGroup Size\n------------------\n");
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < 4; i++){
      node* current = head[i];
      while(current != NULL){
	fprintf(fp, "%s\t%d\n", current->name, current->data);
	current = current->next;
      }
    }
    pthread_mutex_unlock(&mutex);
    fclose(fp);
  }
  return NULL;
}
