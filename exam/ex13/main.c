#include <stdio.h>
#include <stdlib.h>

struct Answer {
    int x;
    int y;
};

struct Answer sum(int* array, int N) {
    struct Answer num;
    num.x = num.y = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] % 2) {
            num.y += array[i];
        }
        else num.x += array[i];
    }
    return num;
}

int main() {
    
    int N;
    struct Answer result;
    
    printf("Input size: ");
    scanf("%d", &N);
    int* array = (int*)malloc(N * sizeof(int));
    printf("Input array: \n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    result = sum(array, N);
    printf("[%d, %d] \n", result.x, result.y);
}
