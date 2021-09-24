#include <stdio.h>
#include <math.h>

int main() {
    printf("Task witch circles:\n");

    float x1,x2,y1,y2,r1,r2;
    float d;

    printf("Input 1st circle:\n");
    printf("x:");
    scanf("%f", &x1);
    printf("y:");
    scanf("%f", &y1);
    printf("r:");
    scanf("%f", &r1);

    printf("Input 2nd circle:\n");
    printf("x:");
    scanf("%f", &x2);
    printf("x:");
    scanf("%f", &y2);
    printf("x:");
    scanf("%f", &r2);

    d = sqrt(pow(x2 - x1,2)+ pow(y2 - y1,2));

    if (d == r1 + r2)
    {
        printf("Kssayutsa");
    }else
        if(d < r1 + r2)
        {
            if (d == 0 && r1 == r2)
            {
                printf("Sovpadaut");
            }else
                if(d + r1 < r2 || d + r2 < r1 )
                {
                    printf("Odna vnutri drugoi");
                }else
                {
                    printf("Peresecayutsa");
                }
        }else
            if( d > r1 + r2)
            {
                printf("Ne svazani");
            }


    return 0;
}
