#include <iostream>
#include <string>
#include <set>
using namespace std;
set<int> x;//��������� ��� ��������� ����� � ��� �� ����� � ��
string stringRandom(int n) 
{
	string s;
	while (s.size() != n)//�� ��� ��� ����   ������ s �� ����� n
	{
		int digit = rand() % 10;//��������� ����� �� 0-9
		if (x.find(digit) == x.end())// ����� �� ������ � �����
		{
			x.insert(digit);// ������ � ���� � ������ �����
			s += digit + '0';
		}
		else
			continue;
	}
	if (s[0] == '0')// 0 �� ������ ����� ����� ����
		swap(s[0], s[1 + rand() % n - 1]);

	return s;
}
int bull(string s1, string s2)//���� ���-�� �����
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
int cow(string s1, string s2)//���� ���-�� �����
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

	cout << "����. ���� � ������." << endl;
	cout << "��� ������� �������� �����, ���������� �����������. ��� �����������, ��� ����� ���� ���������:" << endl
		<< "1) ���-�� �����, ����������� �� ��, ������� ���� �� �������� (���� ��� ��������� �� ���������� ��������)" << endl
		<< "2) ���-�� �����, ����������� �� ��, ������� ���� �� �������� (�� ������� ��������� �� �� ��� ��������)" << endl <<
		"������ �������? ������� 0" << endl << endl;
	int n;
	cout << "������� n (�� 2-� �� 5-�): ";
	for (;;) 
	{
		do 
		{
			cin >> n;
			if (n < 2 || n > 5)
			{ cout << "����� n ������ ���� �� 2-� �� 5-�! ������� ��� ���!" << endl; 

			}
		} while (n < 2 || n > 5);
		if (n >= 2 && n <= 5) { break;}
	}

	string s1 = stringRandom(n);
	cout << "��������� ������� �����. �����������! " << endl << endl;
	//cout << "��������� ������� �����: " << s1 << endl << endl;
	for (;;) {
		string s2;
		cout << "��������� �����. ��� �������?: ";
		cin >> s2;
		if (s2 == "0") { cout << "�� �������.. ���������� ����� ����: " << s1; break; }

		cout << "�����: " << bull(s1, s2) << " | �����: " << cow(s1, s2) << endl << endl;

		if (bull(s1, s2) == n) { cout << "�������! �� �������� �����."; break; }
	}

	cout << endl;

	return 0;
}