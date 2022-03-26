#include <iostream>
#include "windows.h"
#include <time.h>
using namespace std;
int main()
{
    system("color 0B");
    setlocale(LC_CTYPE, "rus");
    srand((unsigned int)time(NULL));
    int rmin = 0, rmax = 1000, rmid = rmin + ((rmax - rmin) / 2);
    int variable_glavn = 0, variable_case_two, question = ((rmax - rmin) * ((double)rand()) / RAND_MAX + rmin), user_answer = 0;
    cout << "Программа загадает или ты ей" << endl; //  программа загадывает,  я загадываю программе
    do
    {
        cout << "1. вариант первый\n";
        cout << "2. вариант второй\n";
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
                    cout << "Джиброни больше, чем твоя самооценка " << endl;
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
            do
            {
                system("CLS");
                cout << "Загаданное число больше или меньше, чем " << rmid << endl;
                cout << "1. Больше\n";
                cout << "2. Меньше\n";
                cout << "9. ПОБЕДА\n";
                cout << "0. SUDO HALT\n";
                cin >> variable_case_two;
                switch (variable_case_two)
                {
                case 1: //больше
                    rmin = rmid;
                    rmid = rmin + round(double((rmax - rmin) / 2));
                    break;
                case 2: //меньше
                    rmax = rmid;
                    rmid = rmin + round(double((rmax - rmin) / 2));
                    break;
                case 9: //победа-победа, вместо обеда
                    system("CLS");
                    cout << "Я в себе и не сомневался, ведь я же компьютер! (ткни любую кнопку)";
                    getchar();
                    getchar();
                    system("CLS");
                    break;
                case 0: // экстренный рестарт
                    return 0;
                default:
                    system("CLS");
                    cout << "Куда жмёшь, слейв?";
                    getchar();
                    getchar();
                    system("CLS");
                    break;
                }
            } while (variable_case_two != 0);
            getchar();
            getchar();
            system("CLS");
            break;
        case 0:
            return 0;
        default:
            system("CLS");
            cout << "Куда жмёшь, слейв?";
            getchar();
            getchar();
            system("CLS");
        }
    } while (variable_glavn != 0);
    return 0;
}