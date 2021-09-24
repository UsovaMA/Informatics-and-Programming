#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	printf("Task0 with circles");
	//init
	float x1, x2, y1, y2, r1, r2;					// x1, x2, и y1, y2 - координаты; r1 и r2 - радиусы
	float d;										// d - расстояние между центрами окружности

	printf("Input 1st circle (i form x y r):");
	scanf_s("%f %f %f", &x1, &y1, &r1);

	printf("Input 2st circle (i form x y r):");
	scanf_s("%f %f %f", &x2, &y2, &r2);

	//action

	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));	// формула для расстроянимя между центрами окружности

	//output

	if (d == r1 + r2) {
		printf("Kasautsa snaruji");
	}
	else
		if (d < r1 + r2) {
			if ((r1 == r2) && (x1 == x2) && (y1 == y2)) {	//&& = AND
				printf("Sovpadaet");
			}
			else if (d + r1 < r2 || d + r2 < r1) {			// || = OR
					printf("Odna vnuutri drugoy");
			} else if (d + r1 == r2 || d + r2 == r1) {
				    printf("Kasautsa odna vnutri drugoy");
			} else {
				printf("Peresekautsa");
			}
		}
		else {
				printf("Ne kasautsa");
	    } 

	return 0;
}
