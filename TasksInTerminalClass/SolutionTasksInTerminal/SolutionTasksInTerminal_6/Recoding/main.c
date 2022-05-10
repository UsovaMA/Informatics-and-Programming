
/*
���������� ������.

����������� ��������� ���������, ���������� � ���������� ����������.

����������� ����� �������� ��� ��� � �����, ��� � ��� ����� ������������ ����.
�� ��������� ���� ��� � �� ������ ������� � ����� ����. ����� ���������
�������� ������������ �� ����� ������� ����� ���� � �������.
�������� ��� � ����, � ����� �������� ����������, ������� �� �� �����.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2


void PrintMatrix(int** matrix, int STR, int STLB)      //STR - ������, STLB - �������
{
    for (int i = 0; i < STR; i++) 
    {                                                  //������� ��� ������ �������
        for (int j = 0; j < STLB; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void Memory(int** matrix, int STR, int STLB)           //������� ��������� ������ ��� �������(�� ���� ������, �� �� ��������)
{
    matrix = (int**)malloc(STR * sizeof(int*));
    for (int i = 0; i < STR; i++)
        matrix[i] = (int*)malloc(STLB * sizeof(int));
}
void PrintVector(int * vector)                         //������� ��� ������ �������
{
    for (int i = 0; i < M; i++)
    {
        printf("%d ", vector[i]);
    }
}
void Filling_vector(int * vector)                      //������� ��� ���������� ������� � ��������
{
    for (int i = 0; i < M; i++)
    {
        vector[i] = rand() % 10;
    }
}
void Filling_matrix(int **matrix, int STR, int STLB)   //������� ��� ��������� ������� � ��������      
{
    int max = 4, min = 0;
    for (int i = 0; i < STR; i++) 
    {
        for (int j = 0; j < STLB; j++) 
        {
            matrix[i][j] = (max - min) * ((float)rand() / RAND_MAX) + min;
        }
    }
}

int main() {
    int** matrix_A, ** matrix_B, ** matrix_C, ** result ,* vector_A, * vector_B, * vector_C, * vector_D;
    int max = 4, min = 0, value = 0;
    // ��������� ������ ��� ������� (��������� ������)
    // N �����, M �������� (������� N x M)
    
    matrix_A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_A[i] = (int*)malloc(M * sizeof(int));

    // ���������� ������� ���������� ����������
    Filling_matrix(matrix_A, N, M);
    
    printf("Matrix A =\n");
    // ������ ������� �� �����
    PrintMatrix(matrix_A, N, M);

    // ��������� ������� �� �����

    value = (max - min) * ((float)rand() / RAND_MAX) + min;

    // ��������� ������
    result = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        result[i] = (int*)malloc(M * sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = matrix_A[i][j] * value;
        }
    }

    printf("Matrix A x %d =\n", value);
    // ������ ������� �� �����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // ���������������� �������

    result = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        result[i] = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix_A[j][i];
        }
    }
    
    printf("Matrix AT =\n");
    // ������ ������� �� �����
    PrintMatrix(result, M, N);

    // �������� ���������� ����� ������
    for (int i = 0; i < M; i++) free(result[i]);
    free(result);

    // ��������� ���� ������

    matrix_B = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        matrix_B[i] = (int*)malloc(K * sizeof(int));

    // ���������� ������� ���������� ����������
    Filling_matrix(matrix_B, M, K);

    printf("Matrix B =\n");
    // ������ ������� �� �����
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
    // ������ ������� �� �����
    PrintMatrix(result, M, K);
    
    // �������� ���������� ����� ������
    for (int i = 0; i < N; i++) free(result[i]);
    free(result);

    // �������� ���� ������
    matrix_C = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_C[i] = (int*)malloc(M * sizeof(int));


    // ������� C �������� ��� A
    Filling_matrix(matrix_C, N, M);
    
    printf("Matrix C =\n");
    // ������ ������� �� �����
    PrintMatrix(matrix_C, N, M);
    

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_C[i][j];

    // ��������� ������ A � C

    printf("Matrix A+C =\n");
    PrintMatrix(matrix_C, N, M);

    //��������� ������

    vector_A = (int*)malloc(M * sizeof(int*));
    vector_B = (int*)malloc(M * sizeof(int*));
    vector_C = (int*)malloc(M * sizeof(int*));
    vector_D = (int*)malloc(M * sizeof(int*));
   
    //���������� ��������

    Filling_vector(vector_A);
    Filling_vector(vector_B);
    Filling_vector(vector_D);

    // ��������� ������� �� �����
  
  
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
 

    // �������� ���� ��������
    printf("\nVector A + B =\n");
    for (int i = 0; i < M; i++)
    {
        vector_A[i] = vector_A[i] + vector_B[i];
    }

    PrintVector(vector_A);

    printf("\nVector D = \n");
    PrintVector(vector_D);
    // ��������� ���� ��������
    printf("\nVector B * D = \n");
    for (int i = 0; i < M; i++)
    {
        vector_B[i] *= vector_D[i];
    }
    PrintVector(vector_B);

    

      // �������� ���� ���������� ������
    for (int i = 0; i < N; i++) free(matrix_A[i]);
    free(matrix_A);
    for (int i = 0; i < M; i++) free(matrix_B[i]);
    free(matrix_B);
    for (int i = 0; i < M; i++) free(matrix_C[i]);
    free(matrix_C);

    free(vector_A);
    free(vector_B);
    free(vector_C);
    free(vector_D);

    return 0;
}
