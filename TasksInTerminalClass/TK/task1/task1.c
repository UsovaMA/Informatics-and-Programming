#include <stdio.h>
#include<math.h>

int main()
{
	int a, b, c;
	float a1, a2, a3, a4;
	
	printf("vvedite tri chisla= ");
	scanf_s("%d %d %d", &a, &b, &c);
	a1 = (a + b + c) / 3;
	printf("srednee=%.1f\n", a1);
	a2 = (pow(a, 2) + pow(b, 2) + pow(c, 2)) / 3;
	printf("sqr srednee=%.1f\n", a2);
	a3 = (fabs(a) + fabs(b) + fabs(c)) / 3;
	printf("fabs srednee=%.1f\n", a3);
	a4 = (sqrt(a) + sqrt(b) + sqrt(c)) / 3;
	printf("sqrt srednee=%.1f\n", a4);

	return 0;
}