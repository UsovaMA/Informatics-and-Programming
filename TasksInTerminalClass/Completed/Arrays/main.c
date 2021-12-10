#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int* array;
    int* reverse;
    
    int mode, size, x, e = 0, temp = 0;
    
    printf("Chose mode (1-2): ");
    scanf("%d", &mode);
    printf("Array size: ");
    scanf("%d", &size);
    
    switch (mode) {
        
        case 1:
            
            array = (int*)malloc(size * sizeof(int));

            if (!array) {
                printf("Error");
                exit(1);
                
            }

            for (int i = 0; i < size; i++) {
                array[i] = 0;
                
            }

            printf("Enter array: \n");
            for (int i = 0; i < size; i++) {
                scanf("%d", &e);
                array[i] = e;
                
            }

            if (size % 2 == 0) {
                for (int i = 0, j = size / 2; j < size; i++, j++) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    
                }
                
            }

            else {

            for (int i = 0, j = size / 2; j < size; i++, j++) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

            }

            array[size - 1] = temp;
            for (int i = size - 1; i >= size / 2 + 1; i--) {
                array[i] = array[i - 1];

            }

            array[size / 2 + 1] = temp;

            }

            printf("Result: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", array[i]);

            }
            
            break;
            
        case 2:
            
            array = (int*)malloc(size * sizeof(int));
            reverse = (int*)malloc(size * sizeof(int));
            
            if (!array || !reverse) {
                printf("Error \n");
                exit(1);
                
            }
            
            for (int i = 0; i < size; i++) {
                reverse[i] = 0;
                array[i] = 0;
                
            }
            
            printf("Input array \n");
            for (int i = 0; i < size; i++) {
                scanf("%d", &x);
                array[i] = x;
                
            }
            
            for (int i = size / 2, j = 0; i < size; i++, j++) {
                reverse[j] = array[i];
                
            }
            
            for (int i = 0, j = size / 2 + size % 2; j < size; i++, j++) {
                reverse[j] = array[i];
                
            }
            
            printf("Result: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", reverse[i]);
                
            }
            
        break;
            
    }
            
    return 0;
    
}
