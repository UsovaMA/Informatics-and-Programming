#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

/*Начало основной программы*/

int main()
{
	int num, kol, mode, random;
	random = rand() % 100 + 1;
	printf("%d\n", random);

	printf("Choose your mode (1 or 2): ");
	scanf_s("%d", &mode);

	kol = 0;

	if (mode == 1) {
		do
		{
			kol = kol + 1;
			printf("Choose your number: ");
			scanf_s("%d", &num);
			if (num > random)
				printf("Number is bigger!\n");
			if (num < random)
				printf("Number is lower!\n");
			if (num == random)
				printf("You guessed a number! Number of trys is: %d", &kol);
		} while (num != random);
	}

	return 0;
}