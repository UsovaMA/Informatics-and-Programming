#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#define SIZE 6
#define X 100


int main()
{
	setlocale(LC_ALL, "ru");
	char item[SIZE][X] =
	{ {" Смартфон Apple iPhone 13 128GB Midnight "}, {" Наушники Apple AirPods Pro with Wireless Case "},
	{" Смарт-часы Apple Watch Series 7 GPS 41mm Green Alum./Clover Sport "}, {" Планшет Apple iPad Air 10.9 Wi-Fi 64GB Rose Gold "},
	{" Ноутбук Apple MacBook Air 13 M1/8/256 Gold "}, {" Системный блок Apple Mac Mini M1/8/256 "} };

	int price[SIZE] = { 79999, 18999, 36999, 44149, 89999, 75999 };
	int barcode[SIZE] = { 7131, 8142, 9153, 1164, 1105, 1206 };
	int discount[SIZE] = { 3, 7, 12, 4, 6, 2 };
	int memory[X] = { 0 };

	printf("\n Электронная касса \n");
	printf("\n Типы операций : \
		\n\n1. Cканировать товар \
		\n\n2. Вывести описание отсканированного товара \
		\n\n3. Добавить данные о товаре в чек \
		\n\n4. Сформировать чек за покупку \
		\n\n5. Рассчитать итоговую сумму к оплате \
		\n\n0. Повторный вывод эл.кассы \n");
	int mode, b_code, n = 0, s_code, s = 0;
	do
	{
		printf("\n Выберите тип операции : \n");
		scanf_s("%d", &mode);
		switch (mode)
		{
		case 1:
			printf("Введите штрих-код: ");
			scanf_s("%d", &b_code);
			for (int s = 0; s < SIZE; s++)
			{
				if (b_code == barcode[s])
				{
					printf(" \n Штрих-код отсканирован \n ");
					s_code = b_code;
					break;
				}
				else if (s + 1 == SIZE)
				{
					printf(" Ошибка ");
				}
			}break;
		case 2:
			s = 0;
			printf("Отсканированный товар: \n");
			printf(" Штрихкод | \t\tНазвание \t\t | Стоимость товара | Скидка \n ");
			while (s_code != barcode[s])
			{
				s++;
			}
			printf("# %d\t | %40s | %10dр | %5d%%", barcode[s], item[s], price[s], discount[s]);
			break;
		case 3:
			printf(" Товар добавлен ");
			memory[n] = s_code;
			n++; 
			break;
		case 4:
			printf("\n Добавленные товары : \n");
			float sum = 0;
			for (int s = 0; s < SIZE; s++)
			{
				int z = 0;
				for (int r = 0; r < n; r++)
				{
					if (barcode[s] == memory[r])
					{
						z++;
					}
				}
				if (z > 0)
				{
					float sumpr = (float)price[s] * z;
					float respr = abs(((float)discount[s] / 100 - 1) * sumpr);
					sum += respr;
					printf("%s\t  %d x %dр\n", item[s], z, price[s]);
					printf("Итого (с учетом скидок) : %.2fр\n\n", respr);
				}
			}
			printf("Итоговая стоимость : %.2f", sum);
			break;
		case 5:
			printf("\n Чек: \n\n");
			sum = 0;
			float sumd = 0;
			for (int s = 0; s < SIZE; s++)
			{
				int z = 0;
				for (int r = 0; r < n; r++)
				{
					if (barcode[s] == memory[r])
					{
						z++;
					}
				}
				if (z > 0)
				{
					float sumpr = (float)price[s] * z;
					float respr = abs(((float)discount[s] / 100 - 1) * sumpr);
					sum += sumpr;
					sumd += sumpr - respr;
					printf("%s\n", item[s]);
					printf("Стоимость : %.2fр\n", sumpr);
					printf("Сумма скидки : %.2fр\n", sumpr - respr);
					printf("Итог : %.2fр\n", sumpr - (sumpr - respr));
				}
			}
			printf("\n Всего : %.2fр\n", sum);
			printf("\n Cкидка : %.2fр\n", sumd);
			printf("\n Итого : %.2fр\n", sum - sumd);
		}
	} while (mode != 5);
}