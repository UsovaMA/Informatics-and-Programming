#include <math.h>
#include <stdio.h>

int main() {
    
    double x1, y1, r1, x2, y2, r2, d;
    
    printf("Enter X first circle: ");
    scanf("%lf", &x1);
    printf("Enter Y first circle: ");
    scanf("%lf", &y1);
    printf("Enter R first circle: ");
    scanf("%lf", &r1);
    
    printf("Enter X second circle: ");
    scanf("%lf", &x2);
    printf("Enter Y second circle: ");
    scanf("%lf", &y2);
    printf("Enter R second circle: ");
    scanf("%lf", &r2);
    
    d = (sqrt(pow(x1 - x2, 2) + pow(y2 - y1, 2)));
    
    if (d == r1 + r2) {
        printf("Circles touch each other \n");
        
    }
    if (d < r1 + r2) {
        if ((d == 0) & (r1 == r2)) {
            printf("Circles are identical \n");
            
        }
        else if (d + r1 < r2 || d + r2 < r1) {
        printf("One circle is inside of another \n");
            
        }
        else {
            printf("Circles cross each other \n");
            
        }
        
    }
    if (d > r1 + r2) {
        printf("Circles don't interact witch each other \n");
        
    }
    
    return 0;
    
}
