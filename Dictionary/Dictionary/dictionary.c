#include "dictionary.h"

void initArray(Array *a, int initialSize)
{
	// Allocate initial space
	a->array = (relatie1 *)malloc(initialSize * sizeof(relatie1));

	a->used = 0; // no elements used
	a->size = initialSize; // available nr of elements
}

void insertArray(Array *a, relatie1 x, int size)
{
	printf("%d\n", a->size);
	printf("word: %s\n", x.word);
	printf("translation: %s\n", x.translation);

	a->size = size;

	if (a->used == a->size)
	{
		a->size *= 2;
		printf("Nieuwe size is %d\n", a->size);
		a->array = (relatie1 *)realloc(a->array, a->size * sizeof(relatie1));
	}
	a->array[a->used] = x;
	a->used++;
}

void freeArray(Array *a)
{
	// Now free the array 
	free(a->array);
}

void readAndFill(Array *a){
	char * check = "";
	char * tmp = "a";
	relatie1 x;

	while (1){ //strcmp(check,tmp) != 0
		tmp = readLine(a->used + 1);
		
		if (strcmp(check, tmp) == 0){
			strcpy_s(check,2, " ");
			printf("Done reading file..\n");
			break;
		}else{
			check = readLine(a->used + 1);
		}

		x.word = malloc(32 * sizeof(char));
		printf("tmp1 = %s\n", tmp);
		x.word = getWord(tmp);
		printf("tmp2 = %s\n", tmp);

		x.translation = malloc(32 * sizeof(char));
		x.translation = getTranslation(tmp);

		if (a->used == a->size)
		{
			a->size *= 2;
			a->array = realloc(a->array, a->size * sizeof(relatie1));
		}

		a->array[a->used] = x;
		a->used++;

		printf(" tmp: %s\n", tmp);
		printf(" check: %s\n", check);
	}
}

