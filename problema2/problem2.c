// c file pt problema 2
// http://community.topcoder.com/stat?c=problem_statement&pm=1835&rd=4655

#include "problem2.h"

int isLegal(char *word){

	int retVal = FALSE;
	int vowelCount = 0;
	int letterCount = 0;
	int wordSize = (int)strlen(word);
	int startsOrEndsWithY = 0;
	char vowels[] = "aeiouy";
	char restriction = 'y';

	for(int i = 0; i < wordSize; i++)
	{
		for (int j = 0; j < strlen(vowels); j++)
		{
			if (word[i] == vowels[j])
			{
				vowelCount++;
			}
		}
		if (tolower(word[i]) >= 'a' && tolower(word[i]) <= 'z')
		{
			letterCount++;
		}
	}

	startsOrEndsWithY += (word[0] == restriction) ? 1 : 0;
	startsOrEndsWithY += (word[wordSize - 1] == restriction) ? 1 : 0;

	retVal = (vowelCount !=0 && letterCount == wordSize && (vowelCount != startsOrEndsWithY)) ? TRUE : FALSE;

	return retVal;

}


char **splitPoem(char *poem){

	char *str = malloc((strlen(poem) + 1) * sizeof(char));
	char **arrLines = malloc((strlen(poem) + 1) * sizeof(char));
	strcpy(str, poem);
	char *tok = NULL;
	int count = 0;
	int restrictionCount = 0;
	char *offset;
	tok = strtok(str, "\n");

	while(tok){
		printf("Line: %s\n", tok);
		offset = strrchr(tok, ' ');

		char *lword = ++offset;
		arrLines[count] = lword;
        tok = strtok(NULL, "\n");
        count++;
	}

	for (int i = 0; i < count; ++i)
	{
		printf("lword %d: %s\n", i, arrLines[i]);
	}

	return (restrictionCount == 0) ? arrLines : NULL;	
}


int verifyPoem(char* poem){

	char *str = malloc((strlen(poem) + 1) * sizeof(char));
	strcpy(str, poem);
	char *tok = NULL;
	int retVal = 0;

	tok = strtok(str, " \n");

	while(tok && *tok != '\n'){
		
		if (isLegal(tok) == FALSE)
		{
			retVal++;
			break;
		}
		printf("word: %s\n", tok);

        tok = strtok(NULL, " \n");
	}
	return retVal;
}

char *checkRhyme(char *word1, char *word2){

}


int main(int argc, char const *argv[])
{
	int okProcess = 0;
	char *poem = "One bright day in the middle of the night\nTwo dead boys got up to fight\nBack to back they faced each other\nDrew their swords and shot each other";
	//char *poem = "too bad   your\n\n\n     solution went   sour";

	if (verifyPoem(poem) == 0)
	{
		char **result = splitPoem(poem);
		if (result != NULL)
		{
			printf("%s\n", "The poem is VALID.");
		}else{
			printf("%s\n", "The poem is not VALID.");
		}

	}else{
		printf("%s\n", "The poem is not VALID.");	
	}

	return 0;
}
