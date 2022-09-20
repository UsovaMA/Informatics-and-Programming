//Преобразовать строки двумерного массива в столбцы.Например было : 
// Класс будет содержать два метода: один заполнит массив значениями, второй произведет замену значений строк на значения столбцов.
#include <iostream>
using namespace std;

class Matrix {

private:
    int** arr1;
    int** arr2;
    int rows, calls;

public:

    void Fill_array(int rows_value, int calls_value) // инициализация 
    {
        rows = rows_value; // копирование 
        calls = calls_value;// копирование 
        arr1 = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            arr1[i] = new int[calls];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < calls; j++)
            {
                arr1[i][j] = 10 + rand() % +50;
                cout << arr1[i][j] << "\t";
            }
            cout << endl;
        }
    }
        void Change_rows_with_calls()
        {
            arr2 = new int* [calls];
            for (int i = 0; i < calls; i++)
            {
                arr2[i] = new int[rows];
            }
            cout << endl << endl;

            for (int i = 0; i < calls; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    arr2[i][j] = arr1[j][i];
                    cout << arr2[i][j] << "\t";
                }
                cout << endl;
            }
        }
    ~Matrix()
    {
        for (int i = 0; i < calls; i++)
        {
            delete[]arr2[i];
        }
        cout << "Destrucor is here for 1 matrix" << endl;
        delete[]arr2;
        for (int i = 0; i < rows; i++)
        {
            delete[]arr1[i];
        }
        cout << "Destructor is here for 2 matrix" << endl;
        delete[]arr1;
    }
};
int main()
{
    Matrix first;
    first.Fill_array(2, 5);
    first.Change_rows_with_calls();
}