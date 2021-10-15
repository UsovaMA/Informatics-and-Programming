#include <stdio.h>
#include <math.h>
#define Pi 3.14159

int main() //start programm
{
	/*Triangle*/
		float a1, h, S1;

	/*Inputing a side*/
		printf("Input a side = ");
		scanf_s("%f", &a1);

	/*Inputing a height*/
		printf("Input a height = ");
		scanf_s("%f", &h);

	/*Taking a result*/
		S1 = 0.5 * a1 * h;
		printf("Area = %.1f\n", S1);

	/*Rectangle*/
		float a2, b1, S2;

	/*Inputing a sides*/
		printf("Input two sides = ");
		scanf_s("%f %f", &a2, &b1);

	/*Taking a result*/
		S2 = a2 * b1;
		printf("Area = %.1f\n", S2);

	/*Circle*/
		float r, S3;

	/*Inputing a radius*/
		printf("Input a radius = ");
		scanf_s("%f", &r);
	
	/*Taking a result*/
		S3 = r * r * Pi;
		printf("%.2f", S3);

	return 0;
}