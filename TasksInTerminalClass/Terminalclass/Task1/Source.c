#include <math.h>
#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	int Price;
	int co1 = 0, co5 = 0, co10 = 0, co25 = 0;
	printf("введите сцену за услуги ведьмака:\n");
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

	printf("колличество монет\n");
	printf("монеты номиналом 25 :%d\n", co25);
	printf("монеты номиналом 10 :%d\n", co10);
	printf("монеты номиналом 5 :%d\n", co5);
	printf("монеты номиналом 1 :%d\n", co1);
	return 0;
}
