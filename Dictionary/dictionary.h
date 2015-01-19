#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "string.h"

typedef struct
{
	char * word;
	char * translation;
} relatie2;

// array of structs
typedef struct
{
	relatie2 *array;
	size_t used;
	size_t size;
} Dictionary;

void initArray(Dictionary *a, int initialSize);
void insertArray(Dictionary *a, relatie2 element, int size);
void freeArray(Dictionary *a);

void readAndFill(Dictionary *a);
void addToArray(Dictionary *a);

void addToArray(Dictionary *a);
void removeFromArray(Dictionary *a);
void searchArray(Dictionary *a);

int checkExistenceWord(Dictionary *a, char* word);