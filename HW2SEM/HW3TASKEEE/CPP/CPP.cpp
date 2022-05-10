#include <iostream>
#include "Tabulator.h"

using namespace std;

Tabulator tabulator;

void Choose_Set_Data();
void Choose_Get_Data();
void Choose_Tabulate_function();

int main()
{
    int16_t choice_1 = 1;
    bool exit = false;
    do
    {
        cout << endl; //вывод: список действий - главное меню
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "-Action list:" << endl;
        cout << "3. Tabulate the function" << endl;
        cout << "2. Get data from tabulation." << endl;
        cout << "1. Set data for tabulation." << endl;
        cout << "0. Exit." << endl;
        cout << "-Perform the action: ";
        cin >> choice_1; //Выбор пользователя
        cout << endl;

        switch (choice_1) // проверка выбора пользователя
        { //Если уберём где-нибудь break (пример case 1), то выполнение программы продолжится (выполнится и case 2 до встречи с break)
        // break не обязателен в default, его можно убрать или оставить для удостоверения в правильном ходе программы

        case 3: // Get data from tabulation - вызов метода - табулировать функцию
        { Choose_Tabulate_function(); break; }

        case 2: // Get data from tabulation - вызов метода - вывод списка действий по получению данных
        { Choose_Get_Data(); break; }

        case 1: // Set data for tabulation - вызов метода - вывод списка действий по вводу данных
        { Choose_Set_Data(); break; }

        case 0: // Exit - Выход из меню и программы
        { exit = true; cout << "--Goodbye." << endl; break; }

        default: // Если число-действие не найдено в списке
        { cout << "--Unknown command." << endl; break; }

        }

    } while (exit != true);

    return 0;
}

void Choose_Tabulate_function()
{
    int16_t choice_2 = 1;
    bool exit = false;
    do
    {
        cout << "---------------------------" << endl; //список подменю 
        cout << endl;
        cout << "-Set data for tabulation:" << endl;
        cout << "2. Set the number of tabulation points" << endl;
        cout << "1. Set the tabulation interval" << endl;
        cout << "0. Return back" << endl;
        cout << "Perform the action: ";
        cin >> choice_2; //Выбор пользователя
        cout << endl;
        switch (choice_2)
        {
        case 2: // Set the number of tabulation points - ввод значения кол-во точек табулирования
        {
            int n;
            bool correct = false;
            cout << "--Enter the number of tabulation points" << endl; cin >> n;
            tabulator.set_number_of_tabulation(n);
            break;
        }
        case 1: // Set the tabulation interval - ввод значений интервала
        {
            float a, b;
            bool correct = false;
            while (correct == false)
            {
                cout << "--Enter the values of the tab interval [a,b]" << endl;
                cin >> a; cin >> b;
                correct = tabulator.set_interval_of_tabulation(a, b);
            };
            break;
        }
        case 0: // Return back - Выход из подменю
        { exit = true; break; }
        default: // Если число-действие не найдено в списке
        { cout << "--Unknown command." << endl; break; }
        }
    } while (exit != true);
    //tabulator.tabulate_the_function();
}

void Choose_Get_Data()
{

    int16_t choice_2 = 1;
    bool exit = false;
    do
    {
        cout << "---------------------------" << endl; //список подменю 
        cout << endl;
        cout << "-Get data from tabulation:" << endl;
        cout << "2. Get the number of tabulation points" << endl;
        cout << "1. Get the tabulation interval" << endl;
        cout << "0. Return back" << endl;
        cout << "Perform the action: ";
        cin >> choice_2; //Выбор пользователя
        cout << endl;
        switch (choice_2)
        {
        case 2: // Get the number of tabulation points
        {
            tabulator.get_number_of_tabulation();
            break;
        }
        case 1: // Get the tabulation interval
        {
            tabulator.get_interval_of_tabulation();
            break;
        }
        case 0: // Return back - Выход из подменю
        { exit = true; break;
        }
        default: // Если число-действие не найдено в списке
        { cout << "--Unknown command." << endl; break; }
        }
    } while (exit != true);
}

void Choose_Set_Data()
{

    int16_t choice_2 = 1;
    bool exit = false;
    do
    {
        cout << "---------------------------" << endl; //список подменю 
        cout << endl;
        cout << "-Set data for tabulation:" << endl;
        cout << "2. Set the number of tabulation points" << endl;
        cout << "1. Set the tabulation interval" << endl;
        cout << "0. Return back" << endl;
        cout << "Perform the action: ";
        cin >> choice_2; //Выбор пользователя
        cout << endl;
        switch (choice_2)
        {
        case 2: // Set the number of tabulation points - ввод значения кол-во точек табулирования
        {
            int n;
            bool correct = false;
            cout << "--Enter the number of tabulation points" << endl; cin >> n;
            tabulator.set_number_of_tabulation(n);
            break;
        }
        case 1: // Set the tabulation interval - ввод значений интервала
        {
            float a, b;
            bool correct = false;
            while (correct == false)
            {
                cout << "--Enter the values of the tab interval [a,b]" << endl;
                cin >> a; cin >> b;
                correct = tabulator.set_interval_of_tabulation(a, b);
            };
            break;
        }

        case 0: // Return back - Выход из подменю
        { exit = true; break; }

        default: // Если число-действие не найдено в списке
        { cout << "--Unknown command." << endl; break; }
        }

    } while (exit != true);
}

