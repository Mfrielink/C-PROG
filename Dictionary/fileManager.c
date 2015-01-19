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
				if (fgets(line, CHUNK, file) == NULL){
					fclose(file);
					return "empty";
				}
				if ((lineNumber - 1) == lineCounter){
					tmp = line;
				}
		lineCounter++;
	}

	fclose(file);

	return tmp;
}

void emptyFile(){
	FILE *file;

	if (fopen_s(&file, fileLocation, "w") != NULL){
		perror("Error opening file; File is empty");
		return(-1);
	}

	fprintf(file, "%s", "");

	fclose(file);
}

void writeFile(char* input){

	char line[CHUNK];
	FILE *file;

	if (fopen_s(&file, fileLocation, write) != NULL){
		perror("Error opening file; File is empty");
		return(-1);
	}

	fprintf(file, "%s", input);

	fclose(file);
}


