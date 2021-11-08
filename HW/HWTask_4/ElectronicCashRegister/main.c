#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include<locale.h>




int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));

	int option, skan = 0, shk, count, type, f = 0, RTX, Rad, Gig, ASUS, RTX3060[] = { 1, 5, 6, 7 }, RadRX6600[] = { 2, 5, 7, 4 }, Gigabyte[] = { 5, 9, 7, 8 }, ASUSROG[] = { 6, 9, 1, 4 };
	float P_RTX3060, P_RadRX6600, P_Gigabyte, P_ASUSROG, sale1, sale2, sale3, sale4, itog;
	
	RTX = (RTX3060[0] * 1000) + (RTX3060[1] * 100) + (RTX3060[2] * 10) + (RTX3060[3] * 1);
	Rad = (RadRX6600[0] * 1000) + (RadRX6600[1] * 100) + (RadRX6600[2] * 10) + (RTX3060[3] * 1);
	Gig = (Gigabyte[0] * 1000) + (Gigabyte[1] * 100) + (Gigabyte[2] * 10) + (Gigabyte[3] * 1);
	ASUS = (ASUSROG[0] * 1000) + (ASUSROG[1] * 100) + (ASUSROG[2] * 10) + (ASUSROG[3] * 1);
	
	sale1 = rand() % 50;
	sale2 = rand() % 50;
    sale3 = rand() % 50;
	sale4 = rand() % 50;



	P_RTX3060 = 60000;
	P_RadRX6600 = 50000;
	P_Gigabyte = 20000;
	P_ASUSROG = 25000;
	

	printf("Для того что бы сканировать товар - введите '1'\n");
	printf("Вывести описание отсканированного товара - '2'\n");
	printf("Добавить данные о товаре в чек - '3'\n");
	printf("Сформировать чек за покупку - введите '4'\n");
	printf("Рассчитать итоговую сумму к оплате - введите '5'\n");
	do 
	{
		printf("\nВведите номер операции: ");
		scanf_s("%d", &option);

		switch (option)
		{
			case 1:
			{   
				do
				{
				printf("Товары есть двух видов 1 - видеокарты 2 - материннские платы:\n");
				printf("Введите тип продукта: ");
				scanf_s("%d", &type);
				if (type == 1 || type == 2)
				{
					if (type == 1) 
					{
						printf("Введите штрих-код продукта: ");
						scanf_s("%d", &shk);
						if (shk == RTX)
						{
							skan = skan + shk;
							printf("RTX3060\n ");
						}
						else
						{
							skan = skan + 2574;
							printf("RadRX6600\n");
						}
					}
					else
					{
						printf("Введите штрих-код продукта: ");
						scanf_s("%d", &shk);
						if(shk == Gig)
						{
							skan = skan + shk;
							printf("Gigabyte\n");
						}
						else
						{
							skan = skan + 6914;
							printf("ASUSROG\n");
						}
					}
				}
				else
				{
					printf("Введены некорректные данные!(нужно ввести 1 или 2");
					f = 1;
				}
			} while (f == 1);
			break;
				
			}
			case 2:
			{
				if (skan == 1567)
				{
					printf("\nВидеокарта RTX3060 10G 1шт.                  %.1f руб.", P_RTX3060);
					printf("\nДествующая скидка           %0.1f %%", sale1);
				}
				else
				{
					if (skan == 2574)
					{
						printf("\nВидеокарта RadRX6600 8G 1шт.                    %.1f руб.", P_RadRX6600);
						printf("\nДествующая скидка           %0.1f %%", sale2);
					}
					else
					{
						if (skan == 5978)
						{
							printf("\nМатеринская плата Gigabyte 1шт.                %.1f руб.", P_Gigabyte);
							printf("\nДествующая скидка           %0.1f %%", sale3);
						}
						else
						{
							if (skan == 6914)
							{
								printf("\nМатеринская плата  ASUSROG  1шт.                %.1f руб.", P_ASUSROG);
								printf("\nДествующая скидка           %0.1f %%", sale4);
							}
							else
							{
								printf("Чтобы посмотреть информацию о товаре сначало нужно его отсканировать!");
							}
						}
					}
				}

				break;
			}
			case 3:
			{
				if (skan == 1567)
				{
					printf("Введите количество отсканированного товара, которое нужно добавить в чек:");
					scanf_s("%d", &count);
					f = 1;
					printf("\nТовар добавлен в чек");
				}
				else
				{
					if (skan == 2574)
					{
						printf("Введите количество отсканированного товара, которое нужно добавить в чек:");
						scanf_s("%d", &count);
						f = 2;
						printf("\nТовар добавлен в чек");
					}
					else
					{
						if (skan == 5978)
						{
							printf("Введите количество отсканированного товара, которое нужно добавить в чек:");
							scanf_s("%d", &count);
							f = 3;
							printf("\nТовар добавлен в чек");
						}
						else
						{
							if (skan == 6914)
							{
								printf("Введите количество отсканированного товара, которое нужно добавить в чек:");
								scanf_s("%d", &count);
								f = 4;
								printf("\nТовар добавлен в чек");
							}
							else
							{
								printf("Для начала отсканируйте товар");
							}
						}
					}
				}

				break;
			}
			case 4:
			{
				if (f == 1)
				{
					P_RTX3060 = P_RTX3060 * count;
					printf("\nRTX3060 10G:");
					printf("\n\tДествующая скидка                         %0.1f %%", sale1);
					printf("\n\tКоличество                                %d шт.", count);
					printf("\n\tСтоимость с учётом скидком                %0.1f руб.", P_RTX3060);
				}
				else
				{
					if (f == 2)
					{
						P_RadRX6600 = P_RadRX6600 * count;
						printf("\nRadRX6600 8G:");
						printf("\n\tДествующая скидка                         %0.1f %%", sale2);
						printf("\n\tКоличество                                %d шт.", count);
						printf("\n\tСтоимость с учётом скидком                %0.1f руб.", P_RadRX6600);
					}
					else
					{
						if (f == 3)
						{
							P_Gigabyte = P_Gigabyte * count;
							printf("\nGigabyte:");
							printf("\n\tДествующая скидка                         %0.1f %%", sale3);
							printf("\n\tКоличество                                %d шт.", count);
							printf("\n\tСтоимость с учётом скидком                %0.1f руб.", P_Gigabyte);
						}
						else
						{
							if (f == 4)
							{
								P_ASUSROG = P_ASUSROG * count;
								printf("\nASUSROG:");
								printf("\n\tДествующая скидка                         %0.1f %%", sale4);
								printf("\n\tКоличество                                %d шт.", count);
								printf("\n\tСтоимость с учётом скидком                %0.1f руб.", P_ASUSROG);
							}
							else
							{
								printf("Для начала отсканируйте товар!");
							}
						}
					}
				}
			}
			case 5:
			{
				printf("\n\t\tЧЕК(итоговый)");

				if (f == 1)
				{
					printf("\nRTX3060 10G:");
					printf("\n\tДествующая скидка                         %0.1f %%", sale1);
					printf("\n\tКоличество                                %d шт.", count);
					printf("\n\tСтоимость с учётом скидком                %0.1f руб.", P_RTX3060);
				}
				else
				{
					P_RTX3060 = 0;
				}

				if (f == 2)
				{
					printf("\nRadRX6600 8G:");
					printf("\n\tДествующая скидка                         %0.1f %%", sale2);
					printf("\n\tКоличество                                %d шт.", count);
					printf("\n\tСтоимость с учётом скидком                %0.1f руб.", P_RadRX6600);
				}
				else
				{
					P_RadRX6600 = 0;
				}

				if (f == 3)
				{
					printf("\nGigabyte:");
					printf("\n\tДествующая скидка                         %0.1f %%", sale3);
					printf("\n\tКоличество                                %d шт.", count);
					printf("\n\tСтоимость с учётом скидком                %0.1f руб.", P_Gigabyte);
				}
				else
				{
					P_Gigabyte = 0;
				}

				if (f == 4)
				{
					printf("\nASUSROG:");
					printf("\n\tДествующая скидка                         %0.1f %%", sale4);
					printf("\n\tКоличество                                %d шт.", count);
					printf("\n\tСтоимость с учётом скидком                %0.1f руб.", P_ASUSROG);
				}
				else
				{
					P_ASUSROG = 0;
				}

				itog = P_RTX3060 + P_RadRX6600 + P_Gigabyte + P_ASUSROG;
				printf("\n\n\nИтого: %.1f рублей", itog);

				break;
			}
			


			default:
			{
				printf("Нужно ввести число от 1 до 5!");
			}
				break;
		}
	} while (option != 5);

	_getch();
	return 0;
}