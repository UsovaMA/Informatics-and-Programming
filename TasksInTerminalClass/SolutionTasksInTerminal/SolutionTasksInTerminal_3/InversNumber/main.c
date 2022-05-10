#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int number, isError = 0, isWork = 1;
	while (isWork)
	{
		printf("Let's invers numbers!\n");
		printf("For exit enter 0\n");
		do
		{
			if (isError)

			printf ("Wrong input! Try again\n");

			printf ("Imput positiv number: ");
			scanf_s("%d", &number);
		    
			if (number == 0)
			{
				isWork = 0;
				break;
			}
			isError = (number <= 0);

		} while (isError);

		int invers = 0;

		while (number != 0)
		{
			invers = invers * 10 + number % 10;

			number = number / 10;

		}
		
		printf("Result: %d", invers);
		break;
	}
	
	return 0;
}