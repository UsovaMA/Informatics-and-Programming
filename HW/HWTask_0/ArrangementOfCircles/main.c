#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{


	float x1, x2, y1, y2, r1, r2;


	printf("Input first circle (x, y, r): ");
	scanf_s("%f %f %f", &x1, &y1, &r1);

	printf("Input second circle (x, y, r): ");
	scanf_s("%f %f %f", &x2, &y2, &r2);


	float d = sqrtf(pow(x2 - x1, 2) + pow(y2 - y1, 2));



	if (d == r1 + r2)
	{
		printf("Kasautsa");
	}
	else
	{
		if (d < r1 + r2)
		{
			if (d == 0 && r1 == r2)
			{
				printf("Sovpadayut ");
			}
			else
			{

				if (d + r1 < r2 || d + r2 < r1)
				{
					printf("Odna v drugoy ");
				}
				else
				{
					printf("Peresekautsa");
				}
			}
		}
		if (d > r1 + r2)
		{
			printf("Ne svazani");
		}
	}
	_getch();
	return 0;

}