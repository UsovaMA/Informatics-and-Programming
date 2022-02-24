#include <iostream>
#include <string>
#include <set>
using namespace std;
set<int> x;//контейнер для генерации одних и тех же чисел в пк
string stringRandom(int n) 
{
	string s;
	while (s.size() != n)//до тех пор пока   длинна s не равна n
	{
		int digit = rand() % 10;//генерация числа от 0-9
		if (x.find(digit) == x.end())// цифры не повтор в числе
		{
			x.insert(digit);// добавл в конт х сгенер число
			s += digit + '0';
		}
		else
			continue;
	}
	if (s[0] == '0')// 0 не первая цифра должа быть
		swap(s[0], s[1 + rand() % n - 1]);

	return s;
}
int bull(string s1, string s2)//счёт кол-во быков
{
	int k = 0;
	for (int i = 0; i < s1.size(); i++) 
	{
		if (s1[i] == s2[i])
		{
			k++;
		}
	}
	return k;
}
int cow(string s1, string s2)//счет кол-во коров
{
	int k = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if ((s1[i] != s2[i]) && (s2.find(s1[i]) != string::npos)) 
		{
			k++;
		}
	}
	return k;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));

	cout << "Игра. Быки и коровы." << endl;
	cout << "Вам следует отгадать число, загаданное компьютером. При отгадывании, вам будут даны подсказки:" << endl
		<< "1) Кол-во быков, указывающее на то, сколько цифр вы отгадали (если они находятся на правильных позициях)" << endl
		<< "2) Кол-во коров, указывающее на то, сколько цифр вы отгадали (но которые находятся не на тех позициях)" << endl <<
		"Хотите сдаться? Введите 0" << endl << endl;
	int n;
	cout << "Введите n (от 2-х до 5-и): ";
	for (;;) 
	{
		do 
		{
			cin >> n;
			if (n < 2 || n > 5)
			{ cout << "Число n должно быть от 2-х до 5-и! Введите ещё раз!" << endl; 

			}
		} while (n < 2 || n > 5);
		if (n >= 2 && n <= 5) { break;}
	}

	string s1 = stringRandom(n);
	cout << "Компьютер загадал число. Отгадывайте! " << endl << endl;
	//cout << "Компьютер загадал число: " << s1 << endl << endl;
	for (;;) {
		string s2;
		cout << "Отгадайте число. Ваш вариант?: ";
		cin >> s2;
		if (s2 == "0") { cout << "Вы сдались.. Загаданное число было: " << s1; break; }

		cout << "Быков: " << bull(s1, s2) << " | Коров: " << cow(s1, s2) << endl << endl;

		if (bull(s1, s2) == n) { cout << "Молодец! Вы отгадали слово."; break; }
	}

	cout << endl;

	return 0;
}