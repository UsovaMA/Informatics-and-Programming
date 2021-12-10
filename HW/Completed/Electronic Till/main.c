#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int openmenu(void) {
    
    printf("\n1 - Scan merchandise \n2 - View scanned information \n3 - Add to check \n4 - Generate check \n5 - Calculate final cost \n0 - Back to menu\n");
    
    return 1;
}

int main() {
    
    char clothing[SIZE][50] = { {"White Swarovski Tee"}, {"Business Matters Tee"}, {"Blue Bubble Tee"}, {"Cross Tee"}, {"Camel Swarovski Tee"}, {"Camel Arabic Logo Hoodie"}, {"Grey Arabic Logo Crewneck"}, {"Blue Arabic Logo Hoodie"}, {"Haliky Cap"}, {"Swarovski Butterflies"}, };
    int price[SIZE] = { 2200, 2200, 2200, 2200, 2200, 6500, 4500, 6500, 2990, 6990 };
    int barcode[SIZE] = { 4345, 9232, 1386, 8844, 4090, 3330, 5204, 7000, 8080, 9009 };
    int discount[SIZE] = { 10, 1, 5, 25, 2, 15, 50, 30, 20, 1 };
    int temp[100] = { 0 };
    
    printf("Clothing store welcomes you! \nHappy shopping!");
    
    openmenu();
    
    int menu, c, n = 0, s = 0, i = 0;
    
    do
    {
        printf("Enter number: ");
        scanf("%d", &menu);
        
        switch (menu) {
                
            case 1:
                
                printf("4345 - White Swarovski Tee\n9232 - Business Matters Tee\n1386 - Blue Bubble Tee\n8844 - Cross Tee\n4090 - Camel Swarovski Tee\n3330 - Camel Arabic Logo Hoodie\n5204 - Grey Arabic Logo Crewneck\n7000 - Blue Arabic Logo Hoodie\n8080 - Haliky Cap\n9009 - Swarovski Butterflies\nEnter barcode: ");
                scanf("%d", &c);
                
                for(int i = 0; i < SIZE; i++) {
                    if (c == barcode[i]) {
                        printf("Scan successful! \n");
                        s = c;
                        break;
                        
                    }
                    
                    else if (i + 1 == SIZE) {
                        printf("Barcode not found \n");
                        
                    }
                    
                }
                
                break;
                
            case 2:
                
                i = 0;
                
                while (s != barcode[i]) {
                    i++;
                    
                }
                
                printf("%s | price: %d rub | discount: %d%%\n", clothing[i], price[i], discount[i]);
                
                break;
                
            case 3:
                
                printf("Product added! \n");
                
                temp[n] = s;
                n++;
                
                break;
                
            case 4:
                
                printf("Your added: \n");
                
                float sum = 0;
                
                for (int i = 0; i < SIZE; i++) {
                    int k = 0;
                    
                    for (int j = 0; j < n; j++) {
                        if (barcode[i] == temp[j]) {
                            k++;
                            
                        }
                        
                    }
                    
                    if (k > 0) {
                        float p = (float)price[i] * k;
                        float r = abs(((float)discount[i] / 100 - 1) * p);
                        
                        sum += r;
                        
                        printf("%s\t %d x %d rub \n", clothing[i], k, price[i]);
                        printf("Discounted price: %.2f rub \n", r);
                        
                    }
                    
                }
                
                printf("Total: %.2f \n", sum);
                
                break;
                
            case 5:
                
                sum = 0;
                
                float d = 0;
                
                for (int i = 0; i < SIZE; i++) {
                    int k = 0;
                    
                    for (int j = 0; j < n; j++) {
                        if (barcode[i] == temp[j]) {
                            k++;
                            
                        }
                        
                    }
                    
                    if (k > 0) {
                    
                        float p = (float)price[i] * k;
                        float r = abs(((float)discount[i] / 100 - 1) * p);
                        
                        sum += p;
                        d += p - r;
                        
                        printf("\n%s | Price: %.2f rub \n", clothing[i], p);
                        printf("Discount: -%.2f rub \n", p - r);
                        
                    }
                    
                }
                
                printf("Price: %.2f \n", sum);
                printf("Discount -%.2f \n", d);
                printf("Total: %.2f \n\n", sum - d);
                
                break;
                
            case 0:
            
                openmenu();
                break;
                
        }
        
    } while (menu != 5);
    
}
