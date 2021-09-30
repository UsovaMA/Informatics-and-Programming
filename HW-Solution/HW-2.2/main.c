#include <stdio.h>


/* Razrabotat' programmu, kotoraya schitaet kolichestvo slov i kolichestvo chisel vo vhodnom
potoke simvolov. Slovom schitat' posledovatel'nost' simvolov anglijskogo ili russkogo
alfavitov, chislom – posledovatel'nost' cifr. Slova i chisla vo vhodnom potoke otdelyayutsya
drug ot druga probelami (odnim ili neskol'kimi) ili simvolami tabulyacii. Potok zavershaetsya simvolom perevoda stroki.*/
int main()
{
    int flag, count_n, count_w;
    char str[100]; // Massiv so strokoi
    printf("Vvedite stroku\n");
    gets(str); // chtenie stroki
    count_n = count_w = flag = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] != ' ' && str[i] !='\t') && flag == 0) { 
                flag = 1;
                if (str[i]>=48 && str[i]<=57) { //Proverka prinadlejnosti simvola k cifram
                    count_n++;
                }
                else { count_w++; }
        }
        else
            if (str[i] == ' ' || str[i] == '\t') flag = 0;
    printf("V stroke soderjitsa:\n chisel: %d\n slov: %d", count_n, count_w);
    return 0;
}