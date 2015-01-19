#include "program.h"

int main(int argc, const char * argv[])
{
	Dictionary a;
	a.array = malloc(1 * sizeof(relatie2));
	int exit = 0;

	a.used = 0; // no elements used
	a.size = 1; // available nr of elements

	printf("Finished initialization..\n");

	// Fill array with .txt content
	readAndFill(&a);
	printf("Finished filling array with .txt content..\n\n");

	startingMenu();
	while (!exit){
		switch (goThroughMenu()){
		case 1:
			// case; add word and translation to dictionary.
			addToArray(&a);
			printf("\n");
			startingMenu();
			break;
		case 2:
			// case; edit a word or/and translation in the dictionary.
			editArray(&a);
			printf("\n");
			startingMenu();
			break;
		case 3:
			// case; remove a word and its translation from the dictionary.
			removeFromArray(&a);
			printf("\n");
			startingMenu();
			break;
		case 4:
			// case; search for a word and its translation in the dictionary.
			searchArray(&a);
			printf("\n");
			startingMenu();
			break;
		case 5:
			// case; print all the content from the dictionary.
			printDictionary(&a);
			printf("\n");
			startingMenu();
			break;
		case 6:
			// case; exit program.
			exit = 1;
			printf("\nThe command you chose was 'exit'.\nThe program will now shut down.\n");
			writeArrayToFile(&a);
			break;
		}

	}

	// Free array
	freeArray(&a);


	return 0;
}

void printDictionary(Dictionary *a){
	printf("The command you chose was 'print all'.\n\n");
	int c;
	for (c = 0; c < a->used; c++){
		if (!strcmp(a->array[c].word, "")){
			// do nothing, since this spot in the array was deleted.
		}
		else{
			printf("%s = %s\n", a->array[c].word, a->array[c].translation);
		}
	}
	printf("\n");
}

void writeArrayToFile(Dictionary *a){
	char tmp1[32];
	char tmp2[32];
	char output[80] = "";
	int c;
	emptyFile();

	for ( c = 0; c < a->used; c++)
	{
		if (!strcmp(a->array[c].word, "")){
			// do nothing, since this spot in the array was deleted.
		}
		else{
			strcpy_s(tmp1, 32, a->array[c].word);
			strcpy_s(tmp2, 32, a->array[c].translation);

			sprintf_s(output, 80, "%s %s\n", tmp1, tmp2);
			writeFile(output);

			// clears the output, in case of a shorter output than the last one. 
			strcpy_s(output, 2, " ");
		}

	}
}