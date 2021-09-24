#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");

	int coin; // Цена услуги
	int k1 = 0,k5 = 0,k10 = 0,k25 = 0;// Кол-во монет
	printf("Цена услуги: ");
	scanf_s("%d", &coin);
	while (coin > 0)
	{
		if (coin - 25 >= 0)
		{
			coin -= 25;
			k25++;
		}
		else if (coin - 10 >= 0)
		{
			coin -= 10;
			k10++;
		}
		else if (coin - 5 >= 0)
		{
			coin -= 5;
			k5++;
		}
		else
		{
			coin -= 1;
			k1++;
		}
	}
	printf("25 - %dшт.\n10 - %dшт.\n5 - %dшт.\n1 - %dшт.\n", k25,k10,k5,k1);
}