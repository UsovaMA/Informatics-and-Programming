#include <iostream>
#include <cmath>
using namespace std;
   
    bool prostoe1(int n) //Bool  верно или лож
    {
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)// Оператор % взятие остатка от деления целой величины на целую величину
            {
                return false;
            }
        return true;
    }
    bool prostoe2(int n, int i = 2)
    {
        if (i > sqrt(n))
        {
            return true;
        }
        return n % i ? prostoe2(n, ++i) : false;
    }
    int main()
    {
        system("color 0B");
        setlocale(LC_ALL, "Russian");
        cout << "Введите два числа через пробел: ";
        int a, b;
        cin >> a >> b;
        cout << "Проверка на простоту обычным алгоритмом числа a: ";
        if (prostoe1(a) == 1) 
        {
            cout << "простое.\n";
        }
        else if (prostoe1(a) == 0)
        {
            cout << "не простое.\n";
        }
        cout << "Проверка на простоту рекурсией числа b: ";
        if (prostoe2(b, 2) == 1) 
        {
            cout << "простое.\n";
        }
        else if (prostoe2(b, 2) == 0) 
        {
            cout << "не простое.\n";
        }
        return 0;
    }