#include <iostream> //����� � �������
#include <fstream>  // ������ � �������
#include <cmath>    // ����������
#include <vector>   //������������ �������
#include "Tabulator.h"
using namespace std;

// ���������� ������ (� ��� ��������� � ������� ������������)
Tabulator::Tabulator(float a = 0, float b = 1, int n = 1) //���������� ������������ � ���������� ����������
{
    // ����� �� ������������ ����� set, � ����� �������� � interval_of_tabulation_a...
    // ��� ��� �������� ������ ��������, �� ������ �������� ��������� ������� ����, ��� � �� �����..
    // ������ ��� ������� ����� ������� ��� get/set, �� ������� ������������ � ������������.
    set_interval_of_tabulation(a, b);
    set_number_of_tabulation(n);
    //������ ������ �������� ��� �������� �������  �� ���� �� �� ������ ������� � ������� ����� ������ ��� ��� ������.�������� ��� ������� ����� �� ����� ������� ������� ��������.
};

//��������� �������� ��������� ������������� � ���������
bool Tabulator::set_interval_of_tabulation(float a = 0, float b = 1)//�� ���������� ��� ������ ���������� ��� ���.���� ��� �������� � �������� �������� ��� ��� ���� ���������� �������� 0.1 ��� ����
//� � ����������  ��� ��� ������������ �� ������� �������� � ��������. ���������� �������� � ���� n ��� �++ ������ 0.
//� ��������� �������� ��� �������� ������� ����� � ����� ���������� ������ ��� ��� �����. ��� ���� � ���� ��������. 
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

//��������� �������� ��������� ������������� � ���������
void Tabulator::get_interval_of_tabulation()
{
    cout << "--The tabulation interval is ";
    cout << "[ " << interval_of_tabulation_a << " , " << interval_of_tabulation_b << " ]" << endl;
};

//��������� � ��������� ���������� ����� �������������
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
vector<float> x_points; //������������ ������ �������� ����� �������������
vector<float> y_values; //������������ ������ �������� ������� �������������

void Tabulator::tabulate_the_function()
{
    x_points.clear();
    y_values.clear();
    float h = (interval_of_tabulation_b - interval_of_tabulation_a) / (number_of_tabulation_n - 1);
    float x = interval_of_tabulation_a; //� ��� ���� � ���  �������� � 
    float y;// ����� y ������� ����� �������������. 
    int count = 0;
    cout << "--The tabulation interval is ";
    cout << "[ " << interval_of_tabulation_a << " , " << interval_of_tabulation_b << " ]" << endl;
    cout << "--The number of tabulation points is " << number_of_tabulation_n << endl;
    cout << "--Tabulation: sin(x)" << endl;
    while (x <= interval_of_tabulation_b)//� ��� �������� ����
    //����������  ������ ��������. ����������� ������� � ������ . 

    {
        x_points.push_back(x); //������ � ������ �������� x
        y = sin(x);
        y_values.push_back(y); //������ � ������ �������� y
        //������������ �������� ��� y � ���������� �������� � y ����.
        cout << ++count << ". x= " << x << " Y(x)= " << y << endl;//� ������� �� ����� � ���������� � � ��� ������� � ��� ���������.
        x += h;
    }
};

bool Tabulator::linearly_interpolate_and_compare(float x)//������ ���� ���������� ��� �� ������ �������� ������������. � ���������� 
//�� ������ ���� �������� �������� x.

{
    int size_x_points = x_points.size();
    int j = 2; // x0 (i) < x <x2 (j)
    float y_tabe, x1, x2, y1, y2, y;
    if ((interval_of_tabulation_a < x) && (x < interval_of_tabulation_b))//���� ������� ��� ����� ������ ���� ������ � � ������ � � ��������� � ���� ������ ���������.
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