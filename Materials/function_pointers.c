#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#include <float.h>  // для FLT_MAX

/*
  Реализовать основные векторные нормы
*/

#define NORMS_COUNT 3

typedef float Norma(float*, int);
typedef float (*Pointer)(float*, int);

// Манхэттенская норма
float L1(float* x, int n) {
  float sum = 0;
  for (int i = 0; i < n; i++) {
    sum += fabs(x[i]);
  }
  return sum;
}

// Евклидова норма
float L2(float* x, int n) {
  float sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pow(x[i], 2);
  }
  return sqrt(sum);
}

// Норма Чебышёва
float Loo(float* x, int n) {
  float max = x[0];
  for (int i = 1; i < n; i++) {
    if (max < fabs(x[i])) max = fabs(x[i]);
  }
  return max;
}

void CalculateNorm(Norma L, float* x, int n) {
  printf("Norma: %.2f\n", L(x, n));
}

void AllNormsCalculate(Pointer* L, char** name, float* x, int n) {
  printf("All norms for vector x:\n");
  for (int i = 0; i < NORMS_COUNT; i++) {
    float norm = (*L[i])(x, n);
    printf("%s = %.2f\n", name[i], norm);
  }
}

int main() {
  int size = 6;
  float value;
  float* vector = (float*)malloc(sizeof(float) * size);
  srand(time(0));

  // массив указателей на функцию
  Pointer norms[NORMS_COUNT] = { &L1, &L2, &Loo };
  char* names[NORMS_COUNT] = { "L1", "L2", "Loo" };

  printf("x = ( ");
  for (int i = 0; i < size; i++) {
    value = rand() % 100 + 0.01f * (rand() % 100);
    vector[i] = value;
    printf("%.2f ", value);
  }
  printf(")\n");

  CalculateNorm(Loo, vector, size);
  AllNormsCalculate(norms, names, vector, size);

  system("pause");
  return 0;
}
