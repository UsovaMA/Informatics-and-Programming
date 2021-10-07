#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char sym;
    sym = '\0';
    int count_n, count_w, flag;
    count_n = count_w =  flag = 0;
    printf("This programm count numbers and words in input string\nTo continue enter string\n");
    do {
        do {
            scanf_s("%c", &sym);
            if ((sym != ' ' && sym != '\t') && flag == 0) {
                flag = 1;
                if (sym >= 48 && sym <= 57) { //Proverka prinadlejnosti simvola k cifram
                    count_n++;
                }
                else { count_w++; }
            }
            else
                if (sym == ' ' || sym == '\t') flag = 0;
        } while (sym != '\n');
        printf("Count of numbers = %d\nCount of words = %d\n", count_n, count_w);
        printf("If you want to continue count words and numbers enter string.\n");
        printf("Else print 0\n");
        scanf_s("%c", &sym);
    } while (sym != '0');
    printf("GoodBye!");
    return 0;
}