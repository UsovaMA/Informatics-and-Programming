#include <stdio.h>
#include <locale.h>
int main() 
{
	setlocale(LC_ALL, "russian");
	system("color 0B");
	int price;
	int m1 = 1, m2 = 5, m3 = 10, m4 = 25, k = 0;
	printf("Что по цене сударь");
	scanf_s("%d", &price);
	while (price > 0) //есть ли закза вообще
	{
		while (price >= m4)
		{
			k++;
			price = price - m4;
		}
		while (price >= m3)
		{
			k++;
			price = price - m3;
		}
		while (price >= m2)
		{
			k++;
			price = price - m2;
		}
		while (price >= m1)
		{
			k++;
			price = price - m1;
		}
	}
	printf("%d", k);
	return 0;
}