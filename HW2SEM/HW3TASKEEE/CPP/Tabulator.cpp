#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "Tabulator.h"

using namespace std;

//Установка и получение значений интервала табулирования
bool Tabulator::set_interval_of_tabulation(float a = 0, float b = 1)
{
    if (a < b)
    {
        interval_of_tabulation_a = a;
        interval_of_tabulation_b = b;
        return true;
    }
    else {
        cout << "--Incorrect values!" << endl;;
    } return false;
};

void Tabulator::get_interval_of_tabulation()
{
    cout << "--The tabulation interval is ";
    cout << "[ " << interval_of_tabulation_a << " , " << interval_of_tabulation_b << " ]" << endl;
};

//Установка и получение количество точек табулирования
void Tabulator::set_number_of_tabulation(int n)
{
    number_of_tabulation = n;
};

void Tabulator::get_number_of_tabulation()
{
    cout << "--The number of tabulation points is " << number_of_tabulation << endl;
};