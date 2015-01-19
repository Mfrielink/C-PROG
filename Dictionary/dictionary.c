#include "dictionary.h"

void initArray(Dictionary *a, int initialSize)
{
	// Allocate initial space
	a->array = malloc(initialSize * sizeof(relatie2));

	a->used = 0; // no elements used
	a->size = initialSize; // available nr of elements
}

void freeArray(Dictionary *a)
{
	// Now free the array 
	free(a->array);
}

void readAndFill(Dictionary *a){
	char tmp[80] = "a";
	relatie2 x;

	while (readLine(a->used + 1) != "empty"){ 
		// copy the whole line from the file into a buffer.
		strcpy_s(tmp, 32, readLine(a->used + 1));

		/* remove newline, if present */
		int i = (strlen(tmp) - 1);
		if (tmp[i] == '\n'){
			tmp[i] = '\0';
		}

		x.word = malloc(32 * sizeof(char));
		x.translation = malloc(32 * sizeof(char));

		// copy the splitted words from the buffer into separate strings
		strcpy_s(x.word, 32, getWord(tmp));
		strcpy_s(x.translation, 32, getTranslation(tmp));

		if (a->used == a->size)
		{
			a->size = a->size + 1;
			a->array = realloc(a->array, a->size * sizeof(relatie2));
		}
		a->array[a->used] = x;
		a->used++;

		
	}
}

void addToArray(Dictionary *a){
	relatie2 y;
	int correctInput = 0;
	char buffer[32] = "";
	printf("\nYou chose the command 'add'.\n");
	printf("Please enter the english word: ");

	while (correctInput == 0){
		strcpy_s(buffer, 32, readInput());

		if (checkExistenceWord(*&a, buffer)){
			correctInput = 1;
		}
		else{
			correctInput = 0;
			printf("That word is already in the dictionary\n");
			printf("Please enter another word: ");
		}

	}

	y.word = malloc(32 * sizeof(char));
	strcpy_s(y.word, strlen(buffer) + 1, buffer);

	correctInput = 0;
	printf("Please enter the dutch translation: ");

	strcpy_s(buffer, 32, readInput());

	y.translation = malloc(32 * sizeof(char));
	strcpy_s(y.translation, strlen(buffer) + 1, buffer);

	if (a->used == a->size)
	{
		a->size = a->size + 1;
		a->array = realloc(a->array, a->size * sizeof(relatie2));
	}
	a->array[a->used] = y;
	a->used++;

	printf("\nThe entry was: %s = %s\n", y.word, y.translation);
}

void editArray(Dictionary *a){
	relatie2 o, r;
	int correctInput = 0;
	char buffer[32] = "";
	printf("\nYou chose the command 'edit'.\n");
	printf("Please enter the english word you want to edit: ");

	while (correctInput == 0){
		strcpy_s(buffer, 32, readInput());

		if (checkExistenceWord(*&a, buffer)){ // True when word is not in array
			printf("That word does not exist in the dictionary \n");
			printf("Please enter another word: ");
			correctInput = 0;
		}
		else{ // word is in the array
			correctInput = 1;
		}
	
	}	
	int counter;
	for (counter = 0; counter < a->used; counter++){
		if (!strcmp(a->array[counter].word, buffer)){
			// get the place of the input in the array
			break;
		}
	}


	printf("Please enter the new enlgish word: ");

	strcpy_s(buffer, 32, readInput());

	o.word = malloc(32 * sizeof(char));
	strcpy_s(o.word, strlen(buffer) + 1, buffer);

	printf("Please enter the new dutch translation: ");

	strcpy_s(buffer, 32, readInput());

	o.translation = malloc(32 * sizeof(char));
	strcpy_s(o.translation, strlen(buffer) + 1, buffer);

	a->array[counter] = o;

	printf("%d ", counter);
	printf("\nThe entry was: %s = %s\n", a->array[counter].word, a->array[counter].translation);

}

void searchArray(Dictionary *a){
	int splitInput = 0;
	int counter;
	int t;
	int c = 0;
	int correctInput = 0;
	char buffer[32] = "";
	char tmp[32] = "";
	printf("\nYou chose the command 'search'.\n");
	printf("Please enter the english word: ");

	strcpy_s(buffer, 32, readInput());

	// look through the array for the word.
	for (t = 0; t <= strlen(buffer); t++) {
		if (buffer[t] == ' ' || buffer[t] == '\0') {
			if (checkExistenceWord(*&a, tmp)) { // True when word is not in array
				printf("%s does not exist in the dictionary \n", tmp);
				t++;
				c = 0;
				memset(tmp, 0, sizeof(tmp));
			}
			else { // word exists!
				for (counter = 0; counter < a->used; counter++) {
					if (!strcmp(a->array[counter].word, tmp)) {
						printf("%s = %s\n", a->array[counter].word, a->array[counter].translation);
						t++;
						c = 0;
						memset(tmp, 0, sizeof(tmp));
					}
				}
			}
		}

			if (buffer[t] != ' '){ //|| (buffer[t] != '\0')	
				tmp[c] = buffer[t];
				c++;
			}
		}
}

void removeFromArray(Dictionary *a){
	relatie2 r;
	int correctInput = 0;
	char buffer[32] = "";
	printf("\nYou chose the command 'remove'.\n");
	printf("Please enter the english word: ");

	while (correctInput == 0){
		strcpy_s(buffer, 32, readInput());

		if (checkExistenceWord(*&a, buffer)){ // True when word is not in array
			printf("That word does not exist in the dictionary \n");
			printf("Please enter another word: ");
			correctInput = 0;
		}
		else{ // word is in the array
			correctInput = 1; 
		}
	}
	int counter;
	for (counter = 0; counter < a->used; counter++){
		if (!strcmp(a->array[counter].word, buffer)){
			printf("The word %s and its translation %s, are removed from the dictionary\n", a->array[counter].word, a->array[counter].translation);
			break;
		}
	}
	r.word = malloc(32 * sizeof(char));
	strcpy_s(r.word,1 , "");

	r.translation = malloc(32 * sizeof(char));
	strcpy_s(r.translation,1 , "");

	a->array[counter] = r;
}

int checkExistenceWord(Dictionary *a, char* word){
	int counter = 0;
	for (counter = 0; counter < a->used; counter++){
		if (!strcmp(a->array[counter].word, word)){
			return 0;
		}
	}
	return 1;
}

