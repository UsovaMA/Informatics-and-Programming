// Copyright 2021 Marina Usova

/*
* Вариант 1 (1 балл)
* Заполнить массив размера N случайными значениями в диапозоне от -A до A и
* выполнить циклический сдвиг вправо на K элементов и развернуть.
* Замечание. Измениться должен именно исходный массив.
*
* Вариант 2 (3 балла)
* Каждый год в ННГУ приходит множество абитуриентов. У каждого абитуриента есть
* свой уникальный номер и информация о его баллах (результаты трёх экзаменов).
* Если план приёма на направление Программная инженерия в этом году равен К,
* определить проходной балл, а также поступивших на данное направление студентов.

* Вариант 3 (5 баллов)
* Население некоторого маленького города N человек. Каждый человек написал
* информацию о том, с каким количеством людей он знаком. После сбора информации
* она должна быть проанализирована и должны быть выданы ответы:
*   - правдива ли информация,
*   - предложить вариант того, кто с кем знаком.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main() {
  int task = 0, size = 0, temp_1 = 0, temp_2 = 0;
  int* values = NULL;

  // var 1
  int board = 0, shift = 0;
  int prev = 0, cur = 0;
  // var 2
  int exam_scores_1 = 0, exam_scores_2 = 0, exam_scores_3 = 0, admission_plan = 0, passing_score = 0;
  int* IDs = NULL;
  // var 3
  int** acuaintance = NULL;
  int mistake_in_data = 0, not_all = 1;

  srand(time(0));

  while (1) {
    // INPUT BLOCK

    // выбор варианта задания контрольной работы
    printf("Choose number of variant:\n  1. easy (1 point),\n  2. middle (3 points),\n  3. hard (5 points)\n  0. exit\n> ");
    scanf_s("%d", &task);

    if (task == 0) break;

    // ввод данных для определённого задания с заполнением массивов данными
    switch (task) {
    case 1:
      printf("Input size\n> ");
      scanf_s("%d", &size);
      printf("Input board of values\n> ");
      scanf_s("%d", &board);
      printf("Input shift\n> ");
      scanf_s("%d", &shift);

      // способ 1 заполнения массива - заполнение рандомными числами из заданного диапозона
      values = (int*)malloc(size * sizeof(int));
      for (int i = 0; i < size; i++)
        // от -board до board
        values[i] = rand() % (board * 2 + 1) - board;

      printf("Generate massive: ");
      for (int i = 0; i < size; i++)
        printf("%d ", values[i]);
      printf("\n");
      break;
    case 2:
      printf("Input number of abiturience\n");
      printf("> ");
      scanf_s("%d", &size);
      printf("Input admission plan\n");
      printf("> ");
      scanf_s("%d", &admission_plan);

      // способ 2 заполнения массива (values) - заполнение массива вычисленными по какому-то правилу значениями
      // способ 3 заполнения массива (IDs) - заполнение элементарными числами (1, 2, 3, 4, ...)
      IDs = (int*)malloc(size * sizeof(int));
      values = (int*)malloc(size * sizeof(int));
      printf("Input exams scores for students by ID (between spaces)\n");
      for (int i = 0; i < size; i++) {
        printf("ID:%d> ", i + 1);
        scanf_s("%d %d %d", &exam_scores_1, &exam_scores_2, &exam_scores_3);
        values[i] = exam_scores_1 + exam_scores_2 + exam_scores_3;
        IDs[i] = i + 1;
      }
      break;
    case 3:
      printf("Input number of population\n");
      printf("> ");
      scanf_s("%d", &size);

      values = (int*)malloc(size * sizeof(int));
      IDs = (int*)malloc(size * sizeof(int));

      // выделение памяти под двумерный массив с заполнением этого массива нулями
      /* Массив acuaintance для, например, 5 человек изначально выглядит так:
       * 0 0 0 0 0
       * 0 0 0 0 0
       * 0 0 0 0 0
       * 0 0 0 0 0
       * 0 0 0 0 0
       */
      acuaintance = (int**)malloc(size * sizeof(int*));
      for (int i = 0; i < size; i++) {
        acuaintance[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
          acuaintance[i][j] = 0;
        }
      }

      // способ 4 заполнения массива - ручной ввод (с клавиатуры)
      printf("Input number of friends for resident num.\n");
      for (int i = 0; i < size; i++) {
        printf("%d> ", i + 1);
        scanf_s("%d", &values[i]);
        IDs[i] = i + 1;
      }
      break;
    default:
      break;
    }

    // ACTIONS BLOCK (algorithms)
    switch (task) {
    case 1:
      // циклический сдвиг вправо
      for (int j = 0; j < shift; j++) {
        prev = values[0];
        for (int i = 1; i < size; i++) {
          cur = values[i];
          values[i] = prev;
          prev = cur;

        }
        values[0] = prev;
      }
      // разворот
      for (int i = 0; i < size / 2; i++) {
        temp_1 = values[i];
        values[i] = values[size - i - 1];
        values[size - i - 1] = temp_1;
      }
      break;
    case 2:
      // сортировка по возрастанию с запоминанием индексов
      for (int j = 0; j < size; j++) {
        int all_right = 1;
        for (int i = 0; i < size; i++) {
          // если встретились значения в неправильном порядке - меняем их местами
          // меняем местами и их индексы, чтобы получить порядок элементов
          if (values[i] < values[i + 1]) {
            temp_1 = values[i];
            temp_2 = IDs[i];
            values[i] = values[i + 1];
            IDs[i] = IDs[i + 1];
            values[i + 1] = temp_1;
            IDs[i + 1] = temp_2;
            all_right = 0;
          }
        }
        // если ни одной перестановки на итерации не сделали - завершаем
        if (all_right) break;
      }
      break;
    case 3:
      // простая проверка на наличие ошибки в задании данных
      mistake_in_data = 0;
      not_all = 1;
      for (int i = 0; i < size; i++) {
        if (values[i] < 0 || values[i] >= size) {
          mistake_in_data = 1;
          break;
        }
      }
      // пока мы не обнаружим ошибку в данных или не обработаем все значения - работаем
      while (!mistake_in_data || not_all) {
        // сортировка по возрастанию с запоминанием индексов
        /* Пример из формулировки - 5 : 2 4 3 1 2
         * до первой сортировки:
         * values: 2 4 3 1 2
         * IDs:    1 2 3 4 5
         * после первой сортировки
         * values: 4 3 2 2 1
         * IDs:    2 3 1 5 4
         */
        for (int j = 0; j < size; j++) {
          int all_right = 1;
          for (int i = 0; i < size; i++) {
            if (values[i] < values[i + 1]) {
              temp_1 = values[i];
              temp_2 = IDs[i];
              values[i] = values[i + 1];
              IDs[i] = IDs[i + 1];
              values[i + 1] = temp_1;
              IDs[i + 1] = temp_2;
              all_right = 0;
            }
          }
          if (all_right) break;
        }
        // если наибольший результат 0, то мы все знакомства отметили - прерываем цикл
        if (values[0] == 0) {
          not_all = 0;
          break;
        }
        // берем самого нагруженнного друзьями человека (у него номер IDs[0])
        // отмечаем, что он дружит с values[0] людьми
        for (int i = 1; i < values[0] + 1; i++) {
          // IDs[0] дружит с IDs[i]
          acuaintance[IDs[0] - 1][IDs[i] - 1] = 1;
          // также помечаем, что IDs[i] дружит с IDs[0]
          acuaintance[IDs[i] - 1][IDs[0] - 1] = 1;
          // мы отметили для IDs[i] одно знакомство - уменьшим число его друзей
          values[i] -= 1;
          // если вышли в отрицательные числа - данные неправильные (кто-то наврал)
          if (values[i] < 0) {
            mistake_in_data = 1;
            break;
          }
        }
        // самого "популярного" человека мы рассмотрели и отметим его через -1, 
        // чтобы это значение нам не мешало
        values[0] = -1;

        /* Расмотрим наш пример с 5 : 2 4 3 1 2
         *
         * 1 итерация
         * Мы отмечаем, что у человека номер 2 больше всего друзей (4) и отмечаем их
         * (выбираем людей у кого максимум неотмеченных нами дружеских знакомств)
         * values: 4 3 2 2 1
         * IDs:    2 3 1 5 4
         * человек №2 - 3 1 5 4
         * 0 1 0 0 0
         * 0 0 0 0 0
         * 0 1 0 0 0
         * 0 1 0 0 0
         * 0 1 0 0 0
         * и знакомства с ним:
         * 0 1 0 0 0
         * 1 0 1 1 1
         * 0 1 0 0 0
         * 0 1 0 0 0
         * 0 1 0 0 0
         * values: -1 2 1 1 0
         * IDs:     2 3 1 5 4
         *
         * 2 итерация
         * values: 2 1 1 0 -1
         * IDs:    3 1 5 4  2
         * человек №3 - 1 5
         * 0 1 1 0 0
         * 1 0 1 1 1
         * 1 1 0 0 1
         * 0 1 0 0 0
         * 0 1 1 0 0
         * values: -1 0 0 0 -1
         * IDs:     3 1 5 4  2
         *
         * 3 итерация
         * values: 0 0 0 -1 -1
         * IDs:    1 5 4  3  2
         * человек №1 - .
         * values[0] == 0 - break
         *
         * Окончательный результат восстанавливаем по таблице знакомств
         * 0 1 1 0 0
         * 1 0 1 1 1
         * 1 1 0 0 1
         * 0 1 0 0 0
         * 0 1 1 0 0
         *
         * 1: 2 3 (в первом столбце единицы во второй и третьей строке)
         * 2: 1 3 4 5
         * 3: 1 2 5
         * 4: 2
         * 5: 2 3
         *
         */
      }
      break;
    default:
      break;
    }

    // OUTPUT
    switch (task) {
    case 1:
      printf("Output massive:   ");
      for (int i = 0; i < size; i++)
        printf("%d ", values[i]);
      printf("\n");
      break;
    case 2:
      printf("Passing score: %d\n", values[admission_plan - 1]);
      printf("Rate : Student ID : Summ Of Score\n");
      for (int i = 0; i < size; i++) {
        if (i == admission_plan)
          printf("================================\nNOT ENTER IN UNN\n");
        printf("%d : stud%d : %d\n", i + 1, IDs[i], values[i]);
      }
      free(IDs);
      break;
    case 3:
      if (mistake_in_data)
        printf("\n !!! OPS is mistake in input data\n");
      else {
        printf("Human: his friends\n");
        for (int i = 0; i < size; i++) {
          printf("%d: ", i + 1);
          for (int j = 0; j < size; j++) {
            if (acuaintance[i][j] != 0) printf("%d ", j + 1);
          }
          printf("\n");
        }
      }
      free(IDs);
      for (int i = 0; i < size; i++) free(acuaintance[i]);
      free(acuaintance);
      break;
    default:
      break;
    }

    // не забываем чистить выделенную память
    free(values);
  }

  return 0;
}
