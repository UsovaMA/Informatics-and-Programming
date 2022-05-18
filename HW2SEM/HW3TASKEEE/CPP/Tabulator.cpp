#include <iostream> //Вывод в консоль
#include <fstream>  // Работа с файлами
#include <cmath>    // Математика
#include <vector>   //Динамические массивы
#include "Tabulator.h"
using namespace std;

// Реализация класса (а тут реализуем с помощью наследования)
Tabulator::Tabulator(float a = 0, float b = 1, int n = 1) //Реализация конструктора с дефолтными значениями
{
    // Можно не использовать метод set, а сразу записать в interval_of_tabulation_a...
    // Так как делается лишняя проверка, но вскоре проверка полностью перейдёт сюда, там её не будет..
    // Вообще при наличии таких методов как get/set, их следует использовать в конструкторе.
    set_interval_of_tabulation(a, b);
    set_number_of_tabulation(n);
    //Должны ввести значения для создания объекта  по идее мы их должны вынести в сетдата чтобы именно там это делать.Возможно это сделать можно но нужно сделать возврат значения.
};

//Установка значений интервала табулирования с проверкой
bool Tabulator::set_interval_of_tabulation(float a = 0, float b = 1)//Мы определяем тип данных возвращает или нет.Если сет интервал я поставил значение что оно булл возвращает значение 0.1 тру фолс
//и в табуляторе  спп это реализованно мы создаем значение и проверку. Дефолттное значение у инта n сам с++ ставит 0.
//В коментаях написано что проверку вынести нужно в класс табулятора потому что тут пипец. Тут хоть и есть проверка. 
{
    if (a < b)
    {
        interval_of_tabulation_a = a;
        interval_of_tabulation_b = b;
        return true;
    }
    else
    {
        cout << "--Incorrect values! [a < b]" << endl;
        return false;
    }
};

//Установка значений интервала табулирования с проверкой
void Tabulator::get_interval_of_tabulation()
{
    cout << "--The tabulation interval is ";
    cout << "[ " << interval_of_tabulation_a << " , " << interval_of_tabulation_b << " ]" << endl;
};

//Установка и получение количество точек табулирования
bool Tabulator::set_number_of_tabulation(int n = 1)
{
    if (n > 0)
    {
        number_of_tabulation_n = n;
        return true;
    }
    else
    {
        cout << "--Incorrect values! [n > 0]" << endl;
        return false;
    }
};

void Tabulator::get_number_of_tabulation()
{
    cout << "--The number of tabulation points is " << number_of_tabulation_n << endl;
};

#define PI 3.14159265
vector<float> x_points; //Динамический массив значений точек табулирования
vector<float> y_values; //Динамический массив значений функции табулирования

void Tabulator::tabulate_the_function()
{
    x_points.clear();
    y_values.clear();
    float h = (interval_of_tabulation_b - interval_of_tabulation_a) / (number_of_tabulation_n - 1);
    float x = interval_of_tabulation_a; //У нас есть х это  интервал а 
    float y;// флоат y который будет расчитываться. 
    int count = 0;
    cout << "--The tabulation interval is ";
    cout << "[ " << interval_of_tabulation_a << " , " << interval_of_tabulation_b << " ]" << endl;
    cout << "--The number of tabulation points is " << number_of_tabulation_n << endl;
    cout << "--Tabulation: sin(x)" << endl;
    while (x <= interval_of_tabulation_b)//У нас работает вайл
    //Записываем  массив значения. Расчитываем значени х поинтс . 

    {
        x_points.push_back(x); //запись в массив значение x
        y = sin(x);
        y_values.push_back(y); //запись в массив значение y
        //рассчитываем значения для y и записываем значения в y виле.
        cout << ++count << ". x= " << x << " Y(x)= " << y << endl;//И выводим на экран и прибавляем к х шаг который у нас получился.
        x += h;
    }
};

bool Tabulator::linearly_interpolate_and_compare(float x)//Дальше булл табулейтор это мы делаем линейную интерполяцию. И сравниваем 
//Мы должны туда перенсти значения x.

{
    int size_x_points = x_points.size();
    int j = 2; // x0 (i) < x <x2 (j)
    float y_tabe, x1, x2, y1, y2, y;
    if ((interval_of_tabulation_a < x) && (x < interval_of_tabulation_b))//Есть условие что число должно быть больше а и меньше б и находится в этих предел значениях.
    {
        for (int i = 0; i < size_x_points - 2; i++)
        {
            if ((x_points[i] < x) && (x < x_points[j]))
            {
                x1 = x_points[i];
                x2 = x_points[j];
                y1 = y_values[i];
                y2 = y_values[j];
                y_tabe = y2 + ((y1 - y2) / (x1 - x2)) * (x - x2);
                y = sin(x);
                cout << "---The value of the tabulated function: " << y_tabe << endl;
                cout << "---The value of the original function: " << y << endl;
                if (y_tabe < y)
                {
                    cout << "---The value of the original function is greater" << endl;
                }
                else if (y_tabe > y)
                {
                    cout << "---The value of the tabulated function is greater" << endl;
                }
                return true;
            }
            ++j;
        }
    }
    else
    {
        cout << "---The x value is not in interval [a,b]" << endl;
        return false;
    }
    cout << "---There is nothing to tabulate here..." << endl;
    return true;
};