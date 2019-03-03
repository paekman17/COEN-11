//files.h lists all of the functions to read and write from binary files
#ifndef FILES_H //header guards to prevent double declaration
#define FILES_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_file(char* fileName);
void print_file(char* fileName);
void writeBinary(char* binaryName);
void readBinary(char* binaryName);

#endif
