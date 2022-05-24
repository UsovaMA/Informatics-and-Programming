#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Izmerenie {
protected:
    int temperature;
    int pressure;
    int day;
    int month;
    int year;
    int hours;
public:
    Izmerenie() { ; }
    Izmerenie(int Day, int Month, int Year, int Hours, int Temperature, int Pressure) {
        day = Day;
        month = Month;
        year = Year;
        hours = Hours;
        temperature = Temperature;
        pressure = Pressure;
    }
    Izmerenie(int Day, int Month, int Year, int Hours) {
        day = Day;
        month = Month;
        year = Year;
        hours = Hours;
    }
    //3 конструктора создали

    int getTemperature() {
        return temperature;
    }

    int getPressure() {
        return pressure;
    }

    const bool& operator== (Izmerenie& iz2)
    {
        return *new bool(this->day == iz2.day && this->month == iz2.month && this->year == iz2.year && this->hours == iz2.hours);
    }
    const bool& operator!= (Izmerenie& iz2)
    {
        return *new bool(this->day != iz2.day && this->month != iz2.month && this->year != iz2.year && this->hours != iz2.hours);
    }
    const void operator= (Izmerenie& iz2)
    {
        this->day = iz2.day;
        this->month = iz2.month;
        this->year = iz2.year;
        this->hours = iz2.hours;
        this->temperature = iz2.temperature;
        this->pressure = iz2.pressure;

    }

    friend ostream& operator<< (ostream& out, Izmerenie& iz)
    {
        out << iz.day << "-" << iz.month << "-" << iz.year << " в " << iz.hours << " часов " << iz.temperature << "°C " << iz.pressure << "мм рт. ст.";
        return out;
    }

};

class Thermometer : public Izmerenie {
protected:

    int SIZE = 0;
    //vector<Izmerenie> his;
public:
    Izmerenie history[8760];
    void addizmerenie(int Day, int Month, int Year, int Hours, int Temperature, int Pressure) {
        Izmerenie a(Day, Month, Year, Hours, Temperature, Pressure);
        bool check = true;
        if (SIZE == 0) {
            history[SIZE] = a;
            ++SIZE;
        }
        else {
            for (int i = 0; i <= SIZE - 1; i++) {
                if ((a == history[i])) {
                    check = false;
                    break;
                }
                else {
                    check = true;
                }
            }
            if (check == true) {
                history[SIZE] = a;
                ++SIZE;
            }
            else
            {
                cout << "Ошибка, измерение уже присутствует" << endl;
            }
        }

    }
   
    void middleTempAndPress() {
        float sredTemp = 0;
        float sredPress = 0;
        for (int i = 0; i <= SIZE - 1; i++) {
            sredTemp += history[i].getTemperature();
            sredPress += history[i].getPressure();
        }
        cout << "Средняя температура: " << sredTemp / (SIZE) << endl;
        cout << "Среднее давление: " << sredPress / (SIZE) << endl;
    }

};




int main()
{
    setlocale(LC_ALL, "Russian");
    Thermometer tm;
    tm.addizmerenie(25, 8, 2020, 5, 30, 145);
    cout << tm.history[0] << endl;
    tm.addizmerenie(1, 4, 2021, 7, 40, 90);
    cout << tm.history[1] << endl;
    tm.addizmerenie(1, 4, 2021, 7, 40, 90);
    tm.addizmerenie(30, 3, 2022, 9, 23, 110);
    cout << tm.history[2] << endl;
    tm.middleTempAndPress();
    return 0;
}




