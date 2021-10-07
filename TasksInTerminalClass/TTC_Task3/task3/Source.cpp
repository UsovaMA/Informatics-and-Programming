#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int number, iswork = 1;
	while (iswork)
	{
		printf("Lets input numbers\n");
		printf("For exit enter 0\n");
		int iserror = 0;
		do
		{
			if (iserror) printf("Wrong input! Try again."); 
			printf("\nInput positive number: ");
			scanf("%d", &number);
			if (number == 0) iswork = 0; break;
			iserror = (number <= 0);
		} while (iserror);
		int inverse = 0;
		while (number)
		{
			inverse *= 10;
			inverse += number % 10;
			number = number / 10;
		}
		if (iswork) printf("\nresult: %d\n\n", inverse);
		if (iswork) printf("\nexit\n\n");
	}	
	return 0;
}