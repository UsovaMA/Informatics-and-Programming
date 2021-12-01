#include<math.h>
#include<stdio.h>
#include<locale.h>


int main()
{
			setlocale(LC_ALL, "RU");
			int c1 = 1, c5 = 5, c10 = 10, c25 = 25, x, cnt1 = 0, cnt5 = 0, cnt10 = 0, cnt25 = 0;
			printf("Введите число : ");
			scanf_s("%d", &x);
	
				while (x >= c25)
				{
					cnt25++;
					x = x - c25;
				}
				while (x >= c10)
				{
					cnt10++;
					x = x - c10;
				}
				while (x >= c5)
				{
					cnt5++;
					x = x - c5;
				}
				while (x >= c1)
				{
					cnt1++;
					x = x - c1;
				}
				printf(" Колличество монет номиналом 25 : %d\n", cnt25);
				printf(" Колличество монет номиналом 10 : %d\n", cnt10);
				printf(" Колличество монет номиналом 5 : %d\n", cnt5);
				printf(" Колличество монет номиналом 1 : %d\n", cnt1);
				return 0;
}   
