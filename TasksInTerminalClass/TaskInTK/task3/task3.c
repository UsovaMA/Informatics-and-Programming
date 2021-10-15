#include <stdio.h>
#include <math.h>
#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int num, inverse_num = 0;

	while (true)
	{
		printf("Input the number: ");
		scanf_s("%d", &num);
		if (num > 0) 
			break;
		else
			printf("Wrong range, choose another number!\n");
	}

	while (num != 0) {
		
		inverse_num *= 10;
		inverse_num += num % 10;
		num /= 10;
	}

	printf("Inverse number equals: %d", inverse_num);

}