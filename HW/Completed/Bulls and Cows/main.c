#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int i = 0, j, temp, n, * computer_massive;
    
    printf("Welcome to the game 'Bulls and Cows!' \nEnter size of the number that i will guess. (between 2 to 5). \nYou size: ");
    
    while (1) {
        
        scanf("%d", &n);
        
        if ((n >= 2) && (n <=5))
            break;
        else
            printf("Wrong size! Try again: ");
        
    }
        
    srand((unsigned)time(NULL));
    
    computer_massive = malloc(n * sizeof(int));
    
    while (i < n) {
        
        if (i == 0) {
            computer_massive[i] = 1 + rand() % 9;
            i++;
            
        }
        
        else {
            
            temp = rand() % 9;
            
            int e = 1;
            
            for (j = 0; e && j != i; j++) {
                e &= (temp != computer_massive[j]);
                
            }
            
            if (e) {
                computer_massive[i] = temp;
                i++;
                
            }
            
        }
        
    }
    
    int userN, numbersu, * user_massive;
    
    while (1) {
        
        printf("Enter %d numbers: ", n);
        scanf("%d", &userN);
        
        user_massive = malloc(n * sizeof(int));
        
        int x = n;
        
        while (x > 0) {
            
            numbersu = userN % 10;
            user_massive[x - 1] = numbersu;
            userN = userN / 10;
            x--;
            
        }
        
        int bulls = 0, cows = 0;
        
        for (int temp1 = 0; temp1 < n; temp1++) {
            for (int temp2 = 0; temp2 < n; temp2++) {
                if (user_massive[temp1] == computer_massive[temp2] && temp1 == temp2) {
                    bulls++;
                    
                    if (bulls == n) {
                        printf("Wow, you won! \n");
                        exit(0);
                        
                    }
                    
                }
                
                else if (user_massive[temp1] == computer_massive[temp2] && temp1 != temp2) {
                    cows++;
                    
                }
                
            }
            
        }
        
        printf("bulls : %d, cows : %d \n", bulls, cows);
        
    }
    
    return 0;
    
}
