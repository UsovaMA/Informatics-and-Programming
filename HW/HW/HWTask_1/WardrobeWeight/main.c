#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "Russian");

	double Den_DSP = 700, Den_DVP = 300, Den_Wood = 1000, BackWall, SideWalls, doors, racks, tops, thickness_15 = 0.015, thickness_5 = 0.005, thickness_10 = 0.01, a, h, w, d, LockerWeight;

	printf("Введите данные шкафа(высота от 1.8м до 2.2м и ширина от 0.8м до 1.2м): ");
	scanf_s("%lf %lf", &h, &w);
	if (1.8 <= h && h <= 2.2 && 0.8 <= w && w <= 1.2)
	{

		printf("Введите данные(глубина от 0.5м до 0.9м): ");
		scanf_s("%lf", &d);
		if (0.5 <= d && d <= 0.9)
		{

			LockerWeight = ((h * w * thickness_5) * Den_DVP) + (((h * d * thickness_15) * Den_DSP) * 2) + ((w * d * thickness_15) * Den_DSP) + ((h * w * thickness_10) * Den_Wood);
			if (h <= 2)
			{
				racks = 4;

				LockerWeight = LockerWeight + ((w * d * thickness_15) * Den_DSP) * racks;

				printf("Вес шкафа:  %.2lf", LockerWeight);
			}
			else
			{
				racks = 5;

				LockerWeight = LockerWeight + ((w * d * thickness_15) * Den_DSP) * racks;

				printf("Вес шкафа:  %.2lf", LockerWeight);

			}

		}
		else
		{
			printf("Введены некорректные данные!!!");
		}

	}
	else
	{
		printf("Введены некорректные данные!!!");
	}
	_getch();
	return 0;
}