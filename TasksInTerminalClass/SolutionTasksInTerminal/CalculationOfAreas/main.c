#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	printf(" ������ � ����� ������������ \n");

	float x1, x2, y1, y2, r1, r2;
	float d;


	printf("������� ��������� 1-� ���������� \n");
	scanf_s("%f %f %f", &x1,&y1,&r1);
	printf("������� ��������� 2-� ���������� \n");
	scanf_s("%f %f %f", &x2, &y2, &r2);


	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));


	return 0;
}