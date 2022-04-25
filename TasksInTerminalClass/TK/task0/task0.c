#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M_PI 3.14

int main()
{
  setlocale(LC_ALL, "Rus");
  float a, h, S;

	printf("введите сторону= ");
	scanf_s("%f", &a);

	printf("введите высоту = ");
	scanf_s("%f", &h); 

  S = 0.5 * a * h;
	printf("площадь = %.1f\n", S);
 
  float a1, b1, S1;

	printf("введите вторую сторону = ");
	scanf_s("%f %f", &a1, &b1);

	S1 = a1 * b1;
	printf("площадь = %.1f\n", S1);

  float r, S2;

	printf("введите радиус = ");
	scanf_s("%f", &r);

  S2 = r * r * M_PI;
	printf("%.2f", S2);

	return 0;
}