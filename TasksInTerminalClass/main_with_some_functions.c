// Copyright 2021 Marina Usova

/*
ѕостановка задачи.

–еализована некотора€ программа, работающа€ с матричными операци€ми.

ѕрограммист начал работать над ней и пон€л, что в ней много дублировани€ кода. 
ќн посмотрел свой код и не увидел проблем в самом коде. „тобы исправить
проблему дублировани€ он решил вынести часть кода в функции. 
ѕомогите ему в этом, а также допишите функционал, который он не успел.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2

/// <summary>
/// генераци€ рандомного числа из указанного диапозона
/// </summary>
/// <param name="maximum">максимальное допустимое значение рандома</param>
/// <param name="minimun">минимальное допустимое значение рандома</param>
/// <returns>сгенерированное случайное значение</returns>
int generateRandNumber(int max, int min) {
  int value = (max - min)* ((float)rand() / RAND_MAX) + min;
  return value;
}

/// <summary>
/// выделение указаного размера пам€ти
/// </summary>
/// <param name="matrix">матрица</param>
/// <param name="n">количество строк</param>
/// <param name="m">количество столбцов</param>
int** setMemory(int** matrix, int n, int m) {
  matrix = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++)
    matrix[i] = (int*)malloc(m * sizeof(int));
  return matrix;
}

/// <summary>
/// вывод матрицы на экран
/// </summary>
/// <param name="matrix">матрица</param>
/// <param name="n">количество строк</param>
/// <param name="m">количество столбцов</param>
void printMatrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

/// <summary>
/// работает неправильно, пример с передачей по адресу обычноый переменной
/// чтобы она помен€ла и сохранила своЄ значение вне этой функции
/// </summary>
/// <param name="matrix"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <param name="value"></param>
/// <returns></returns>
int** multMatrixOnNumber(int** matrix, int n, int m, int* value) {
  int** res = NULL;                       // nullptr
  res = setMemory(res, N, M);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res[i][j] = matrix[i][j] * (*value);
    }
  }
  (*value) = 3;
  return res;
}

void fillArrayRandValues(int** matrix, int n, int m, int max, int min) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = generateRandNumber(max, min);
    }
  }
}

void freeMemory(int** matrix, int n, int m) {
  for (int i = 0; i < n; i++) free(matrix[i]);
  free(matrix);
}

int** createMatrix(int** matrix, int n, int m, int max, int min, char name) {
  matrix = setMemory(matrix, n, m);
  fillArrayRandValues(matrix, n, m, max, min);
  printf("Matrix %c =\n", name);
  printMatrix(matrix, n, m);
  return matrix;
}

void inputData(int* n, int* m, int* max, int* min) {
  // только printf scanf_s
}

int main() {
  int **matrix_A = NULL, **matrix_B = NULL, **result = NULL;
  int max = 4, min = 0, value = 0;

  // srand(time(0));

  //inputData(&n, &m, &max, &min);

  matrix_A = createMatrix(matrix_A, N, M, max, min, 'A');
  matrix_B = createMatrix(matrix_B, M, K, max, min, 'B');
  value = generateRandNumber(max, min);

  // умножение матрицы на число
  result = setMemory(result, N, M);
  result = multMatrixOnNumber(matrix_A, N, M, &value);
  printf("Matrix A x %d =\n", value);
  printMatrix(result, N, M);
  // was error
  freeMemory(result, N, M);

  // транспонирование матрицы
  result = setMemory(result, M, N);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      result[i][j] = matrix_A[j][i];
    }
  }
  printf("Matrix AT =\n");
  printMatrix(result, M, N);
  // очищение результата после вывода
  freeMemory(result, M, N);

  // умножение двух матриц
  result = setMemory(result, N, K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      result[i][j] = 0;
      for (int k = 0; k < M; k++) {
        result[i][j] += matrix_A[i][k] * matrix_B[k][j];
      }
    }
  }
  printf("Matrix AxB =\n");
  printMatrix(result, N, K);
  // очищение результата после вывода
  freeMemory(result, N, K);

  // сложение двух матриц
  // ???

  // умножение вектора на число
  // ???

  // сложение двух векторов
  // ???

  // умножение двух векторов
  // ???

  // очищение всей выделенной пам€ти
  freeMemory(matrix_A, N, M);
  freeMemory(matrix_B, M, K);

  return 0;
}
