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
