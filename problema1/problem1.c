// c file pt problema 1
// http://community.topcoder.com/stat?c=problem_statement&pm=2913&rd=5849

#include "problem1.h"

char **existingNames;

int stringCompare(char *string1, char *string2){

	size_t result = 0;
	size_t len1 = strlen(string1);
	size_t len2 = strlen(string2);

	//printf("|Size1:%lu  Size2:%lu|\n", len1, len2);

	if(len1 != 0 && len2 != 0 && len1 == len2){
		for(int i = 0; i < len1; i++){
			if(tolower(string1[i]) == tolower(string2[i])){
				result++;
			}
		}
	}
	return (result == len1) ? 1 : 0;
}

char* suggestName(char *name, int index){

	static char buffer[50];
	sprintf(buffer,"%s%d",name,index);
	return buffer;
}

int checkName(char **Names, char *name){

	int ret = 0;

	for(int i = 0; i < n_array; i++){
		if(stringCompare(Names[i], name) == 1){
			ret = 1;
		}
	}
	return ret;

}

void process(char *newName){

	int index = 1;
	char *suggestionName;
	int res;

	res = checkName(existingNames, newName);
	printf("Match found: %d\n", res);

	if(res == 1){
		if(isdigit(newName[strlen(newName) - 1])){
			int cdigit = 0;
			for(int i = strlen(newName) - 1; i >= 0; i--){
				if(isdigit(newName[i])){
					cdigit++;
				}				
			}
		printf("User already exists!!!\n");
		printf("Username ends in %d digits\n", cdigit);

		int offset = strlen(newName) / sizeof(char) - cdigit;

		printf("Digits offset: %d\n", offset);

		char uname[offset];
   		char end[cdigit];
   		memcpy(uname, newName, offset);
   		memcpy(end, newName + offset, cdigit);

   		printf("User part: %s\n", uname);
		printf("Digits part: %s\n", end);

   		char *ptr;
   		long ret;
   		ret = strtol(end, &ptr, 10);

		for(int n = (int)ret; ; n++){
			if(checkName(existingNames, suggestName(uname, n)) == 0){
				printf("Suggestion: %s\n", suggestName(uname, n));
				break;
			}
		}
		for(int n = 0; n >= 0; n++){
			if(checkName(existingNames, suggestName(uname, n)) == 0){
				printf("Suggestion: %s\n", suggestName(uname, n));
				break;
			}
		}

		}else{
			while(checkName(existingNames, suggestName(newName, index)) == 1){
			index++;
			}
			suggestionName = suggestName(newName, index);
			printf("Suggestion: %s\n", suggestionName);

		}
		
	}else{
		printf("Username is available!\n");
	}
}


int main(void){

	existingNames = (char**)malloc(n_array);

	existingNames[0] = "MasterOfDisaster";
	existingNames[1] = "DingBat";
	existingNames[2] = "DingBat123";
	existingNames[3] = "DingBat2";
	existingNames[4] = "DingBat3";
	existingNames[5] = "Orpheus1";
	existingNames[6] = "WolfMan";
	existingNames[7] = "MrKnowItAll";

	while(1){
		char newName[50];
		printf("Please enter a new name: ");
		//scanf("%s", newName);
		int result = scanf("%99[^\n]%*c", newName);
		if(result != 1){
			printf("Exiting...\n");
			break;
		}
		process(newName);
		
	}

return 0;

}




