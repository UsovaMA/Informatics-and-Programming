#include<locale.h>
#include<math.h>
#include<stdio.h>

void main()
{
	setlocale(LC_ALL, "rus");
	int a, b, c;
	float sraf, srkv, srmd, srkr;
	printf(" Введите три числа : ");
	scanf_s("%d %d %d", &a, &b, &c);
	sraf = (a + b + c) / 3;
	srkv = (a ^ 2 + b ^ 2 + c ^ 2) / 3;
	srmd = ((fabs(a) + fabs(b) + fabs(c)) / 3);
	srkr = ((sqrt(a) + sqrt(b) + sqrt(c)) / 3);
	printf(" Среднее арифметическое этих чисел = %f \n", sraf);
	printf(" Среднее арифметическое квадратов  этих чисел = %f \n", srkv);
	printf(" Среднее арифметическое модулей этих чисел = %f \n", srmd);
	printf(" Среднее арифметическое корней этих чисел = %f \n", srkr);

	return 0;
}