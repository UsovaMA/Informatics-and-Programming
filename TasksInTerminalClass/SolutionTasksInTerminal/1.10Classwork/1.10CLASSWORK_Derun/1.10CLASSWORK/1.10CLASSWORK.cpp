#include <iostream>
#include <math.h>
#include <locale.h>
#include "windows.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	system("color 0B");
	int number = 0, Mfirstinput = 0, remof;
	cout << "Ввведи цифры я те их щас обраткой выведу" << endl; //ну как бы вот мой сяут 
	cin >> number;
	if (number <= 0)
	{
		cout << "ну ты чо фраер 0 и меньше нуля вводить берега попутал?";
		return 0;
	}
	while (number > 0)
	{
		system("CLS");
		remof = number % 10;
		Mfirstinput = Mfirstinput * 10 + remof;
		number /= 10;
	}

	system("CLS");
	cout << "ну вот как бы обратный вывод че ты хотел?" << endl;
	cout << Mfirstinput;
	getchar();
	getchar();
	return 0;
}
