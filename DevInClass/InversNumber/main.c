#include <stdio.h>
/* Sozdat programmu inversirovania chisel */


int main() 
{
	int num, method, IsError, sum;
	sum = IsError = 0; // flag
	printf("This Programm for finding inverse number or sum of digits\n");
	printf("If you want to find inverse number enter 1\nif you want to find sum of digits enter 2\nFor exit print 0\n");
	while (1) {
		printf("Input method: ");
		scanf_s("%d", &method);
		IsError = (method == 1 || method == 2 || method == 0) ? 0 : 1;
		if (IsError) printf("Error. Isnt right method. Try again\n");
		if (method == 1) {
			do {
				if (IsError) printf("Error. Number isnt positive. Try again\n");
				printf("Input positive number\nFor exit enter 0\n");
				scanf_s("%d", &num);
				IsError = 1; // if while isnt end when input isnt right 
			} while (num < 0);
			IsError = 0; // if continue when inpust is right
			if (!num) continue;
			printf("Invers number: ");
			while (num) {
				if (num % 10) {
					printf("%d", num % 10);
				}
				num /= 10;
			}
			printf("\n");
		}
		else if (method == 2) {
			do {
				if (IsError) printf("Error. Number isnt positive. Try again\n");
				printf("Input positive number\nFor exit print 0\n");
				scanf_s("%d", &num);
				IsError = 1;
			}while(num < 0);
			IsError = 0;
			if (!num) continue;
			while (num) {
				sum = sum + num % 10;
				num /= 10;
			}
			printf("Sum of digits = %d\n", sum);
		}
		else if (method == 0) break;
	}
	printf("GoodBye!");
	return 0;
}
