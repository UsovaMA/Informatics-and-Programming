#include<stdio.h>;
#include<locale.h>;
#include<math.h>;

int main()
{
	setlocale(LC_ALL, "ru");
	float d, x1, y1, r1, x2, y2, r2;
	printf("Введите координаты x1,y1,r1 :");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Введите координаты x2, y2, r2 :");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (d > r1 + r2)
	{
		printf("Окружности не пересекаются");
	}
	else if (d == r1 + r2)
	{
		printf("Внешнее касание двух окружностей");
	}
	else if (d == r1 - r2)
	{
		printf("Внутреннее касание двух окружностей");
	}
	else if (d < r1 - r2)
	{
		printf("Одна из окружностей лежит внутри другой");
	}
	else if (r1 - r2 < d < r1 + r2)
	{
		printf("Окружности пересекаются в двух точках");
	}
	return 0;
}

