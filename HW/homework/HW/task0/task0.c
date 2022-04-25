#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "russian");

	printf("¬ведите координаты первой окружности и еЄ радиус:\n");
	int x, y, r;
	scanf_s("%d %d %d", &x, &y, &r);

	printf("¬ведите координаты второй окружности и еЄ радиус:\n");
	int x1, y1, r1;
	scanf_s("%d %d %d", &x1, &y1, &r1);

	int d, diff;
	diff = pow((x1-x), 2) + pow((y1-y), 2);
	d = sqrt(diff);

	if ((r + r1 > d) && (r + d > r1) && (r1 + d > r))
		printf("ќкружности пересекаютс€");
	else
		if ((r + r1 == d) || (abs(r - r1) == d))
			printf("окружности касаютс€");
		else
			printf("окружности не касаютс€");

			return 0;




}