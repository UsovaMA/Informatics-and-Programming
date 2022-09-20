#include <iostream>
#include <vector>
using namespace std;

int main()
{
    system("color 0B");
    setlocale(LC_CTYPE, "rus");
    int Kmest = 0, Kpretendentov = 0, minScore = 1;
    cout << "Введите к-во мест и к-во претендентов на это место" << endl;
    cin >> Kmest >> Kpretendentov;
    vector <int> a(Kpretendentov * 4); // массив поступающих
    vector <int> score; // массив баллов за 3 экзамена 
    vector <int> stud; // массив поступивших: номер поступающего, потом его к-во баллов 
    //считывание
    for (int i = 0, temp = 0; i < (Kpretendentov * 4); i++) //цикл помещает сумму баллов каждго поступившего в отдельный массив
    {
        cin >> a[i];
    }
    //обработка
    cout << endl << endl;
    for (int i = 1, pretscore = 0; i <= a.size(); i++)
    {
        if ((i % 4) != 0)
        {
            pretscore += a[i];
        }
        else if ((i % 4) == 0)
        {
            score.push_back(i / 4); //помещаем индекс человечка
            score.push_back(pretscore); //и его баллы
            pretscore = 0;
        }
    }
    for (int i = 0, maxIndex = 0; i < Kmest; i++) // цикл находит на все места людей с максимальными баллами 
    {
        maxIndex = 0;
        for (int j = 1; j < score.size(); j++)
        {
            if (score[maxIndex] < score[j])
            {
                maxIndex = j;
            }
        }
        stud.push_back((maxIndex + 1) / 2); // номер студента мы перемещаем в другой массив
        stud.push_back(score[maxIndex]); // и его баллы тоже
        score[maxIndex] = 0;
    }
    for (int i = 0; i < stud.size(); i++) //Средний балл
    {
        if ((i % 2) != 0)
        {
            if (stud[minScore] > stud[i])
            {
                minScore = i;
            }
        }
    }
    //вывод
    cout << "Проходной балл : - " << stud[minScore] << endl;
    cout << "Список поступивших: ";
    for (int i = 0; i < stud.size(); i++)  //список поступивших
    {
        if ((i % 2) == 0) //выводим только номера студентов, без их баллов
        {
            cout << stud[i] << " ";
        }
    }
    return 0;
}