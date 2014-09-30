//header file pt problema 2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isLegal(char *word);
char **splitPoem(char *poem);
int verifyPoem(char* poem);
char *checkRhyme(char *word1, char *word2);

