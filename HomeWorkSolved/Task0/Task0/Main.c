#include <stdio.h>
#include <math.h>

int main() {
	float x1, y1, r1, x2, y2, r2, l;
	printf("Insert coordinates and radius of the first circle x1, y1, r1:");
	scanf_s("%f, %f, %f", &x1, &y1, &r1);
	printf("Insert coordinates and radius of the second circle x2, y2, r2:");
	scanf_s("%f, %f, %f", &x2, &y2, &r2);
	l = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (l == 0 && r1 == r2)
		printf("Circles merge");
	else
		if (l == 0 && r1 != r2)
			printf("One circle in another");
		else
			if (r1 + r2 == l)
				printf("The circles are touching");
			if (r1 + r2 < l)
				printf("The circles are don't intersect");
			if (r1 + r2 > l)
				printf("The circles are intersect");
}
//can't figure out, how to one circle in another