#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2
#define VECTOR_COORDINAT 3

int MNG(int max, int min) {
    int v = (max - min) * ((float)rand() / RAND_MAX) + min;

    return v;
}

int** MSM(int** matr, int n, int m) {
    matr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matr[i] = (int*)malloc(m * sizeof(int));

    return matr;
}
 
void MP(int** matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matr[i][j]);
        }
    }
}

int** MMON(int** matr, int n, int m, int v) {
    int** res = NULL;
    res = MSM(res, N, M);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matr[i][j] * v;
        }
    }    return res;
}

void MFRV(int** matr, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matr[i][j] =MNG(max, min);
        }
    }
}

void MFM(int** matr, int n, int m) {
    for (int i = 0; i < n; i++) free(matr[i]);
    free(matr);
}

int** MC(int** matr, int n, int m, int max, int min, char im) {
    matr = MSM(matr, n, m);
    MFRV(matr, n, m, max, min);
    printf("Matr %c = ", im);
    MP(matr, n, m);
    return matr;
}

int* MVSM(int* matrV, int vc) {
    matrV = (int*)malloc(vc * sizeof(int*));
    return matrV;
}

void MVFRV(int** matrV, int vc, int max, int min) {
    for (int i = 0; i < vc; i++) {
        matrV[i] = MNG(max, min);
    }
}

void MVP(int* matrV, int vc) {
    for (int i = 0; i < vc; i++) {
        printf("%d ", matrV[i]);
    }
}

int* MVC(int* matrV, int vc, int max, int min, char im) {
    matrV = MVSM(matrV, VECTOR_COORDINAT);
    MVFRV(matrV, VECTOR_COORDINAT, max, min);
    printf("vektor %c = ", im);
    MVP(matrV, vc);

    return matrV;
}

int* MVMON(int* matrV, int vc, int v) {
    int* res = NULL;
    res = MVSM(res, VECTOR_COORDINAT);
    for (int i = 0; i < vc; i++) {
        res[i] = matrV[i] * v;
    }
    return res;
}

int main() {
    int** matr_A = NULL, ** matr_B = NULL, ** resultat = NULL;
    int* vektor_A = NULL, * vektor_B = NULL, * resultatV= NULL;
    int max = 4, min = 0, v = 0;

    srand(time(NULL));

    matr_A = MC(matr_A, N, M, max, min, 'A');
    matr_B = MC(matr_B, M, K, max, min, 'B');
    v = MNG(max, min);

    resultat = MSM(resultat, N, M);
    resultat = MMON(matr_A, N, M, v);
    printf("Matr A  %d =", v);
    MP(resultat, N, M);

    MFM(resultat, N, M);

    resultat = MSM(resultat, M, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            resultat[i][j] = matr_A[j][i];
        }
    }

    printf("Matr AT =");
    MP(resultat, M, N);
    MFM(resultat, M, N);

    resultat = MSM(resultat, N, K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            resultat[i][j] = 0;
            for (int k = 0; k < M; k++) {
                resultat[i][j] += matr_A[i][k] * matr_B[k][j];
            }
        }
    }

    printf("Matr A x B =");
    MP(resultat, N, K);
    MFM(resultat, N, K);

    resultat = MSM(resultat, N, M);

    if (N == K) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                resultat[i][j] = matr_A[i][j] + matr_B[i][j];
            }
        }
        printf("Matrix A + B =\n");
        MP(resultat, N, K);
    }
    else {
        printf("matrica nelzya dobavit");
    }

    MFM(resultat, N, K);

    vektor_A = MVC(vektor_A, VECTOR_COORDINAT, max, min, 'A');
    vektor_B = MVC(vektor_B, VECTOR_COORDINAT, max, min, 'B');

    v = MNG(max, min);

    resultatV = MVSM(resultatV, VECTOR_COORDINAT);
    resultatV = MVMON(vektor_A, VECTOR_COORDINAT, v);
    printf("Vektor A x %d\n", v);
    MVP(resultatV, VECTOR_COORDINAT);

    free(resultatV);

    resultatV = MVSM(resultatV, VECTOR_COORDINAT);

    for (int i = 0; i < VECTOR_COORDINAT; i++) {
        resultatV[i] = vektor_A[i] + vektor_B[i];
    }

    printf("Vektor A + B =");
    MVP(resultatV, VECTOR_COORDINAT);

    free(resultatV);

    resultatV = MVSM(resultatV, VECTOR_COORDINAT);

    if (VECTOR_COORDINAT < 3) {
        printf("nelzya umnojit");
    }
    else {
        for (int i = 0; i < VECTOR_COORDINAT; i++) {
            switch (i) {
            case 0:

                resultatV[0] = vektor_A[1] * vektor_B[2] - vektor_A[2] * vektor_B[1];
                break;

            case 1:

                resultatV[1] = -1 * (vektor_A[0] * vektor_B[2] - vektor_A[2] * vektor_B[0]);
                break;

            case 2:

                resultatV[2] = vektor_A[0] * vektor_B[1] - vektor_A[1] * vektor_B[0];
                break;

            }
        }
        printf("Vektor A x B ");
        MVP(resultatV, VECTOR_COORDINAT);
    }

    free(resultatV);

    MFM(matr_A, N, M);
    MFM(matr_B, M, N);

    free(vektor_A);
    free(vektor_B);

  return 0;
}