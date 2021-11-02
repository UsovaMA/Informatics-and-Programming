// Copyright 2021 Marina Usova

/*
Ïîñòàíîâêà çàäà÷è.

Íàïèñàòü ïðîãðàììó äëÿ ñðàâíåíèÿ äâóõ ñîðòèðîâîê.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int generateRandNumber(int max, int min) {
  int value = (max - min) * ((float)rand() / RAND_MAX) + min;
  return value;
}

void swap(int* mass, int indx1, int indx2) {
  int temp = mass[indx1];
  mass[indx1] = mass[indx2];
  mass[indx2] = temp;
}

void printArray(int* mass, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", mass[i]);
  }
}

void bubbleSort(int* mass, int n, int* countOfComp, int* countOfSwap) {
  int temp;
  (*countOfComp) = 0;
  (*countOfSwap) = 0;
  // ñîðòèðîâêà ïî âîçðàñòàíèþ ñ çàïîìèíàíèåì èíäåêñîâ
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      // åñëè âñòðåòèëèñü çíà÷åíèÿ â íåïðàâèëüíîì ïîðÿäêå - ìåíÿåì èõ ìåñòàìè
      // ìåíÿåì ìåñòàìè è èõ èíäåêñû, ÷òîáû ïîëó÷èòü ïîðÿäîê ýëåìåíòîâ
      if (mass[i] < mass[i + 1]) {
        swap(mass, i, i + 1);
        (*countOfSwap) += 1;
      }
      (*countOfComp) += 1;
    }
  }
}

void bubbleSortWithFlag(int* mass, int n, int* countOfComp, int* countOfSwap) {
  int temp;
  (*countOfComp) = 0;
  (*countOfSwap) = 0;
  // ñîðòèðîâêà ïî âîçðàñòàíèþ ñ çàïîìèíàíèåì èíäåêñîâ
  for (int j = 0; j < n; j++) {
    int all_right = 1;
    for (int i = 0; i < n; i++) {
      // åñëè âñòðåòèëèñü çíà÷åíèÿ â íåïðàâèëüíîì ïîðÿäêå - ìåíÿåì èõ ìåñòàìè
      // ìåíÿåì ìåñòàìè è èõ èíäåêñû, ÷òîáû ïîëó÷èòü ïîðÿäîê ýëåìåíòîâ
      if (mass[i] < mass[i + 1]) {
        swap(mass, i, i + 1);
        all_right = 0;
        (*countOfSwap) += 1;
      }
      (*countOfComp) += 1;
    }
    // åñëè íè îäíîé ïåðåñòàíîâêè íà èòåðàöèè íå ñäåëàëè - çàâåðøàåì
    if (all_right) break;
  }
}

void countingSort(int* mass, int n, int min, int max, int* countOfComp, int* countOfSwap) {
  int* count = NULL;
  int size = max - min + 1;                          // -5 5 - 0 10 = 11 el
  
  count = (int*)malloc(size * sizeof(int));

  (*countOfComp) = 0;
  (*countOfSwap) = 0;

  for (int i = 0; i < size; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    count[mass[i] - min] += 1;
  }
  int ind = 0;
  //for (int i = size - 1; i >= 0; i--) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < count[size - i - 1]; j++) {
      mass[ind] = size - i - 1;
      ind += 1;
      (*countOfSwap) += 1;
    }
    (*countOfComp) += 1;
  }
}


int main() {
  int* mass = NULL, * copy_1 = NULL, * copy_2 = NULL, * copy_3 = NULL;
  int n = 0, min = 0, max = 0;
  int countOfComp = 0, countOfSwap = 0;

  printf("Input array size: \n> ");
  scanf_s("%d", &n);

  printf("Input min and max value of random (between space): \n> ");
  scanf_s("%d %d", &min, &max);

  mass = (int*)malloc(n * sizeof(int));
  copy_1 = (int*)malloc(n * sizeof(int));
  copy_2 = (int*)malloc(n * sizeof(int));
  copy_3 = (int*)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    mass[i] = generateRandNumber(max, min);
    copy_1[i] = mass[i]; copy_2[i] = mass[i]; copy_3[i] = mass[i];
  }

  if (n < 21) {
    printf("Source array: ");
    printArray(mass, n);
  }

  /* Sort with bubble sorting */

  printf("\nStart sort with bubble sort...\n");

  int time = clock();
  bubbleSort(copy_1, n, &countOfComp, &countOfSwap);
  time = clock() - time;

  if (n < 21) {
    printf("Sort array: ");
    printArray(copy_1, n);
  }
  printf("\nTime of work: %d ms\nCount of comparisons: %d\nCount of swap: %d\n", time, countOfComp, countOfSwap);

  /* Sort with bubble sorting whith flag for stop */

  printf("\nStart sort with bubble sort with stop condition...\n");

  time = clock();
  //switch (sort) {
  bubbleSortWithFlag(copy_2, n, &countOfComp, &countOfSwap);
  //}
  time = clock() - time;

  if (n < 21) {
    printf("Sort array: ");
    printArray(copy_2, n);
  }
  printf("\nTime of work: %d ms\nCount of comparisons: %d\nCount of swap: %d\n", time, countOfComp, countOfSwap);

  /* Countion sort */

  printf("\nStart sort with bubble sort with stop condition...\n");

  time = clock();
  countingSort(copy_3, n, min, max, &countOfComp, &countOfSwap);
  time = clock() - time;

  if (n < 21) {
    printf("Sort array: ");
    printArray(copy_3, n);
  }
  printf("\nTime of work: %d ms\nCount of comparisons: %d\nCount of swap: %d\n", time, countOfComp, countOfSwap);

  return 0;
}
