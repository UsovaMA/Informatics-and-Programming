#include <stdio.h>
#include <math.h>
#define M_PI 3.14

int main()
{
	float a, h, S;



	printf("vvedite storonu = ");
	scanf_s("%f", &a);

	printf("vvedite visotu = ");
	scanf_s("%f", &h);

	S = 0.5 * a * h;
	printf("ploshad = %.1f\n", S);

	float a1, b1, S1;



	printf("vvedite vtoruyu storonu = ");
	scanf_s("%f %f", &a1, &b1);

	S1 = a1 * b1;
	printf("ploshad = %.1f\n", S1);

	float r, S2;


	printf("vvedite radius = ");
	scanf_s("%f", &r);

	S2 = r * r * M_PI;
	printf("%.2f", S2);

	return 0;
}