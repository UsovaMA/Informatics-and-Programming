// Copyright 2021 Marina Usova

/*

Постановка задачи.

Даны некоторые популярные задачи, представить их простое решение
(если такое есть) и их решение с рекурсией. Если простого решения нет,
вывести информацию об отсутсвии такого.

РЕКУРСИЯ - определение части функции (метода) через саму себя.
Может вызывать чебя непосредственно (в своём теле) или косвенно (через другую функцию).
В первую очередь надо понимать что рекурсия это своего рода перебор (цикл).
Вообще говоря, всё то, что решается итеративно можно решить рекурсивно,
то есть с использованием рекурсивной функции.

ПРАВИЛА РЕКУРСИИ.
1. У рекурсии должно быть правило (условие) остановки (базовый случай).
2. При каждом шаге вызывается рекурсивная функция. И условие из пункта 1. является тем
случаем, к которому рекурсия идет.


Задачки.
1. Дано натуральное число N, написать функцию, выводящую на экран все числа от 1 до N.
2. Написать функцию, вычисляющую функцию Аккермана с параметрами m и n.
A(m, n) = {
  n + 1,                  m = 0
  A(m - 1, 1),            m > 0, n = 0
  A(m - 1, A(m, n - 1)),  m > 0, n > 0
}
Примеры: А(3, 4) = 125, А(3, 2) = 29
3. Дано натуральное число, написать функцию, вычисляющую факториал этого числа.
4. Дано натуральное число, написать функцию, вычисляющую сумму цифр числа.
5. Дано натуральное число, написать функцию, разворавчивающую данное число.
6. Дано натуральное число, написать функцию, проверяющую является ли число простым.
7. Дано слово, определить является ли оно палиндромом.
8. Дан массив, найти максимальный элемент массива (его значение).

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

/* ПРИМЕР: Вывод на экран последовательности */

void showSequenceBaseMethod(int N) {
  for (int i = 1; i <= N; ++i) {
    printf("%d ", i);
  }
}

void showSequenceRecursionMethod(int N) {
  if (N == 0) return;                         // условие выхода
  showSequenceRecursionMethod(N - 1);         // шаг рекурсии
  printf("%d ", N);
}

/* Вычисление функции Аккермана */

// нет очевидного способа реализовать вычисление данной функции,
// можно попробовать реализовать самостоятельно дополнительно
int getAkermanFuncValueBaseMethod(int m, int n) {}

/*
A(m, n) = {
  n + 1,                  m = 0
  A(m - 1, 1),            m > 0, n = 0
  A(m - 1, A(m, n - 1)),  m > 0, n > 0
}
Примеры: А(3, 4) = 125, А(3, 2) = 29
*/
int getAkermanFuncValueRecursionMethod(int m, int n) {
  if (m == 0) return n + 1;
  else if (m > 0 && n == 0) return getAkermanFuncValueRecursionMethod(m - 1, 1);
  else return getAkermanFuncValueRecursionMethod(m - 1, getAkermanFuncValueRecursionMethod(m, n - 1));
}

/* Вычисление факториала числа */

// 7! = 1 * 2 * 3 * 4 * ... * 7

int getFactorialBaseMethod(int N) {
  int fact = 1;
  for (int i = 2; i <= N; ++i) {
    fact *= i;
  }
  return fact;
}

int getFactorialRecursionMethod(int N) {
  if (N == 1) return 1;
  return N * getFactorialRecursionMethod(N - 1);
}

/* Вычисление суммы цифр числа */