//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//class Thermometer {
//protected:
//    int day;
//    int month;
//    int year;
//    int hours;
//    int temperature;
//    int history[8760][5] = { 14,8,20,04,0 }; //Переменная в которой будут храниться все измерения. ДМожно сделать 8760 измерений в каждом из которых будет 5 параметров
//                                                                           таких как день, месяц, год, время, температура
//    int SIZE = 1;
//public:
//
//    void SaveToHistory(int Nday, int Nmonth, int Nyear, int Nhours, int temperature) { //Сохраняет данные в историю (History)
//        int current = Nday + Nmonth * 31 + Nyear * 365; //Строчки 19-20 считаются для того, чтобы узнать какая из дат больше
//        int start = history[0][0] + history[0][1] * 31 + history[0][2] * 365;
//        if (current >= start && current <= start + 365)
//        {
//
//            for (int i = 0; i <= SIZE; i++) {
//                if (history[i][0] == Nday && history[i][1] == Nmonth && history[i][2] == Nyear && history[i][3] == Nhours) 
//                { //24-33 проверяется есть ли запись на выбранный день на определëнные часы. Если есть, то данные перезаписываются. 
//                    Если нет, то перекидывается на 35-41 и добавляются новые значения в конец. Переменная SIZE указывает сколько значений было внесено
//
//                    history[i][0] = Nday;
//                    history[i][1] = Nmonth;
//                    history[i][2] = Nyear;
//                    history[i][3] = Nhours;
//                    history[i][4] = temperature;
//                    SIZE -= 1;
//                    break;
//                }
//                else {
//                    history[SIZE][0] = Nday;
//                    history[SIZE][1] = Nmonth;
//                    history[SIZE][2] = Nyear;
//                    history[SIZE][3] = Nhours;
//                    history[SIZE][4] = temperature;
//                    break;
//                }
//            }
//            SIZE += 1;
//        }
//        else {
//            cout << "Couldn't add the dimension. Going beyond the date" << endl;
//        }
//    }
//    void GetFromHistory(int Nday, int Nmonth, int Nyear, int Nhours) { //Выводит измерение из истории за определённый час  
//        Выбирается из истории наблюдений конкретное наблюдение, точнее температура наблюдения.
//        bool val = false;
//        for (int i = 0; i < SIZE; i++) {
//            if (history[i][0] == Nday && history[i][1] == Nmonth && history[i][2] == Nyear && history[i][3] == Nhours) {
//                val = true;
//                cout << history[i][4] << endl;
//            }
//        }
//        if (val == false) {
//            cout << "Can't find the value " << endl;
//        }
//    }
//    void startDateTime() { //Выводит стартовое время начала измерений  
//        Первая функция выводит время начального наблюдения 65-58
//         Вторая записывает наблюдения за определённый день в файл 70-83
//        cout << "Start date: " << history[0][0] << "." << history[0][1] << "." << history[0][2] << " at " << history[0][3] << " hours" << endl;
//    }
//    void GetFromHistoryToFile(int Nday, int Nmonth, int Nyear) { //Записывает в файл все измерения сделанные за определённый день
//        ofstream observation;
//        observation.open("observations.txt");
//        bool val = false;
//        for (int i = 0; i < SIZE; i++) {
//            if (history[i][0] == Nday && history[i][1] == Nmonth && history[i][2] == Nyear) {
//                val = true;
//                observation << history[0][0] << "." << history[i][1] << "." << history[i][2] << " at " << history[i][3] << " hours: " << history[i][4] << endl;
//            }
//        }
//        if (val == false) {
//            observation << "Can't find the value " << endl;
//        }
//    }
//    void AverageTemperature(int Nday, int Nmonth, int Nyear) { // Средняя температура всех измерений за определённый день
//        bool val = false;
//        int summ = 0;
//        int num = 0;
//        for (int i = 0; i < SIZE; i++) {
//            if (history[i][0] == Nday && history[i][1] == Nmonth && history[i][2] == Nyear) {
//                val = true;
//                summ += history[i][4];
//                num += 1;
//            }
//        }
//        if (val == false) {
//            cout << "Can't find the value " << endl;
//        }
//        else
//            cout << "Average:" << summ / num << endl;
//    }
//    void AverageTemperature(int Nmonth, int Nyear) { // Средняя температура всех измерений за определённый месяц
//        bool val = false;
//        int summ = 0;
//        int num = 0;
//        for (int i = 1; i < SIZE; i++) {
//            if (history[i][1] == Nmonth && history[i][2] == Nyear) {
//                val = true;
//                summ += history[i][4];
//                num += 1;
//            }
//        }
//        if (val == false) {
//            cout << "Can't find the value " << endl;
//        }
//        else
//            cout << "Average:" << summ / num << endl;
//    }
//    void AverageTemperature() {// Средняя температура всех измерений за всю историю измерений
//        bool val = false;
//        int summ = 0;
//        int num = 0;
//        for (int i = 1; i < SIZE; i++) {
//
//            val = true;
//            summ += history[i][4];
//            num += 1;
//
//        }
//        if (val == false) {
//            cout << "Can't find the value " << endl;
//        }
//        else
//            cout << "Average:" << summ / num << endl;
//    }
//    void AverageTemperatureAtNight(int Nmonth, int Nyear) { //Средняя температура ночью за выбранный месяц
//        Складываем температуру (summ) и делим на колличество переменных, которые мы сложили (num)
//        Это средняя температура за конкретный месяц ночью
//         По этому там есть ограничения и берутся измерения, которые сделаны с полуночи до 6 утра
//        bool val = false;
//        int summ = 0;
//        int num = 0;
//        for (int i = 1; i < SIZE; i++) {
//            if (history[i][1] == Nmonth && history[i][2] == Nyear && history[i][3] >= 0 && history[i][3] <= 6) {
//                val = true;
//                summ += history[i][4];
//                num += 1;
//            }
//        }
//        if (val == false) {
//            cout << "Can't find the value " << endl;
//        }
//        else
//            cout << "Average at night:" << summ / num << endl;
//    }
//    void AverageTemperatureAtDay(int Nmonth, int Nyear) { //Средняя температура днём за выбранный месяц
//        bool val = false;
//        int summ = 0;
//        int num = 0;
//        for (int i = 1; i < SIZE; i++) {
//            if (history[i][1] == Nmonth && history[i][2] == Nyear && history[i][3] >= 12 && history[i][3] <= 18) {
//                val = true;
//                summ += history[i][4];
//                num += 1;
//            }
//        }
//        if (val == false) {
//            cout << "Can't find the value " << endl;
//        }
//        else
//            cout << "Average at day:" << summ / num << endl;
//    }
//    void GetFromHistoryToFile() { //Записывает в файл всю историю измерений
//        ofstream observation;
//        observation.open("observations.txt");
//        bool val = false;
//        for (int i = 1; i < SIZE; i++) {
//
//            val = true;
//            observation << history[0][0] << "." << history[i][1] << "." << history[i][2] << " at " << history[i][3] << " hours: " << history[i][4] << endl;
//
//        }
//        if (val == false) {
//            observation << "Can't find the value " << endl;
//        }
//    }
//    void GetFromFile() { //Записывает в консоль из файла все измерения
//        ifstream observation; // ifstream для чтения и записи данных 
//        observation.open("observations.txt");
//        string buff;
//
//        cout << endl;
//        if (observation.is_open()) {
//            while (getline(observation, buff))
//                cout << buff << endl;
//        }
//
//
//
//    }
//};
//я использую void потому что мне не надо никакое значение возвращать.
//Вывод в консоль идëт в самой функции.
//Можно сделать int, возвращать число и потом в main прописывать через cout.
//
//
//
//int main()
//{
//
//    Thermometer tm;
//    tm.SaveToHistory(1, 1, 21, 4, 30);
//    tm.SaveToHistory(1, 1, 21, 5, 36);
//    tm.SaveToHistory(1, 1, 21, 6, 39);//Сохраняем температуру за определённый день и час (01.01.21 в 6 часов утра с температурой 39 градусов)
//    tm.SaveToHistory(1, 1, 21, 7, 40);
//
//    tm.SaveToHistory(1, 2, 21, 15, 50);
//    tm.SaveToHistory(1, 1, 22, 5, 60);
//
//    tm.GetFromHistory(1, 1, 21, 4);
//    tm.GetFromHistory(1, 1, 21, 5); //Вытаскиваем температуру за определённый день и час (01.01.21 в 5 часов утра)
//    tm.GetFromHistory(1, 2, 21, 4);
//    tm.GetFromHistory(1, 1, 22, 5);
//
//    tm.startDateTime(); //Выводит стартовое время
//
//    tm.GetFromHistoryToFile(1, 1, 21); //Записывает наблюдения за 01.01.21 число в файл
//
//    tm.AverageTemperature(1, 1, 21);
//    tm.AverageTemperature(1, 21); // Находит среднюю температуру
//    tm.AverageTemperature();
//
//    tm.AverageTemperatureAtNight(1, 21);
//    tm.AverageTemperatureAtDay(2, 21);
//
//    tm.GetFromHistoryToFile(); //Записывает в файл всю историю наблюдений
//
//    tm.GetFromFile(); //Из файла записывает всё в консоль
//
//
//    return 0;
//}