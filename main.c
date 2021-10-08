// Copyright © 2021 Belan
// Terminal Class Task #3

#include <stdio.h>

int main() {
    
    int n, w = 1, e = 0, i = 0;
    
    printf("Let's invert numbers! Exit? Enter 0.\n");
    
    while (w) {
        
        printf("Input number: ");
        
        do {
            if (e) printf("Wrong input! \nInput number: ");
            scanf("%d", &n);
            
            if (n == 0) {
                w = 0;
                break;
                
            }
            
            e = (n <= 0);
            
        } while (e);
        
        while (n > 0) {
            i = (i * 10 + n % 10);
            n /= 10;
            
        }
        
        printf("Result: %d \n\n", i);
        i = 0;
        
    }
    
    return 0;
    
}
