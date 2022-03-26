#include<locale.h>
#include<stdio.h>
#include<math.h>
#define pi 3.14

int main()
{
	setlocale(LC_ALL, "RU");
	int vst, osn, Str, strn1, strn2, Sprm, R, number;
	float So;
	printf("Введите номер фигуры  1 - Треугольник | 2 - Прямоугольник | 3 - окружность \n");
	scanf_s("%d", &number);
	switch (number)
	{
	case 1:
	{
		printf("Введите высоту и основание треугольника : ");
		scanf_s("%d %d", &vst, &osn);
		Str = vst * osn / 2;
		printf(" Площадь треугольника = %f \n", Str);
	} break;

	case 2:
	{
		printf("Введите стороны прямоугольника : ");
		scanf_s("%d %d", &strn1, &strn2);
		Sprm = strn1 * strn2;
		printf(" Площадь прямоугольника = %d \n", Sprm);
	} break;

	case 3:
	{
		printf("Введите радиус окружности : ");
		scanf_s("%d", &R);
		So = pi * R * R * 0.5;
		printf(" Площадь окружности = %f \n", So);
	} break;

	return 0;
	}	
}
 

