#include <iostream>
#include <vector>
using namespace std;

int main()
{
	system("color 0B");
	setlocale(LC_CTYPE, "rus");
	int Kmest = 0, Kpretendentov = 0, avScore = 0;
	cout << "Введите к-во мест и к-во претендентов на это место" << endl;
	cin >> Kmest >> Kpretendentov;
	vector <int> a(Kpretendentov * 4);
	vector <int> score; // массив баллов за 3 экзамена 
	//считывание
	for (int i = 0, temp = 0; i < (Kpretendentov); i++) //цикл помещает сумму баллов каждго поступившего в отдельный массив
	{
		temp = 0; // зануляем баллы предыдущего человека
		for (int j = 1; ((j % 4) != 0); j++) // цикл считывания потока ввода и сложения баллов
		{
			cin >> a[j];
			temp += a[j];
		}
		score.push_back(temp); //вот в этот
	}
	//обработка
	for (int i = 0, temp = 0; i < score.size(); i++) //по-идее, этот цикл должен сравнивать к-во баллов между собой, но как это сделать - вопрос
	{
		for (int j = 0; j < score.size(); j++) //сравнивает со следующим эд-том
		{
			if (score[i] > score[j])
			{
				cout << i + 1 << " "; //от безысходности
			}
		}
	}
	/*
	cout << "Проходной балл - " << avScore << endl;
	for (int i = 0, temp = 0; i < (Kpretendentov * 4); i++)
	{
		if ((((Kpretendentov * 4) % 4) == 0) && ((a[i+1] + a[i+2] + a[i+3]) >= avScore))
		{
			cout << " Список поступивших:" << a[i] + 1 << " "; // +1 потому что массивы начинаются с 0
		}
	}
	*/
	return 0;
}