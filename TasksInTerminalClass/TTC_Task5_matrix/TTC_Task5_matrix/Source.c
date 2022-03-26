#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2


int main() {
    int** matrix_A = NULL, ** matrix_B = NULL, ** result = NULL;
    int max = 4, min = 0, value = 0;

    // ��������� ������ ��� ������� (��������� ������)
    // N �����, M �������� (������� N x M)
    matrix_A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        matrix_A[i] = (int*)malloc(M * sizeof(int));

    // ���������� ������� ���������� ����������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix_A[i][j] = (max - min) * ((float)rand() / RAND_MAX) + min;
        }
    }

    printf("Matrix A =\n");
    // ������ ������� �� �����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix_A[i][j]);
        }
        printf("\n");
    }

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
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // �������� ���������� ����� ������
    for (int i = 0; i < M; i++) free(result[i]);
    free(result);

    // ��������� ���� ������

    matrix_B = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        matrix_B[i] = (int*)malloc(K * sizeof(int));

    // ���������� ������� ���������� ����������
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            matrix_B[i][j] = (max - min) * ((float)rand() / RAND_MAX) + min;
        }
    }

    printf("Matrix B =\n");
    // ������ ������� �� �����
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", matrix_B[i][j]);
        }
        printf("\n");
    }

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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // �������� ���������� ����� ������
    for (int i = 0; i < N; i++) free(result[i]);
    free(result);

    // �������� ���� ������
    // ???

    // ��������� ������� �� �����
    // ???

    // �������� ���� ��������
    // ???

    // ��������� ���� ��������
    // ???

      // �������� ���� ���������� ������
    for (int i = 0; i < N; i++) free(matrix_A[i]);
    free(matrix_A);
    for (int i = 0; i < M; i++) free(matrix_B[i]);
    free(matrix_B);

    return 0;
}
