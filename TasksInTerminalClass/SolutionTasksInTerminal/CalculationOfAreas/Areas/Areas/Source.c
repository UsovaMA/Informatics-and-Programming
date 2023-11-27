#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "russian");
	printf("Задача по двум окружностям \n");
	float x1, x2, y1, y2, r1, r2;
	float d;
	printf("Введите параметры 1-й окружности (в виде x y r): ");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Введите параметры 2-й окружности (в виде x y r): ");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if (d == r1 + r2)
	{
		printf("Касаются");;
	}
	if (d < r1 + r2)
	{
		if (d == 0 && r1 == r2)
		{
			printf("Совпадают");
		}
		else if (d + r1 < r2 || d + r2 < r1)
		{
			printf("Одна внутри другой");
		}
		else if (d == abs(r1 - r2)) 
		{
			printf("касаются внутри ");
		}
		else {
			printf("Пересекаются");
		}
	}
	if (d > r1 + r2)
	{
		printf("не пересекаются");
	}
	return 0;
}