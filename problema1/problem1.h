//header file pt problema 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ELEMENTS 8
#define n_array ELEMENTS

int stringCompare(char *string1, char *string2);

char* suggestName(char *name, int index);

int checkName(char **Names, char *name);

void process(char *newName);