int getSumOfNumbersBaseMethod(int num) {
  int sum = 0;
  while (num) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int getSumOfNumbersRecursionMethod(int num) {
  if (num == 0) return 0;
  return num % 10 + getSumOfNumbersRecursionMethod(num / 10);
}

/* Функция, разворачивающая число */

int inverseNumberBaseMethod(int num) {}

int inverseNumberRecursionMethod(int num, int* res) {
  // res - доп. параметр функции, при вызове имеет значение 0
  if (num == 0) return 0;
  (*res) = (*res) * 10 + num % 10;
  return inverseNumberRecursionMethod(num / 10, res);
}


/* Функция, проверяющая число на простоту */

int isPrimeNumberBaseMethod(int num) {}
int isPrimeNumberRecursionMethod(int num) {}

/* Функция, проверяющая является ли слово палиндромом */

int isPalindromBaseMethod(char *word, int start, int end) {

}

int isPalindromRecursionMethod(char *word, int start, int end) { // g h t y 3 4 t 2 5 h 1 6 g 0 7
  if (end == 0) return -1;
  if (end - start <= 1) return 1;
  if (word[start] == word[end - 1]) {
    isPalindromRecursionMethod(word, start + 1, end - 1);
  }
  else {
    return 0;
  }

}

/* Функция, находящая максимальный элемент массива */

float findMaximumBaseMethod(float* mass, int size) {
  float cur_max = -1000000;                          // MAX_FLOAT???
  for (int i = 0; i < size; i++) {
    if (mass[i] > cur_max)
      cur_max = mass[i];
  }
  return cur_max;
}

float findMaximumRecursionMethod(float* mass, int size) {  // 1 3 5 3 7 6 2
  if (size == 0) return -1000000;
  float cur_max = findMaximumRecursionMethod(mass, size - 1);
  return max(cur_max, mass[size - 1]);
  /*
  if (mass[size - 1] > cur_max)
      return mass[size - 1];
  else 
      return cur_max;
  */
}

int main() {
  // блок переменных
  int N = 0, m = 0, n = 0, num = 0;
  char word[20];
  int inv = 0;
  int size = 0;
  float* mass = NULL;
  int choosen = 0, type = 0;
  int temp = 0;
  float temp_f = 0;
  float ans = 0;

  while (1) {
    printf("Choose task number:\n1. Show all numbers from 1 to N;");
    printf("\n2. Calculates the Ackermann function A(m, n); ");
    printf("\n3. Find factorial of the number;\n4. Calculates sum of the digits of the number; \n5. Invers the number; \n6. Check if the number is prime;");
    printf("\n7. Check if the word is palindrom; ");
    printf("\n8. Find the maximum element of the array;");
    printf("\n0. Exit.");
    printf("\n> ");
    scanf_s("%d", &choosen);

    if (choosen == 0) break;

    // инициализация
    switch (choosen) {
    case 1:
      printf("Input N: ");
      scanf_s("%d", &N);
      break;
    case 2:
      printf("Input m and n: ");
      scanf_s("%d %d", &m, &n);
      break;
    case 3: case 4: case 5: case 6:
      printf("Input number: ");
      scanf_s("%d", &num);
      break;
    case 7:
      getchar();
      printf("Input word: ");
      gets(word);
      for (size = 0; word[size] != '\0'; size++);
      break;
    case 8:
      printf("Input size of array: ");
      scanf_s("%d", &size);
      srand(time(0));
      printf("Your random array: ");
      mass = (float*)malloc(size * sizeof(float));
      for (int i = 0; i < size; ++i) {
        mass[i] = rand() % 10;
        printf("%.2f ", mass[i]);
      }
      printf("\n");
      break;
    default:
      printf("Haven't such task!");
    }

    printf("Input type of method: 1. base; 2. recursion.; 3. both\n> ");
    scanf_s("%d", &type);

    if (type == 1)
      printf("Base methods start...\n");
    else if (type == 2)
      printf("Recursion methods start...\n");

    // решение задач
    switch (choosen) {
    case 1:
      printf("Suquence:\n");
      if (type == 1 || type == 3) {
        showSequenceBaseMethod(N);
        printf("\n");
      }
      if (type == 2 || type == 3) {
        showSequenceRecursionMethod(N);
        printf("\n");
      }
      break;
    case 2:
      if (type == 1 || type == 3)
        printf("Task have only recursion method\n");
      if (type == 2 || type == 3)
        printf("A(%d, %d) = %d", m, n, getAkermanFuncValueRecursionMethod(m, n));
      printf("\n");
      break;
    case 3:
      if (type == 1 || type == 3) {
        printf("%d! = %d", num, getFactorialBaseMethod(num));
        printf("\n");
      }
      if (type == 2 || type == 3) {
        printf("%d! = %d", num, getFactorialRecursionMethod(num));
        printf("\n");
      }
      break;
    case 4:
      if (type == 1 || type == 3) {
        printf("Sum = %d", getSumOfNumbersBaseMethod(num));
        printf("\n");
      }
      if (type == 2 || type == 3) {
        printf("Sum = %d", getSumOfNumbersRecursionMethod(num));
        printf("\n");
      }
      break;
    case 5:
      if (type == 1 || type == 3)
        printf("Task have only recursion method\n");
      if (type == 2 || type == 3) {
        inverseNumberRecursionMethod(num, &inv);
        printf("Inverse of number: %d", inv);
      }
      printf("\n");
      break;
    case 6:
      break;
    case 7:
      if (type == 1 || type == 3)
        printf("Task have only recursion method\n");
      if (type == 2 || type == 3) {
        int flag = isPalindromRecursionMethod(word, 0, size);
        if (flag == -1) {
          printf("Empty input!\n");
        } else if (flag) {
          printf("%s - IS palindrom\n", word);
        } else if (!flag) {
          printf("%s - IS NOT palindrom\n", word);
        }
      }
      break;
    case 8:
      // ans = findMaximumBaseMethod(mass, size);
      printf("Max = %.2f\n", findMaximumBaseMethod(mass, size));
      ans = findMaximumRecursionMethod(mass, size);
      printf("Max = %.2f\n", ans);
      break;
    default:
      printf("Haven't such task!");
    }
    printf("\n");
    system("pause");
  }

  return 0;
}
