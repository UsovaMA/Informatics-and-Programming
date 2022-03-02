#include <stdio.h>
#include "locale.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("задача о ведьмаке и кривом кодере монстре");
	double CzenaZaZakaz = 0; //ввод кривых переменных
	int Monstr1 = 1, Monstr2 = 5, Monstr3 = 10, Monstr4 = 25;//цена за убийство определенного чудища
	double mostr1 = 0, monstr2 = 0, monstr3 = 0, mostr4 = 0; //нам нужно без остатка ведь монет чеканных в виде копеек не существует
	printf("Для того чтобы определить стоимость заказа ведьмака нужно указать каких монстров ему нужно убить");
	if ((Monstr1 > 0) || (Monstr2 > 0) || (Monstr3 > 0) || (Monstr4 > 0)) // возможность заказа
	   printf("при таком исходе заказ возможен,цена будет такая:...");

	return 0;
}
