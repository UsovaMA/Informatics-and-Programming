#pragma once /* Защита от двойного подключения заголовочного файла */

#include <iostream>

using namespace std;

#define PI 3.14159265

class Tabulator
{
public:
    bool set_interval_of_tabulation(float, float);
    void get_interval_of_tabulation();

    void set_number_of_tabulation(int);
    void get_number_of_tabulation();

    bool tabulate_the_function();

private:
    float interval_of_tabulation_a;
    float interval_of_tabulation_b;
    float number_of_tabulation;
}; 
