#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	int price, coins = 0;

	printf ("Цена за услугу ведьмака: ");
	scanf_s("%d", &price);

	while(price >= 25)
	{
		price = price - 25;
		coins ++;
	}
	while(price >= 10)
	{
		price = price - 10;
		coins++;
	}
	while(price >= 5)
	{
		price = price - 5;
		coins++;
	}
	while (price >= 1 )
	{
		price = price - 1;
		coins++;
	}


	printf ("Количество монет %d", coins);

	return 0;
}