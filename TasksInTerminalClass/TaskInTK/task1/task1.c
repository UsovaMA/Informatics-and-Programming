#include <stdio.h>
#include <math.h>

int main() //start programm
{
	/*Inputing variables*/
	int a, b, c;
	float aver1, aver2, aver3, aver4;

	printf("Input three numbers = ");
	scanf_s("%d %d %d", &a, &b, &c);

	aver1 = (a + b + c) / 3;
	printf("Average = %.1f\n", aver1);

	aver2 = (pow(a, 2) + pow(b, 2) + pow(c, 2)) / 3;
	printf("Sqr Average = %.1f\n", aver2);

	aver3 = (fabs(a) + fabs(b) + fabs(c)) / 3;
	printf("Fabs Average = %.1f\n", aver3);

	aver4 = (sqrt(a) + sqrt(b) + sqrt(c)) / 3;
	printf("Sqrt Average = %.1f\n", aver4);

	return 0;
}