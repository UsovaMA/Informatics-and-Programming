#include <iostream>
#include "Tabulator.h"
//1. Файл заголовка используется для того, чтобы чтобы объявить класс, в нём можно проводить реализацию,
//но это не надо делать, потому что это интерфейс (объявление) класса вот этот h заголовок
//реализация методов классов вот эти всякие сеттеры геттеры и табулирование происходят именно в cpp с помощью наследования. 
//Подключается эти классы с помощью include и вот этот табулятор.h
//чтобы заработал класс его нужно там подключить ты там увидишь include табулятор.h сверху, типа то что мы объявили и с помощью наследования  подключаем методы
//чтобы мы могли работать с его методами, как раз-таки вот реализуем установку данных или получение их или табулируем функцию
//В Мейн он подключается, чтобы мы использовали методы
//Можно вообще обойтись без создания отдельных файлов и сделать всё в main 
using namespace std;

void Choose_Set_Data(Tabulator& tabulator);          // Объявляем функции заранее для компилятора, иначе ошибка
void Choose_Get_Data(Tabulator& tabulator);          // на входе должен быть объект типа Tabulator
void Choose_Tabulate_function(Tabulator& tabulator); // & - передача объекта по ссылке без копирования памяти

int main()

//В мейн создаем табулятор создаем класс объект класса. 
{
    int16_t choice_1 = 1;
    bool exit = false;

    //создание начального объекта и проверка данных на корректность..
    //в будущем будет перенесено в switch с использованием списков массивов,
    //так как проблема в том, что за пределами цикла switch "tabulator" не определяется
    cout << "-Set data for tabulation:" << endl;
    int n;
    float a, b;
    bool correct = false;
    while (correct == false)
    {
        cout << "--Enter the values of the tab interval [a,b] (a < b)" << endl;
        cin >> a;
        cin >> b;
        cout << "--Enter the number of tabulation points (n > 0)" << endl;
        cin >> n;
        if ((a >= b))
        {
            cout << "---Invalid values! (a < b)" << endl;
        }
        if ((n <= 0))
        {
            cout << "---Invalid values! (n > 0)" << endl;
        }
        if ((a < b) && (n > 0))
        {
            correct = true;
        }
    }
    Tabulator* tabulator = new Tabulator(a, b, n);

    //Интерфейс пользователя в терминале
    do
    {
        cout << endl; //вывод: список действий - главное меню
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "-Action list:" << endl;
        cout << "3. Tabulate the function" << endl;//3. табулир функции там мы получаем значения. 
        cout << "2. Get data from tabulation." << endl;//2 гет дата это мы поулчаем интервал который у нас есть и колво точек табулирования.
        cout << "1. Set data for tabulation." << endl;
        cout << "0. Exit." << endl;
        cout << "-Perform the action: ";
        cin >> choice_1; //Выбор пользователя
        cout << endl;
        switch (choice_1) // проверка выбора пользователя
        {
        case 3: // Tabulate the function - вызов функции - табулировать функцию
        {
            Choose_Tabulate_function(*tabulator); //передаём наш объект, * - указатель на объект
            break;
        }

        case 2: // Get data from tabulation - вызов функции - вывод списка действий по получению данных
        {
            Choose_Get_Data(*tabulator);
            break;
        }

        case 1: // Set data for tabulation - вызов функции - вывод списка действий по вводу данных
        {
            Choose_Set_Data(*tabulator);
            break;
        }

        case 0: // Exit - Выход из меню и программы
        {
            exit = true;
            cout << "--Goodbye." << endl;
            break;
        }

        default: // Если число-действие не найдено в списке
        {
            cout << "--Unknown command." << endl;
            break;
        }
        }

    } while (exit != true);
    delete tabulator;
    return 0;
}

void Choose_Tabulate_function(Tabulator& tabulator)
{
    int16_t choice_2 = 1;
    bool exit = false;
    do
    {
        cout << "---------------------------" << endl; //список подменю
        cout << endl;
        cout << "-Tabulate the function:" << endl; //3. табулир функции там мы получаем значения.  
        //В табулир функци у нас есть динамические массивы которые векторы. В самом начале очищаем их чтобы занести новые.
        cout << "2. Calculate the value of the tabulated function at the point x and compare this value with the value of the original function" << endl;
        cout << "1. Tabulate the function" << endl;
        cout << "0. Return back" << endl;
        cout << "Perform the action: ";
        cin >> choice_2; //Выбор пользователя
        cout << endl;
        switch (choice_2)
        {
        case 2: // Tabulate the function - Табулирование функции с записанными параметрами
        {
            float x; //У нас есть х это  интервал 
            bool correct = false;
            while (correct == false)
            {
                cout << "--Enter the x value" << endl;
                cin >> x;
                correct = tabulator.linearly_interpolate_and_compare(x);
            };
            break;
        }

        case 1: // Tabulate the function - Табулирование функции с записанными параметрами
        {
            tabulator.tabulate_the_function();
            break;
        }

        case 0: // Return back - Выход из подменю
        {
            exit = true;
            break;
        }
        default: // Если число-действие не найдено в списке
        {
            cout << "--Unknown command." << endl;
            break;
        }
        }
    } while (exit != true);
}

void Choose_Get_Data(Tabulator& tabulator)//Крч ввели данные дефолтные значения. 
//Потом интерфейс есть где мы дату устанавливаем.Мы чисто можем поменять значение даты.

{

    int16_t choice_2 = 1;
    bool exit = false;
    do
    {
        cout << "---------------------------" << endl; //список подменю
        cout << endl;
        cout << "-Get data from tabulation:" << endl; //2 гет дата это мы поулчаем интервал который у нас есть и колво точек табулирования
        // cout << "3. Get the function" << endl;
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
        {
            exit = true;
            break;
        }
        default: // Если число-действие не найдено в списке
        {
            cout << "--Unknown command." << endl;
            break;
        }
        }
    } while (exit != true);
}

void Choose_Set_Data(Tabulator& tabulator)
{
    int16_t choice_2 = 1;
    bool exit = false;
    do
    {
        cout << "---------------------------" << endl; //список подменю
        cout << endl;
        cout << "-Set data for tabulation:" << endl;
        cout << "2. Change the number of tabulation points" << endl;
        cout << "1. Change the tabulation interval" << endl;
        cout << "0. Return back" << endl;
        cout << "Perform the action: ";
        cin >> choice_2; //Выбор пользователя
        cout << endl;
        switch (choice_2)
        {
        case 2: // Change the number of tabulation points - изменение значения кол-ва точек табулирования
        {
            int n;
            bool correct = false;
            while (correct == false)
            {
                cout << "--Enter the number of tabulation points" << endl;
                cin >> n;
                correct = tabulator.set_number_of_tabulation(n);
            };
            break;
        }
        case 1: // Change the tabulation interval - изменение значений интервала
        {
            float a, b;
            bool correct = false;
            while (correct == false)
            {
                cout << "--Enter the values of the tab interval [a,b]" << endl;
                cin >> a;
                cin >> b;
                correct = tabulator.set_interval_of_tabulation(a, b);
            };
            break;
        }

        case 0: // Return back - Выход из подменю
        {
            exit = true;
            break;
        }

        default: // Если число-действие не найдено в списке
        {
            cout << "--Unknown command." << endl;
            break;
        }
        }

    } while (exit != true);
}