#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() //Объявляем начало программы
{
	setlocale(LC_ALL, "Russian"); // Переводим текст на русский язык

	/* Ввводим x1, y1 первой окружности, а так же ее R*/

	printf("Введите координаты I окружности: \n");
	int x1, y1;
	scanf_s("%d %d", &x1, &y1);

	printf("Введите радиус I окружности: \n");

	int r1;
	scanf_s("%d", &r1);

	/* Ввводим x2, y2 второй окружности, а так же ее R */

	printf("Введите координаты II окружности: \n");
	int x2, y2;
	scanf_s("%d %d", &x2, &y2);

	printf("Введите радиус II окружности: \n");

	int r2;
	scanf_s("%d", &r2);

	/* Найдем расстояние между центрами окружностей d */

	int d, diff1, diff2, diff3;

	diff1 = x2 - x1;
	diff2 = y2 - y1;
	diff3 = pow(diff1, 2) + pow(diff2, 2);

	d = sqrt(diff3);

	/* Рассмотрим все случае, и выясним взаимное расположение окружностей */

	if ((r1 + r2 > d) && (r1 + d > r2) && (r2 + d > r1))
		printf("Окружности пересекаются");
	else
		if ((r1 + r2 == d) || (abs(r1 - r2) == d))
			printf("Окружности касаются");
		else
			printf("Окружности не касаются");

	return 0;
}