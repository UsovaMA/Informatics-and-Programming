#include <stdio.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "russian");

  // init data
  int a, b, c;
  float mean;

  printf("Введите три числа (через пробел): ");
  scanf_s("%d %d %d", &a, &b, &c);   // & - адрес

  // action
  mean = a * b * c / 3.0;

  // result
  printf("Среднее арифметическое: %.2f", mean);

  return 0;
}
