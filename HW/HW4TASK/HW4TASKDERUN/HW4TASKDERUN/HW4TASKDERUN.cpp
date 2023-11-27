#include <iostream>
#include <string>
using namespace std;
void main()
{
    system("color 0B");
    setlocale(LC_ALL, "Russian");
    const int size = 7;
    string Tovari[size] = { "сыр советский\t", "колбаса\t\t", "сыр президентский", "молоко\t\t", "хлеб\t\t", "упаковка яиц\t", "сырок александров" };
    double Price[size] = { 349, 149, 449, 80, 40, 70, 60 };
    int count[size] = { 10, 10, 10, 10, 10, 10, 10 };
    double Sum[size] = { 0 };
    int n = 0;              //колличество товаров
    double balance = 0; //баланс
    cout << "Введите колличество деняк, которые у вас есть: \n";
    cin >> balance;
    cout << "Мы имеем на складе:\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t" << Tovari[i] << "\t" << Price[i] << "\tрублей\t" << count[i] << " штук\n";
    }
    cout << "\nВыберите товар из списка:\n";


    for (int j = 1; j <= 3; j++)
    {
    m:
        cout << "Покуnатель " << j << "\n";
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << "\t" << Tovari[i] << "\t" << Price[i] << "\tрублей\t" << "штук\t";
            cin >> n;

            while (count[i] < n) //если кол-во меньше чем есть на складе, введите меньшее кол-во
            {
                cout << "Error" << "В наличии \t" << count[i] << "\n" << "Введите количество\t\t";
                cin >> n;
            }
            count[i] = count[i] - n;
            Sum[i] = Price[i] * n;
        }
        for (int i = 0; i < size; i++)
        {
            sum += Sum[i];
        }
        if (sum > balance) //если сумма превышает баланс, возвращаем все товары и набираем заново
        {
            for (int i = 0; i < size; i++)
            {
                count[i] = 10;
            }
            cout << "\nВаш баланс: " << balance << "\tСумма чека: " << sum << "\n";
            cout << "\nСумма превышает ваш баланс, выберите товары заново \n";
            goto m;
        }
        cout << sum;
        if (sum >= 1000)
        {
            double pay = sum - sum / 100 * 15;
            double ostatok = balance - pay;
            cout << " У Вас 15% скидка!!!\n";
            cout << "Вы должны заплатить - " << pay << "рублей\n";

            cout << "Остаток " << ostatok << "рублей\n";
            cout << "Следующий чек? (Нажмите любую клавишу) \n";
            getchar();
            getchar();
        }
        else
        {
            cout << "У Вас нет скидки!!!\n";
            cout << "Вы должны заплатить - " << sum << "рублей\n";
            cout << "Остаток " << balance - sum << "рублей\n";
            cout << "Следующий чек? (Нажмите любую клавишу) \n";
            getchar();
            getchar();
        }
        for (int i = 0; i < size; i++)
            cout << i + 1 << "\t" << Tovari[i] << "\t" << Price[i] << "\tрублей\t" << count[i] << "штук\n";
    }
}