#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3
#define K 3
#define COORDINATES 3

int generateRandNumber(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
    
}

int** SetMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
    
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
            
        }
        printf("\n");
    }
    
}

int** multMatrixOnNumber(int** matrix, int n, int m, int value) {
    int** res = NULL;
    res = SetMemory(res, N, M);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * value;
            
        }
        
    }
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
    matrix = SetMemory(matrix, n, m);
    fillArrayRandValues(matrix, n, m, max, min);
    printf("Matrix %c = \n", name);
    printMatrix(matrix, n, m);
    return matrix;
    
}

int* VectorSetMemory(int* matrixVector, int vc) {
    matrixVector = (int*)malloc(vc * sizeof(int*));
    return matrixVector;
    
}

void fillVectorRandValues(int* matrixVector, int vc, int max, int min) { //int**
    for (int i = 0; i < vc; i++) {
        matrixVector[i] = generateRandNumber(max, min);
        
    }
    
}

void VectorPrint(int* matrixVector, int vc) {
    for (int i = 0; i < vc; i++) {
        printf("%d ", matrixVector[i]);
        
    }
    
    printf("\n");
    
}

int* VectorCreate(int* matrixVector, int vc, int max, int min, char name) {
    matrixVector = VectorSetMemory(matrixVector, COORDINATES);
    fillVectorRandValues(matrixVector, COORDINATES, max, min);
    printf("Vector %c = \n", name);
    VectorPrint(matrixVector, vc);
    return matrixVector;
    
}

int* multVectorOnNumber(int* matrixVector, int vc, int value) {
    int* res = NULL;
    res = VectorSetMemory(res, COORDINATES);
    for (int i = 0; i < vc; i++) {
        res[i] = matrixVector[i] * value;
        
    }
    
    return res;
    
}

int main() {
    
    int **matrix_A = NULL, **matrix_B = NULL, **result = NULL;
    int *vector_A = NULL, *vector_B = NULL, *resultV = NULL;
    int max = 4, min = 0, value = 0;
    
    srand((unsigned)time(NULL));
    
    matrix_A = createMatrix(matrix_A, N, M, max, min, 'A');
    matrix_B = createMatrix(matrix_B, M, K, max, min, 'B');
    value = generateRandNumber(max, min);
    
    result = SetMemory(result, N, M);
    result = multMatrixOnNumber(matrix_A, N, M, value);
    printf("Matrix A x %d = \n", value);
    printMatrix(result, N, M);
    
    freeMemory(result, N, M);
    
    result = SetMemory(result, N, M);
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix_A[j][i];
            
        }
        
    }
    
    printf("Matrix AT = \n");
    printMatrix(result, M, N);
    freeMemory(result, M, N);
    
    result = SetMemory(result, N, K);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M; k++) {
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
                
            }
            
        }
        
    }
    
    result = SetMemory(result, N, M);
    
    if (N == K) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result[i][j] = matrix_A[i][j] + matrix_B[i][j];
                
            }
            
        }
        
        printf("Matrix A + B = \n");
        printMatrix(result, N, K);
        
    }
    
    else {
        printf("Error \n\n");
    }
    
    freeMemory(result, N, K);
    
    vector_A = VectorCreate(vector_A, COORDINATES, max, min, 'A');
    vector_B = VectorCreate(vector_B, COORDINATES, max, min, 'B');
    
    value = generateRandNumber(max, min);
    
    resultV = VectorSetMemory(resultV, COORDINATES);
    
    resultV = multVectorOnNumber(vector_A, COORDINATES, value);
    printf("Vector A x %d \n", value);
    VectorPrint(resultV, COORDINATES);
    
    free(resultV);
    
    resultV = VectorSetMemory(resultV, COORDINATES);
    
    for (int i = 0; i < COORDINATES; i++) {
        resultV[i] = vector_A[i] + vector_B[i];
        
    }
    
    printf("Vector A + B = \n");
    VectorPrint(resultV, COORDINATES);
    
    free(resultV);
    
    resultV = VectorSetMemory(resultV, COORDINATES);
    
    if (COORDINATES < 3) {
        
        printf("Error.");
        
    }
    
    else {
        for (int i = 0; i < COORDINATES; i++) {
            
            switch (i) {
                    
                case 0:
                    
                    resultV[0] = vector_A[1] * vector_B[2] - vector_A[2] * vector_B[1];
                    break;
                    
                case 1:
                    
                    resultV[1] = -1 * (vector_A[0] * vector_B[2] - vector_A[2] * vector_B[0]);
                    break;
                    
                case 2:
                    
                    resultV[2] = vector_A[0] * vector_B[1] - vector_A[1] * vector_B[0];
                    break;
                                       
            }
            
        }
        
        printf("Vector A x B = \n");
        VectorPrint(resultV, COORDINATES);
        
    }
    
    free(resultV);
    
    freeMemory(matrix_A, N, M);
    freeMemory(matrix_B, M, N);
    
    free(vector_A);
    free(vector_B);
    
    
    return 0;
    
}

