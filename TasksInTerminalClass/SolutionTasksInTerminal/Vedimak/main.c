#include <stdio.h>
#include "locale.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("������ � �������� � ������ ������ �������");
	double CzenaZaZakaz = 0; //���� ������ ����������
	int Monstr1 = 1, Monstr2 = 5, Monstr3 = 10, Monstr4 = 25;//���� �� �������� ������������� ������
	double mostr1 = 0, monstr2 = 0, monstr3 = 0, mostr4 = 0; //��� ����� ��� ������� ���� ����� �������� � ���� ������ �� ����������
	printf("��� ���� ����� ���������� ��������� ������ �������� ����� ������� ����� �������� ��� ����� �����");
	if ((Monstr1 > 0) || (Monstr2 > 0) || (Monstr3 > 0) || (Monstr4 > 0)) // ����������� ������
	   printf("��� ����� ������ ����� ��������,���� ����� �����:...");

	return 0;
}
