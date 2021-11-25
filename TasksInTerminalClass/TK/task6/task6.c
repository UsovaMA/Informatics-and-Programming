#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <math.h>
#include <locale.h>
void simple_n(n, d) {
	if (n > 1)
	{
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				printf("Дисло не простое");
		return 0;
		printf("Дисло простое");
		return TRUE;
	}
}
void simple_nrec(n, d) {
	if (d == 0)
		d = n - 1;
	while (d >= 2) {
		if (n % d == 0) {
			printf("Дисло не простое");
			return FALSE;
		}
		else
			return simple_nrec(n, d - 1);
	}
	return printf("Дисло простое");
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n, pr;
	printf("ђыбери режим(1 rec или 2 base): ");
	scanf_s("%d", &pr);
	while (TRUE) {
		if ((pr == 1) || (pr == 2))
			break;
	}
	printf("ђведите число ");
	scanf_s("%d", &n);
	if (pr == 1)
		simple_nrec(n, 0);
	if (pr == 2)
		simple_n(n, 0);
	return 0;
}