#include <cmath>
#include <iostream>
using namespace std;
//часть вычесления метода квадратичной интерполяции
double fun(double x)
{
    return (0.1 * x * x * x - 2 * x * x + 10 * sqrt(x));
}
// метод для вычесления квадратичной интерполяции
pair<double, double> mkv(double h, double x1, double e)
{
    double xm = x1;
    do {
        x1 = xm;

        double f0 = fun(x1 - h);
        double f1 = fun(x1);
        double f2 = fun(x1 + h);

        double c = (f0 - 2 * f1 + f2) / (2 * h * h);
        double b = ((-1) * f0 * (2 * x1 + h) + 4 * f1 * x1 - f2 * (2 * x1 - h)) / (2 * h * h);

        xm = (-1) * b / (2 * c);
    } while ((xm - x1) < e);

    return make_pair<>(xm, fun(xm));
}
//запуск программы

int
main()
{
    double step = 1, accuracy = 0.10, x = 1;
    auto res = mkv(step, x, accuracy);
    std::cout << "f(" << res.first << ") = " << res.second << endl;
    return 0;
}
//step--> шаги
//accuracy--> Точность
//x это начальное значение