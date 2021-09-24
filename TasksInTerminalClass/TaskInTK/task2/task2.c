#include <stdio.h>
#include <math.h>

int main()
{
	int sum, kol;
	kol = 0;
	printf("Input a witcher coast: ");
	scanf_s("%d", &sum);
	if (sum >= 25)
		do {
			sum -= 25;
			kol += 1;
		} while (sum >= 25);

	if (sum >= 10)
		do {
			sum -= 10;
			kol += 1;
		} while (sum >= 10);

	if (sum >= 5)
		do {
			sum -= 5;
			kol += 1;
		} while (sum >= 5);

	if (sum >= 1)
		do {
			sum -= 1;
			kol += 1;
		} while (sum >= 1);

	printf("%d", kol);

	return 0;
}