#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>

#define ARRSIZE 4

void Filling_ProductARR(int * prodname)                             //Заполнение массива штрих-кода
{                                          
	for (int i = 0; i < ARRSIZE; i++)
	{
		prodname[i] = rand() % 9 + 1;
	}
}


void SHTK_Product(int* prodmass_name, int *prod_name)               //Передача значение массива в переменную
{
	for (int i = 0; i < ARRSIZE; i++)
	{
		int b = *prod_name;
		b *= 10;
		*prod_name = b;
		*prod_name += prodmass_name[i];
		
	}
}

void case4_printf( float sale, int count, float produkts)           //Вывод информации о товаре
{
 printf("\n\tДествующая скидка =  %0.1f %%", sale);
 printf("\n\tКоличество товара =  %d шт.", count);
 printf("\n\tСтоимость с учётом скидком = %0.0f руб.", produkts);
}
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));

	int option = 0, skan = 0, shk = 0, count = 0, type, f = 0, fs = 0, fRTX = 0, fRad = 0, fGig = 0, fASUS = 0, RTX = 0, Rad = 0, Gig = 0, ASUS = 0, skanRTX = 0, skanRad = 0, skanGig = 0, skanASUS = 0, countRTX = 0, countRad = 0, countGig = 0, countASUS = 0;
	int* RTX3060 = NULL, * RadRX6600 = NULL, * Gigabyte = NULL, * ASUSROG = NULL, * STRISH = NULL;
	float P_RTX3060, P_RadRX6600, P_Gigabyte, P_ASUSROG, sale1, sale2, sale3, sale4, P_RTX3060s, P_RadRX6600s, P_Gigabytes, P_ASUSROGs, SUMM;
	
	//Выделение памяти 
	RTX3060   = (int*)malloc(ARRSIZE * sizeof(int*));
	RadRX6600 = (int*)malloc(ARRSIZE * sizeof(int*));
	Gigabyte  = (int*)malloc(ARRSIZE * sizeof(int*));
	ASUSROG   = (int*)malloc(ARRSIZE * sizeof(int*));
	STRISH    = (int*)malloc(ARRSIZE * sizeof(int*));
	//Заполнение массива штих-кода 
	Filling_ProductARR(RTX3060);
	Filling_ProductARR(RadRX6600);
	Filling_ProductARR(Gigabyte);
	Filling_ProductARR(ASUSROG);
	//Передача штрих-кода в переменнную
	SHTK_Product(RTX3060, &RTX);
	SHTK_Product(RadRX6600, &Rad);
	SHTK_Product(Gigabyte, &Gig);
	SHTK_Product(ASUSROG, &ASUS);
	//Скидки
	sale1 = rand() % 50;
	sale2 = rand() % 50;
    sale3 = rand() % 50;
	sale4 = rand() % 50;
	//Цена товаров
    P_RTX3060   = 60000;
	P_RadRX6600 = 50000;
	P_Gigabyte  = 20000;
	P_ASUSROG   = 25000;
	//Цена товаров с учетом скидки
	P_RTX3060s = P_RTX3060 * (1 - (sale1 / 100));
	P_RadRX6600s = P_RadRX6600 * (1 - (sale2 / 100));
	P_Gigabytes = P_Gigabyte * (1 - (sale3 / 100));
	P_ASUSROGs = P_ASUSROG * (1 - (sale4 / 100));

	
	

	printf("\nДля того что бы сканировать товар - введите '1'\n");
	printf("Вывести описание отсканированного товара - '2'\n");
	printf("Добавить данные о товаре в чек - '3'\n");
	printf("Сформировать чек за покупку - введите '4'\n");
	printf("Рассчитать итоговую сумму к оплате - введите '5'\n");
	
	printf("\n\nШтрих код RTX3060 - %d\n", RTX);
	printf("Штрих код RadRX6600 - %d\n", Rad);
	printf("Штрих код Gigabyte - %d\n", Gig);
	printf("Штрих код ASUSROG - %d\n", ASUS);
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
					fs = 0;
					printf("\nВведите штрих код:");
					scanf_s("%d", &shk);
					
					if (shk == RTX)
					{
						printf("\nВы отсканировали RTX3060\n");
						f = 1;
					}
					else
					{
						if (shk == Rad)
						{
							printf("\nВы отсканировали RadRX6600\n");
							f = 2;
						}
						else
						{
							if (shk == Gig)
							{
								printf("\nВы отсканировали Gigabyte\n");
								f = 3;
							}
							else
							{
								if (shk == ASUS)
								{
									printf("\nВы отсканировали ASUSROG\n");
									f = 4;
								}
								else
								{
									printf("\n>Товар не найден");
									fs = 1;
								}
							}
						}
					}
									
			    } while (fs == 1);
			     break;
				
			}
			case 2:
			{
				if (f == 1)
				{
					printf("\nВидеокарта RTX3060 - 10G 1шт.\nЦена за шт. = %.1f руб.", P_RTX3060);
					printf("\nДествующая скидка = %0.1f %%\n", sale1);
				}
				else
				{
					if (f == 2)
					{
						printf("\nВидеокарта RadRX6600 - 8G 1шт.\nЦена за шт. = %.1f руб.", P_RadRX6600);
						printf("\nДествующая скидка = %0.1f %%\n", sale2);
					}
					else
					{
						if (f == 3)
						{
							printf("\nМатеринская плата Gigabyte 1шт\nЦена за шт. = %.1f руб.", P_Gigabyte);
							printf("\nДествующая скидка = %0.1f %%\n", sale3);
						}
						else
						{
							if (f == 4)
							{
								printf("\nМатеринская плата  ASUSROG  1шт\nЦена за шт. = %.1f руб.", P_ASUSROG);
								printf("\nДествующая скидка = %0.1f %%\n", sale4);
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
				if (f == 1)
				{				
					printf("Введите количество отсканированного товара, которое нужно добавить в чек:");
					scanf_s("%d", &countRTX);
					printf("\nТовар добавлен в чек");
					fRTX = 1;
				}
				else
				{
					if (f == 2)
					{
						printf("Введите количество отсканированного товара, которое нужно добавить в чек:");
						scanf_s("%d", &countRad);
						printf("\nТовар добавлен в чек");
						fRad = 1;
					}
					else
					{
						if (f == 3)
						{
							printf("Введите количество отсканированного товара, которое нужно добавить в чек:");
							scanf_s("%d", &countGig);
							printf("\nТовар добавлен в чек");
							fGig = 1;
						}
						else
						{
							if (f == 4)
							{
								printf("Введите количество отсканированного товара, которое нужно добавить в чек:");
								scanf_s("%d", &countASUS);
								printf("\nТовар добавлен в чек");
								fASUS = 1;
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
				printf("Чек за покупку на данный момент:");

				if (fRTX == 1)
				{
					P_RTX3060s = P_RTX3060s * countRTX;
					printf("\nRTX3060 10G:");
					case4_printf(sale1, countRTX, P_RTX3060s);
				}
			
		     	if (fRad == 1)
				{
					P_RadRX6600s= P_RadRX6600s * countRad;
					case4_printf(sale2, countRad, P_RadRX6600s);
				}
				
				
				if (fGig == 1)
				{
				    P_Gigabytes = P_Gigabytes * countGig;
				    case4_printf(sale3, countGig, P_Gigabytes);
				}
					
					
				if (fASUS == 1)
				{
					P_ASUSROGs = P_ASUSROGs * countASUS;
					printf("\nASUSROG:");
					case4_printf(sale4, countASUS, P_ASUSROGs);
		     	}

				if(fRTX == 0 && fRad == 0 && fGig == 0 && fASUS == 0)
				{
				    printf("Ваш чек пуст, для начала отсканируйте товар и добавьте его в чек!!!");
				}

				break;
			}
			
			case 5:
			{
				printf("\nЧЕК(итоговый): ");

				if (fRTX == 1)
				{
					printf("\nRTX3060 10G:");
					case4_printf(sale1, countRTX, P_RTX3060s);
				}
				else
				{
					P_RTX3060s = 0;
				}

				if (fRad == 1)
				{
					printf("\nRadRX6600 8G:");
					case4_printf(sale2, countRad, P_RadRX6600s);
				}

				else
				{
					P_RadRX6600s = 0;
				}

				if (fGig == 1)
				{
					printf("\nGigabyte:");
					case4_printf(sale3, countGig, P_Gigabytes);
				}
				else
				{
					P_Gigabytes = 0;
				}

				if (fASUS == 1)
				{
					printf("\nASUSROG:");
					case4_printf(sale4, countASUS, P_ASUSROGs);
				}
				else
				{
					P_ASUSROGs = 0;
				}

				SUMM = P_RTX3060s + P_RadRX6600s + P_Gigabytes + P_ASUSROGs;
				printf("\n\nИтоговая цена: %.1f рублей", SUMM);

				break;
			}
			default:
			{
				printf("Введены некорректные даные!!!(нужно ввести чмсло от 1 до 5)");
			}
			
		  break;
		}
	} while (option != 5);

	_getch();
	return 0;
}