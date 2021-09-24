#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int  x1, x2, y1, y2, r1, r2, dist;
	printf("Введите через пробел координаты x, y и радиус r первой окружности:\n");
	scanf_s("%d %d %d", &x1, &y1, &r1);

	printf("Введите через пробел координаты x, y и радиус r второй окружности:\n");
	scanf_s("%d %d %d", &x2, &y2, &r2);

	//Найдем расстрояние окружностей во всех случаях

	dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	
	//Узнаем расположение окружностей


	if (dist == r1 + r2)
	{
		printf("Окружности касаются");
	}
	else if (dist < r1 + r2)
	{
		if ((dist == 0) && (r1 == r2))
		{
			printf("Окружности совпадают");
		}
		else if ((dist + r1 < r2) || (dist + r2 < r1))
		{
			printf("Одна окружность внутри с другой");
		}
		else
		{
			printf("Окружности пересекаются");
		}
	}
	if (dist > r1 + r2) 
	{
		printf("Окружности никак не связаны");
	}
};
