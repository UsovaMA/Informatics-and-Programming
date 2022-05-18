#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Vector
{
private:
    double X = 0;
    double Y = 0;
    double Z = 0;
public:
    Vector(const double& x, const double& y, const double& z) {//Функция для присваивания значений точек вектора
        X = x;
        Y = y;
        Z = z;
    }
    double GetLength() { // Функция для вычисления длины вектора
        return sqrt(X * X + Y * Y + Z * Z);
    }

    friend Vector operator +(Vector& l, Vector& r) {
        return Vector(l.X + r.X, l.Y + r.Y, l.Z + r.Z);
    }
    friend Vector operator -(Vector& l, Vector& r) {// переопределям операции с векторами
        return Vector(l.X - r.X, l.Y - r.Y, l.Z - r.Z);
    }
    friend double operator *(Vector& l, Vector& r)
    {
        return (l.X * r.X + l.Y * r.Y + l.Z * r.Z);
    }
    friend Vector operator *(Vector& l, double val)
    {
        return Vector(l.X * val, l.Y * val, l.Z * val);
    }

    friend const bool operator== (Vector& v1, Vector& v2)
    {
        return v1.GetLength() == v2.GetLength();
    }
    friend const bool operator!= (Vector& v1, Vector& v2)
    {
        return v1.GetLength() != v2.GetLength();
    }
    friend const bool operator> (Vector& v1, Vector& v2)
    {
        return v1.GetLength() > v2.GetLength();
    }
    friend const bool operator< (Vector& v1, Vector& v2)
    {
        return v1.GetLength() < v2.GetLength();
    }

    void compare(Vector& one, Vector& two) {// функция для сравнения двух векторов
        if (one > two)
            cout << one << " > " << two << endl;
        else if (one < two)
            cout << one << " < " << two << endl;
        else
            cout << one << " = " << two << endl;
    }
    friend ostream& operator<< (ostream& out, const Vector& vec) // переопределяем формат вывода для векторов
    {
        out << "X=" << vec.X << " Y=" << vec.Y << " Z=" << vec.Z;
        return out;
    }
};

int main(int argc, char* argv[])
{
    Vector v1 = Vector(1, 2, 3);
    Vector v2 = Vector(4, 5, 6);
    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    double m = v1 * v2;
    cout << "m=" << m << endl << "v3: " << v3 << endl << "v4: " << v4 << endl;

    v3.compare(v3, v4);

    v3 = v3 * 100;
    cout << v3;
    return 0;
}