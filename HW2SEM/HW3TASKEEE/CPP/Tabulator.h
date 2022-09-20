#pragma once /* Защита от двойного подключения заголовочного файла */

using namespace std;
// Интерфейс класса (объявляем тут короче)
class Tabulator
{
public:
    Tabulator(float, float, int); // Конструктор класса Tabulator
    ~Tabulator() {};               //Деструктор

    bool set_interval_of_tabulation(float, float); // Установка интервала табулирования
    void get_interval_of_tabulation();             // Получение интервала табулирования

    bool set_number_of_tabulation(int); // Установка кол-ва точек табулирования
    void get_number_of_tabulation();    // Получение кол-ва точек табулирования

    void tabulate_the_function(); //Табулирование функции с записанными параметрами
    bool linearly_interpolate_and_compare(float); // Линейное интерполирование и сравнивание со значением исходной функции

private:
    float interval_of_tabulation_a; // Начало интервала табулирования
    float interval_of_tabulation_b; // Конец интервала табулирования
    float number_of_tabulation_n;   // Кол-во точек табулирования
};
//В h файле заглавном здесь методы которые имеет этот класс. И аргументы приватные чтобы работать можно было ток в классе. 