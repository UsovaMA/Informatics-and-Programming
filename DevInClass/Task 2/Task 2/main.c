#include <stdio.h>


int main() {
	int cost, counter;
	counter = 0;
	printf("Vvedite cenu za uslugi vedmaka\n");
	scanf_s("%d", &cost);
	while (cost > 0)
	{
		counter = counter + cost / 25;
		cost %= 25;
		counter = counter + cost / 10;
		cost %= 10;
		counter = counter + cost / 5;
		cost %= 5;
		counter = counter + cost / 1;
		cost %= 1;
	}
	printf("%d", counter);

	return 0;
}