#include <stdio.h>
#include <locale>
int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 5;
	while (n != 0)
	{
		printf("1 - треугольник		2 - прямоугольник 	 3 - окружность		0 - выход из программы\n");
		scanf_s("%d", &n);
		double a = 0;
		double b = 0;
		double S = 0;
		switch (n)
		{
		case 0:
			break;
		case 1:
		{
			printf("Введите высоту и основание треугольника\n");
			scanf_s("%lf %lf", &a, &b);
			S = a * b * 0.5;
			printf("Площадь треугольника = %.2lf\n", S);
			break;
		}
		case 2:
		{
			printf("Введите 2 стороны прямоугольника\n");
			scanf_s("%lf %lf", &a, &b);
			S = a * b;
			printf("Площадь прямоугольника = %.2lf\n", S);
			break;
		}
		case 3:
		{
			printf("Введите радиус окружности\n");
			scanf_s("%lf", &a);
			S = 3.14 * a * a;
			printf("Площадь окружности = %.2lf\n", S);
			break;
		}
		default:
		{
			printf("Введите одну из предложенных цифр, уважаемый\n");
			break;
		}
		}
	}
	return 0;
}