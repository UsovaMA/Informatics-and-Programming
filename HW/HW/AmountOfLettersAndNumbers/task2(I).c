#include <stdio.h>
#include <math.h>
#ifndef cplusplus
#define bool int
#define true 1
#define false 0
#endif

void guess_number(){
	int number, count = 0, random_number;
	srand(time(0));
	random_number = rand() % 1000 + 1;
	while (true) {
		printf("Input the number: ");
		scanf_s("%d", &number);
		count++;
		if (number < random_number) 
			printf("The hidden number is greater!\n");

		if (number > random_number) 
			printf("The hidden number is smaller\n");

		if (number == random_number) {
			printf("You guessed the number!\n");
			break;
		}
	}
	printf("The hidden number is: %d\n", number);
	printf("The count of attemps is: %d\n", count);	
}

void input_number() {
	int number, count = 0, x1 = 0, x2 = 1000, flag = 0, guess_num;
	char input;
	printf("Input the number: ");
	scanf_s("%d", &number);
	while ((x1 < x2) && (flag == 0)) {
		guess_num = x1 + ((x2 - x1) / 2);
		printf("Is hidden number: %d?\n", guess_num);
		scanf_s("%c", &input, 1);
		input = getchar(); //Added with VSCode
		count++;
		switch (input)
		{
		case '>': x1 = guess_num;
			break;
		case '<': x2 = guess_num;
			break;
		case '=': printf("PC is right!\n");
			flag = 1;
			break;
		}
	}
	printf("The hidden number is: %d\n", guess_num);
	printf("The count of attemps is: %d", count);
 }

int main() {
	int program;
	while (true) {
		printf("Choose your mode(1 or 2): ");
		scanf_s("%d", &program);
		if ((program == 1) || (program == 2))
			break;
	}
	if (program == 1)
		guess_number();
	if (program == 2)
		input_number();
}