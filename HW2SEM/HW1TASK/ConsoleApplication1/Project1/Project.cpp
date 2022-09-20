#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Vector
{
protected:

public:
    double X, Y, Z;
    Vector(const double& x, const double& y, const double& z) {//Функция для присваивания значений точек вектора
        X = x;
        Y = y;
        Z = z;
    }
    double GetLength() { // Функция для вычисления длины вектора
        return sqrt(X * X + Y * Y + Z * Z);
    }

    Vector& operator +(const Vector& r) {
        return *new Vector(this->X + r.X, this->Y + r.Y, this->Z + r.Z);
    }
    Vector& operator -(const Vector& r) {// переопределям операции с векторами
        return *new Vector(this->X - r.X, this->Y - r.Y, this->Z - r.Z);
    }
    double& operator *(const Vector& r)
    {
        return *new double(this->X * r.X + this->Y * r.Y + this->Z * r.Z);
    }
    Vector& operator *(const double val)
    {
        return *new Vector(this->X * val, this->Y * val, this->Z * val);
    }

    const bool& operator== (Vector& v2)
    {
        return *new bool(this->GetLength() == v2.GetLength());
    }
    const bool& operator!= (Vector& v2)
    {
        return *new bool(this->GetLength() != v2.GetLength());
    }
    const bool& operator> (Vector& v2)
    {
        return *new bool(this->GetLength() > v2.GetLength());
    }
    const bool& operator< (Vector& v2)
    {
        return *new bool(this->GetLength() < v2.GetLength());
    }

    void compare(Vector& one, Vector& two) {// функция для сравнения двух векторов
        if (one > two)
            cout << one << " > " << two << endl;
        else if (one < two)
            cout << one << " < " << two << endl;
        else
            cout << one << " = " << two << endl;
    }
    friend ostream& operator<< (ostream& out, Vector& vec) // переопределяем формат вывода для векторов
    {
        out << "X=" << vec.X << " Y=" << vec.Y << " Z=" << vec.Z;
        return out;
        //cout << "X=" << vec.X << "Y=" << vec.Y << "Z=" << vec.Z; // можно и так но чет не заработало 
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
    cout << v3 << endl;

    if (v3 == v4)
        cout << "v3 == v4";
    else
        cout << "v3 != v4";

    return 0;
}