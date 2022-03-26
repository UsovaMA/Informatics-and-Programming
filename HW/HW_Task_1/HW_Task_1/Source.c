#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "RUS");

	int dsp, dvp, wd;
	printf("Введите плотности ДВП ДСП Дерева - \n");
	scanf_s("%d %d %d", &dvp, &dsp, &wd);

	int Pkl, h, d, w, t2 = 1;
	float M, door, pol, kr, st, bok, t1 = 0.5, t3 = 1.5;

	printf("Введите высоту (от 180 до 220), Ширину (от 80 до 120), Глубину (от 50 до 90) \n");
	scanf_s("%d %d %d", &h, &w, &d);

	int check;

	if ((h > 179 && h < 221) && (w > 79 && w < 121) && (d > 49 && d < 91))
		check = 1;
	else
		printf("Недопустимое значение \n");

	door = (h * w * t2) / 1000000;
	kr = (w * d * t3) / 1000000;
	st = (h * w * t1) / 1000000;
	bok = (h * d * t3) / 1000000;

	float t4;
	printf("Введите толщину полки \n");
	scanf_s("%f", &t4);

	pol = (w * d * t4) / 1000000;

	Pkl = h / 40;

	M = (st * dvp) + ((bok * 2) * dsp) + ((kr * 2) * dsp) + ((door * 2) * wd) + (floor(Pkl) * pol * dsp);

	printf("Масса шкафа = %.1f", M);

	return 0;
}