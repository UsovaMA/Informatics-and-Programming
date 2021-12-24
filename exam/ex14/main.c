#include <stdio.h>
#include <stdlib.h>

int game(int* array1, int* array2, int N) {
    for (int i = 0; i < N - 1; i++) {
        if (array1[i] == array2[i + 1]);
        else return 0;
    }
    return  1;
}

int main() {
    
    int N, result = 1;
    
    printf("Input size: ");
    
    while (1) {
        
        scanf("%d", &N);
        
        if ((N >= 2))
            break;
        else
            printf("Wrong size! Try again: ");
    }
    
    int* array1 = (int*)malloc(N * sizeof(int));
    
    printf("Inpit numbers: \n");
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &array1[i]);
    }
    
    int* array2 = (int*)malloc(N * sizeof(int));
    
    printf("Inpit numbers: \n");
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &array2[i]);
    }
    
    if (result == game(array1, array2, N))
        printf("true \n");
    else printf("false \n");
    
    return 0;
}
