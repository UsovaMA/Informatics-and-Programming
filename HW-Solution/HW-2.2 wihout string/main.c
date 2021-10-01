#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char sym;
    sym = '\0';
    int count_n, count_w, flag;
    count_n = count_w =  flag = 0;
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
    printf("%d %d", count_n, count_w);
    return 0;
}