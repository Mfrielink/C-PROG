#include "util.h"

char * getWord(char input[]){
	int wordCount = 0;
	char word[32] = "";

	while (input[wordCount] != ' '){
		word[wordCount] = input[wordCount];
		wordCount++;
	}

	return word;
}

char * getTranslation(char input[]){
	int wordCount = 0;
	int translationCount = 0;
	char translation[32] = "";

	while (input[wordCount] != ' '){
		wordCount++;
	}

	wordCount++;

	while (input[wordCount] != '\0'){
		translation[translationCount] = input[wordCount];
		wordCount++;
		translationCount++;
	}
	return translation;
}

char * readInput(){
	char str[80];
	int i;
	fgets(str, 80, stdin);

	/* remove newline, if present */
	i = (strlen(str) - 1);
	if (str[i] == '\n'){
		str[i] = '\0';
	}
	return str;
	printf("%s\n", str);
}

int readMenuChoice(){
	int  temp, status;

	scanf_s("%d", &status);
	scanf_s("%c", &temp);

	while ((status != 1) && (status != 2) && (status != 3) && (status != 4) && (status != 5) && (status != 6)){
		printf("Invalid input... please enter a correct command: ");
		scanf_s("%d", &status);
		scanf_s("%c", &temp);
	}

	return status;
}

