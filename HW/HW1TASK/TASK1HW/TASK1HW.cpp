#include <iostream>
#include "locale.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    double w = 0, h = 0, d = 0; // ШхВхГ, только по-англечанске
    int Pdsp = 550, Pdvp = 800, Pwood = 1000; //Плотность материалов
    double mPolka = 0, mZstenka = 0, mBstenka = 0, mDver = 0, tPolka = 0.015, tZstenks = 0.005, tBstenka = 0.015, tDver = 0.010;

    //Получение данных
    cout << "Чтобы узнать массу вашего шкафа, нужно ввести ШхВхГ, а так же указать плотность материалов ДСП, ДВП, Дерева." << endl;
    cout << "Введите ширину от 80см до 120см = " << endl << "Введите высоту от 180см до 220см = " << endl << "Введите глубину от 50см до 90см = " << endl;
    cin >> w >> h >> d;

    if ((w > 120) || (w < 80) || (h > 220) || (h < 180) || (d > 90) || (d < 50)) //Проверка вводимых значений
    {
        cout << "К сожалению, наши фурри-сборщики не смогут сделать такой шкаф :(";
        return 0;
    }

    //Обработка данных
    mPolka = (w / 100) * (d / 100) * tPolka * Pdsp;     // Масса крышки (или полки), m = V * Pdsp;      V = w * d * t;      t = 15mm
    mZstenka = (w / 100) * (h / 100) * tZstenks * Pdvp; // Масса задней стенки,      m = V * Pdvp;      V = w * h * t;      t = 5mm
    mBstenka = (d / 100) * (w / 100) * tBstenka * Pdsp; // Масса боковой стенки,     m = V * Pdsp;      V = d * h * t;      t = 15mm
    mDver = (w / 100) * (d / 100) * tDver * Pwood;      // Масса дверей,             m = V * Pwood;     V = w * h * t;      t = 10mm
    if (h >= 200) // Количество полок (включая верхнюю и нижнюю крышки)
    {
        mPolka *= 7;
    }
    else
    {
        mPolka *= 6;
    }
    cout << "Масса вашего шкафа = " << mPolka + mZstenka + mBstenka + mDver;
    return 0;
}