#include <stdio.h>
#include <math.h>


int main() //Start programm 
{

	/*Enter x1, y1 of the first circle, as well as its R*/

	printf("Enter the I coordinates of the circle: \n");
	int x1, y1;
	scanf_s("%d %d", &x1, &y1);

	printf("Enter the radius I of the circle: \n");

	int r1;
	scanf_s("%d", &r1);

	/* Introduce x2, y2 of the second circle, as well as its R */

	printf("Enter the II coordinates of the circle: \n");
	int x2, y2;
	scanf_s("%d %d", &x2, &y2);

	printf("Enter the radius I of the circle: \n");

	int r2;
	scanf_s("%d", &r2);

	/* Find the distance between the centers of the circles d */

	int d, diff1, diff2, diff3;

	diff1 = x2 - x1;
	diff2 = y2 - y1;
	diff3 = pow(diff1, 2) + pow(diff2, 2);

	d = sqrt(diff3);

	/* Consider all cases, and find out the relative position of the circles */

	if ((r1 + r2 > d) && (r1 + d > r2) && (r2 + d > r1))
		printf("Circles intersect");
	else
		if ((r1 + r2 == d) || (abs(r1 - r2) == d))
			printf("Circles touch");
		else
			printf("Circles dont intersect");

	return 0;
}