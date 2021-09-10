#include <stdio.h>

int main() {
  // init data
  int a, h;
  float S;

  printf("Input two parameters of triangle (through space): ");
  scanf_s("%d %d", &a, &h);   // & - адрес

  // action
  S = 0.5 * a * h;

  // result
  printf("S = %.2f", S);

  return 0;
}
