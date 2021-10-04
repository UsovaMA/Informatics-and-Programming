#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

int main()/*Start programm */ {
	int number = 0, working = 1;
	while (working){

		int error = 0;
		do {
			if (error)
				printf("Wrong range of number, please, try again!\n");
			
			printf("Enter number > 0: ");
			scanf_s("%d", &number);
			if (number == 0)
				working = 0;
			break;

		} while (error);
	}
}