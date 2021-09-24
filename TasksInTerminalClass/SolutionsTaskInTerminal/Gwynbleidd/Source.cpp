#include <stdio.h>
#include <locale>
int main()
{
	int coins = 0;
	int price_of_coins = 0;
	int price, aboba;
	setlocale(LC_ALL, "Russian");
	printf("Какова цена за услуги ведьмака?\n");
	scanf_s("%d", &price);
	aboba = price;
	while (price_of_coins != price)
	{
		if (aboba >= 25)
		{
			coins = coins + 1;
			price_of_coins = price_of_coins + 25;
			aboba = aboba - 25;
		}
		else
			if (aboba >= 10)
			{
				coins = coins + 1;
				price_of_coins = price_of_coins + 10;
				aboba = aboba - 10;
			}
			else
				if (aboba >= 5)
				{
					coins = coins + 1;
					price_of_coins = price_of_coins + 5;
					aboba = aboba - 5;
				}
				else
					if (aboba >= 1)
					{
						coins = coins + 1;
						price_of_coins = price_of_coins + 1;
						aboba = aboba - 1;
					}
	}
	printf("С вас минимум %d монет(ы), холоп.\n", coins);
	return 0;
}