#include <iostream>
#include <cmath>
#include "locale.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    int x1 = 0, y1 = 0, r1 = 0; //круг 1
    int x2 = 0, y2 = 0, r2 = 0; //круг 2
    int d = 0; //расстояние от центра первого круга до центра второго круга

    cout << "введите x1, y1, r1 = " << endl;
    cin >> x1 >> y1 >> r1;

    cout << "введите x2, y2, r2 = " << endl;
    cin >> x2 >> y2 >> r2;

    d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // рассчитываем расстояние от центра первого круга до центра второго круга

    if (d > (r1 + r2))
    {
        cout << "Круги не соприкасаются" << endl;
    }
    else if (d == (r1 + r2))
    {
        cout << "Круги соприкасаются" << endl;
    }
    else if ((d > (r1 - r2)) && (d < (r1 + r2)))
    {
        cout << "Круги пересекаются" << endl;
    }
    else // (r1 < d < r2) - единственный оставшийся исход
    {
        cout << "Круг вписан в окружность" << endl;
    }
    return 0;
}