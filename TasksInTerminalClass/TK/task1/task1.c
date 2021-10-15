#include <stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");
  int a, b, c;
  float a1, a2, a3, a4;
	
	printf("введите 3 стороны= ");
    scanf_s("%d %d %d", &a, &b, &c);

  a1 = (a + b + c) / 3;
    printf("среднее=%.1f\n", a1);

  a2 = (pow(a, 2) + pow(b, 2) + pow(c, 2)) / 3;
    printf("sqr среднее=%.1f\n", a2);

  a3 = (fabs(a) + fabs(b) + fabs(c)) / 3;
    printf("fabs среднее=%.1f\n", a3);

  a4 = (sqrt(a) + sqrt(b) + sqrt(c)) / 3;
	printf("sqrt среднее=%.1f\n", a4);

	return 0;
}