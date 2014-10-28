#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "string.h"

typedef struct
{
	char * word;
	char * translation;
} relatie1;

// array of structs
typedef struct
{
	relatie1 *array;
	size_t used;
	size_t size;
} Array;

void initArray(Array *a, int initialSize);
void insertArray(Array *a, relatie1 element);
void freeArray(Array *a);

void readAndFill(Array *a);