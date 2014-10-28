#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"


void readFile(){

	char line[CHUNK];
	FILE *file;

		if (fopen_s(&file, fileLocation, read) != NULL){
			perror("Error opening file; File is empty");
			return(-1);
		}
		while (!feof(file)){
			if(fgets(line, CHUNK, file) != NULL){
				printf("%s \n", line);
			}
		}

		fclose(file);
	}

char *readLine(int lineNumber){
	char line[CHUNK];
	FILE *file;
	char * tmp;

	int lineCounter = 0;

	if (fopen_s(&file, fileLocation, read) != NULL){
		perror("Error opening file; File is empty");
		return(-1);
	}
	while (lineNumber > lineCounter){
		
			if (fgets(line, CHUNK, file) != NULL){
				if (feof(file)){
					fclose(file);
					return "empty";
				}
				if ((lineNumber - 1) == lineCounter && !feof(file)){
				tmp = line;
			}
				tmp = line;
		}
		lineCounter++;
	}

	fclose(file);
	return tmp;
}

void writeFile(char* input){

	char line[CHUNK];
	FILE *file;

	if (fopen_s(&file, fileLocation, write) != NULL){
		perror("Error opening file; File is empty");
		return(-1);
	}

	fprintf(file, "%s\n", input);

	fclose(file);
}

void readInput(){
	char str[80];
	int i;

	printf("\nEnter a string: ");
	fgets(str, 80, stdin);

	/* remove newline, if present */
	i = strlen(str) - 1;
	if (str[i] == '\n')
		str[i] = '\0';

	printf("This is your string: %s\n", str);

	writeFile(str);
	
}

