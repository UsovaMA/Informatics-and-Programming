#include <stdio.h>
#include <locale>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	printf("Введите три целых числа\n");
	scanf_s("%d %d %d", &a, &b, &c);
	double Aver = (a + b + c) / 3;
	printf("Среднее арифметическое этих чисел = %.2lf\n", Aver);
	Aver = ((a * a) + (b * b) + (c * c));
	printf("Среднее квадратов этих чисел = %.2lf\n", Aver);
	Aver = (abs(a) + abs(b) + abs(c))/3;
	printf("Среднее модулей этих чисел = %.2lf\n", Aver); 
	Aver = (sqrt(a) + sqrt(b) + sqrt(c))/3;
	printf("Среднее корней этих чисел = %.2lf\n", Aver);
	return 0;
}