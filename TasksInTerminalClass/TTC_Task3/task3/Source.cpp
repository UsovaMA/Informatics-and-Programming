#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
int main()
{ 
	setlocale(LC_ALL, "RUS");
	int nmbr, iswork = 1;
	while (iswork)
	{
		printf("Введите число \n");
		printf("Для выхода введите 0 \n");
		int iserror = 0;
		do
		{
			if (iserror) printf(" Ошибка "); 
			printf("Введите число : ");
			scanf_s("%d", &nmbr);
			if (nmbr == 0) iswork = 0; break;
			iserror = (nmbr <= 0);
		} while (iserror);
		int inverse = 0;
		while (nmbr)
		{
			inverse *= 10;
			inverse += nmbr % 10;
			nmbr = nmbr / 10;
		}
		if (iswork) printf("Инверсия: %d\n\n", inverse);
		
	}	
	return 0;
}