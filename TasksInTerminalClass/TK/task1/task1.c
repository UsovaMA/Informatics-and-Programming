#include <stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");
  int a, b, c;
  float a1, a2, a3, a4;
	
	printf("������� 3 �������= ");
    scanf_s("%d %d %d", &a, &b, &c);

  a1 = (a + b + c) / 3;
    printf("�������=%.1f\n", a1);

  a2 = (pow(a, 2) + pow(b, 2) + pow(c, 2)) / 3;
    printf("sqr �������=%.1f\n", a2);

  a3 = (fabs(a) + fabs(b) + fabs(c)) / 3;
    printf("fabs �������=%.1f\n", a3);

  a4 = (sqrt(a) + sqrt(b) + sqrt(c)) / 3;
	printf("sqrt �������=%.1f\n", a4);

	return 0;
}