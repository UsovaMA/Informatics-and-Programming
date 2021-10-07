#include <iostream>
#include "windows.h"
#include <time.h>
using namespace std;
int main()
{
    system("color 0B");
    setlocale(LC_CTYPE, "rus");
    srand((unsigned int)time(NULL));
    int rmin = 0, rmax = 1000;
    int variable_glavn = 0, question = ((rmax - rmin) * ((double)rand()) / RAND_MAX + rmin), user_answer = 0, i = 1000, Otvet = 0;
    cout << "Программа загадает или ты ей" << endl; //  программа загадывает,  я загадываю программе
    do
    {
        cout << "1. вариант первый\n";
        cout << "2. вариант второй\n";
        cout << "3. Интересно,  зачем  оно здесь?\n";
        cout << "0. SUDO HALT\n";
        cin >> variable_glavn;
        switch (variable_glavn)
        {
        case 1:
            system("CLS");
            cout << "Попробуй ввести число джиброни " << endl;
            while (user_answer != question)
            {
                cin >> user_answer;
                if (user_answer > question)
                {
                    cout << "Джиброни слишком мал для этого числа " << endl;
                }
                else if (user_answer < question)
                {
                    cout << "Джиброни больше чем твоя самооценка " << endl;
                }
            }
            cout << "Как истинный данжн мастер ты смог победить меня";
            getchar();
            getchar();
            system("CLS");
            break;
        case 2:
            system("CLS");
            cout << "Загадай мне число джиброни босс " << endl;
            cin >> question;

            getchar();
            getchar();
            system("CLS");
            break;
        case 0:
            return 0;
        case 3:
            system("CLS");
            cout << "3 от тысячи...хм это получается\n";
            cout << "1000-7 одно и тоже...сколько будет 1000-7...?\n";
            cin >> Otvet;
            if (Otvet == 993)
            {
                while (i > 7)
                {
                    i = i - 7;
                    cout << i << " - 7\n";
                    Sleep(10);
                }
                cout << " Dead Inside with deep deep dark fantasy";

                getchar();
                getchar();
            }
            system("CLS");
            break;
        default:
            system("CLS");
            cout << "Куда жмёшь слейв?";
            getchar();
            getchar();
            system("CLS");
        }
    } while (variable_glavn != 0);
    return 0;
}