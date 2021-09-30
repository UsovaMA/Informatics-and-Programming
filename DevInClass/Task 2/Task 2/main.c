#include <stdio.h>


int main() {
	int cost, counter, dp, d, p, o;
	counter = 0;
	dp = 0; d = 0; p = 0; o = 0;
	printf("Vvedite cenu za uslugi vedmaka\n");
	scanf_s("%d", &cost);
	while (cost > 0)
	{
		counter = counter + cost / 25;
		dp = cost / 25;
		cost %= 25;
		counter = counter + cost / 10;
		d = cost / 10;
		cost %= 10;
		counter = counter + cost / 5;
		p = cost / 5;
		cost %= 5;
		counter = counter + cost / 1;
		o = cost / 1;
		cost %= 1;

	}
	printf("Colishestvo monet = %d\n Colichestvo 25 = %d\n Colichestvo 10 = %d\n Colichestvo 5 = %d\n Colichestvo 1 = %d\n", counter, dp, d, p, o);

	return 0;
}