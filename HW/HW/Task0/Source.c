#include <math.h>
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	float x1, x2, y1, y2, r1, r2;
	float d;

	printf("������� ������ � ���������� ������� �����(x,y,r)");
	scanf_s("%f %f %f", &x1, &y1, &r1);

	printf("������� ������ � ���������� ������� �����(x,y,r)");
	scanf_s("%f %f %f", &x2, &y2, &r2);

	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (d == r1 + r2) {
		printf("���������� ��������");
	}
	else if (d < r1 + r2) {
		if (d == 0 && r1 == r2) {
			printf("���������� ���������");
		}
		else if (d + r1 < r2 || d + r2 < r1) {
			printf("���� ���������� ������ ������");
		}
		else if (d == r1 - r2 || d == r2 - r1) {
			printf("��������� �������");
		}
		else {
			printf("���������� ������������");
		}

	}
	else if (d > r1 + r2) {
		printf("���������� ����� �� �������");
	}
	return 0;
}