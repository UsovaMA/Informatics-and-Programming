#include <stdio.h>
#include <math.h>
#include <locale>
int main()
{
	setlocale(LC_ALL, "Russian");
	int price, aboba;
	int summ_of_coins = 0;
	int coins = 0;
	printf("Какова цена за услуги ведьмака?");
	scanf_s("%d", price);
	aboba = price;
	while (summ_of_coins != price)
	{
		if (aboba >= 25)
		{
			summ_of_coins = summ_of_coins + 25;
			coins = coins + 1;
			aboba = aboba - 25;
		}
		else
			if (aboba >= 10)
			{
				summ_of_coins = summ_of_coins + 10;
				coins = coins + 1;
				aboba = aboba - 10;
			}
			else
				if (aboba >= 5)
				{
					summ_of_coins = summ_of_coins + 5;
					coins = coins + 1;
					aboba = aboba - 5;
				}
				else
					if (aboba >= 1)
					{
						summ_of_coins = summ_of_coins + 1;
						coins = coins + 1;
						aboba = aboba - 1;
					}
	}
	printf("С вас минимум %d монет", &coins);
	return 0;
}