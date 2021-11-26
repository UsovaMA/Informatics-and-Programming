#include <stdio.h>
#include <locale.h>

int main() {
    char* locale = setlocale(LC_ALL, "");

    char x, m = -1;
    unsigned words = 0;
    unsigned numbers = 0;

    printf("Введите входной поток символов:\n");

    while ((x = getchar()) != EOF) {
        if (x == '\n') {
            break;
        }
        if (x == ' ' || x == '\t')
            m = -1;
        else if (m == -1) {
            if (48 <= x && x <= 57) {
                m = 1;
                numbers++;
            }
            if ((-128 <= x && x <= -17) || ((65 <= x && x <= 90) || (97 <= x && x <= 122))) {
                m = 1;
                words++;
            }
        }
    }
    printf("Слова: %u\n", words);
    printf("Числа: % u\n", numbers);
}