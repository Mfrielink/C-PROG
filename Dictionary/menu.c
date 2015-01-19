#include "menu.h"

void startingMenu(){
	printf("Welcome to the dictionary. \n");
	printf("This program recognizes the following commands: \n");
	printf("'1' to add\n'2' to edit\n'3' to remove\n'4' to search\n'5' to print all\n'6' to exit\n");
}

int goThroughMenu(){
	printf("\ntype a command of your choice: ");
	int input = readMenuChoice();

	switch (input){
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;
		break;
	case 5:
		return 5;
		break;
	case 6:
		return 6;
		break;
	}

	return 0;
}