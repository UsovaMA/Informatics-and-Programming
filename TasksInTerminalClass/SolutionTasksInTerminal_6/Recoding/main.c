
/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода.
Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить
проблему дублирования он решил вынести часть кода в функции.
Помогите ему в этом, а также допишите функционал, который он не успел.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2


void PrintMatrix(int** matrix, int STR, int STLB)      //STR - строки, STLB - столбцы
{
    for (int i = 0; i < STR; i++) {                    //Функция для вывода массива
        for (int j = 0; j < STLB; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void Memory(int** matrix, int STR, int STLB)           //Функция выделения памяти для массива
{
    matrix = (int**)malloc(STR * sizeof(int*));
    for (int i = 0; i < STR; i++)
        matrix[i] = (int*)malloc(STLB * sizeof(int));
}
void PrintVector(int * vector)                         //Функция для вывода вектора
{
    for (int i = 0; i < M; i++)
    {
        printf("%d ", vector[i]);
    }
}
void Filling(int * vector)                             //Функция для заполнения вектора
{
    for (int i = 0; i < M; i++)
    {
        vector[i] = rand() % 10;
    }
}

int main() {
    int** matrix_A = NULL, ** matrix_B = NULL, ** matrix_C = NULL, ** result = NULL, * vector_A = NULL, * vector_B = NULL, * vector_C = NULL, * vector_D;
    int max = 4, min = 0, value = 0;
    // выделение памяти под матрицу (двумерный массив)
    // N строк, M столбцов (матрица N x M)
    
    matrix_A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_A[i] = (int*)malloc(M * sizeof(int));

    // заполнение массива рандомными значениями
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix_A[i][j] = (max - min) * ((float)rand() / RAND_MAX) + min;
        }
    }
    
    printf("Matrix A =\n");
    // печать матрицы на экран
    PrintMatrix(matrix_A, N, M);

    // умножение матрицы на число

    value = (max - min) * ((float)rand() / RAND_MAX) + min;

    // выделение памяти
    result = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        result[i] = (int*)malloc(M * sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = matrix_A[i][j] * value;
        }
    }

    printf("Matrix A x %d =\n", value);
    // печать матрицы на экран
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // транспонирование матрицы

    result = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        result[i] = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix_A[j][i];
        }
    }
    
    printf("Matrix AT =\n");
    // печать матрицы на экран
    PrintMatrix(result, M, N);

    // очищение результата после вывода
    for (int i = 0; i < M; i++) free(result[i]);
    free(result);

    // умножение двух матриц

    matrix_B = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        matrix_B[i] = (int*)malloc(K * sizeof(int));

    // заполнение массива рандомными значениями
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            matrix_B[i][j] = (max - min) * ((float)rand() / RAND_MAX) + min;
        }
    }

    printf("Matrix B =\n");
    // печать матрицы на экран
    PrintMatrix(matrix_B, M, K);

    result = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        result[i] = (int*)malloc(K * sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M; k++) {
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }

    printf("Matrix AxB =\n");
    // печать матрицы на экран
    PrintMatrix(result, M, K);
    
    // очищение результата после вывода
    for (int i = 0; i < N; i++) free(result[i]);
    free(result);

    // сложение двух матриц
    matrix_C = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_C[i] = (int*)malloc(M * sizeof(int));


    // матрица C размером как A
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix_C[i][j] = (max - min) * ((float)rand() / RAND_MAX) + min;
        }
    }
    
    printf("Matrix C =\n");
    // печать матрицы на экран
    PrintMatrix(matrix_C, N, M);
    

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_C[i][j];

    // сложенние матриц A и C

    printf("Matrix A+C =\n");
    PrintMatrix(matrix_C, N, M);

    //выделение памяти

    vector_A = (int*)malloc(M * sizeof(int*));
    vector_B = (int*)malloc(M * sizeof(int*));
    vector_C = (int*)malloc(M * sizeof(int*));
    vector_D = (int*)malloc(M * sizeof(int*));
   
    //заполнение массивов

    Filling(vector_A);
    Filling(vector_B);
    Filling(vector_D);

    // умножение вектора на число
  
  
    printf("Vector A = \n");

    PrintVector(vector_A);
    printf("\nVector B = \n");
    PrintVector(vector_B);
    printf("\nVector A * %d\n", value);
    for(int i = 0; i < M; i++)
    {
        vector_C[i] = vector_A[i] * value;
    }
    
    PrintVector(vector_C);
 

    // сложение двух векторов
    printf("\nVector A + B =\n");
    for (int i = 0; i < M; i++)
    {
        vector_A[i] = vector_A[i] + vector_B[i];
    }

    PrintVector(vector_A);

    printf("\nVector D = \n");
    PrintVector(vector_D);
    // умножение двух векторов
    printf("\nVector B * D = \n");
    for (int i = 0; i < M; i++)
    {
        vector_B[i] *= vector_D[i];
    }
    PrintVector(vector_B);

      // очищение всей выделенной памяти
    for (int i = 0; i < N; i++) free(matrix_A[i]);
    free(matrix_A);
    for (int i = 0; i < M; i++) free(matrix_B[i]);
    free(matrix_B);
    for (int i = 0; i < M; i++) free(matrix_C[i]);
    free(matrix_C);

    return 0;
}
