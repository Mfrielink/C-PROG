#include "program.h"

int main(int argc, const char * argv[])
{
	Array a;
	a.array = (relatie1 *)malloc(1 * sizeof(relatie1));

	a.used = 0; // no elements used
	a.size = 1; // available nr of elements

	printf("Finished initialization..\n");

	// Fill array with .txt content
	readAndFill(&a);
	printf("Finished filling array with .txt content..\n");

	printf("%s\n", a.array[0].word);
	printf("%s\n", a.array[0].translation);


	// Free array
	freeArray(&a);



	printf("The end!\n");
	while (1){

	}

	return 0;
}



//x.translation = "banaan";
//x.word = "banana";

//y.translation = "leraar";
//y.word = "teacher";

//// Add elements 
//insertArray(&a, x);
//insertArray(&a, y);

// Print elements

