#include <iostream>
using namespace std;
class Time
{
private: 
    int day, // день
        month, // месяц
        year; // год
public: // спецификатор доступа public
    Time(int date_day, int date_month, int date_year) // конструктор класса
    {
        setDate(date_day, date_month, date_year); // вызов функции установки даты
    }
    void message() // функция (метод класса) выводящая сообщение на экран
    {
        cout << "\nData \n";
    }
    void setDate(int date_day, int date_month, int date_year) // установка даты в формате дд.мм.гг
    {
        day = date_day; // инициализация день
        month = date_month; // инициализация месяц
        year = date_year; // инициализация год
    }
    void getDate() // отобразить текущую дату
    {
        cout << "date: " << day << "." << month << "." << year << endl;
    }
}; // конец объявления класса Time

int main(int argc, char* argv[])
{
 Time objTime(20, 10, 2003); // объявление объекта и инициализация элементов данных
    objTime.message(); // вызов функции message
    objTime.getDate(); // отобразить дату
    system("pause");
    return 0;
}