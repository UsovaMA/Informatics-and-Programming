#include <math.h>
#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	int Price;
	int co1 = 0, co5 = 0, co10 = 0, co25 = 0;
	printf("������� ����� �� ������ ��������:\n");
	scanf_s("%d", &Price);
	while (Price >= 25) {
			Price = Price - 25;
			co25 = co25 + 1;
	}
	while (Price >= 10) {
			Price = Price - 10;
			co10 = co10 + 1;
	}
	while (Price >= 5) {
			Price = Price - 5;
			co5 = co5 + 1;
	}
	while (Price >= 1) {
			Price = Price - 1;
			co1 = co1 + 1;
	}

	printf("����������� �����\n");
	printf("������ ��������� 25 :%d\n", co25);
	printf("������ ��������� 10 :%d\n", co10);
	printf("������ ��������� 5 :%d\n", co5);
	printf("������ ��������� 1 :%d\n", co1);
	return 0;
}
