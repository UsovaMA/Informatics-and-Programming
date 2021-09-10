#include <stdio.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "russian");

  // init data
  int a, h;
  float S;

  printf("¬ведите два параметра треуольника (через пробел): ");
  scanf_s("%d %d", &a, &h);   // & - адрес

  // action
  S = 0.5 * a * h;

  // result
  printf("ѕлощадь: S = %.2f", S);

  return 0;
}
