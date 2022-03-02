#include<iostream>
#include<string>
using namespace std;
void main()
{
    system("color 0B");
    setlocale(LC_ALL, "Russian");
    const int size = 7;
    string Tovari[size] = { "сыр советский","колбаса","сыр президентский","молоко","хлеб", "упаковка яиц","сырок александров"};
    double Price[size] = { 349,149,449,80,40,70,60};
    int count[size] = { 10,10,10,10,10,10,10};
    double Sum[size] = { 0 };
    for (int i = 0; i < size; i++)
        cout << i + 1 << "\t" << Tovari[i] << "\t" << Price[i] << "\tрублей\t" << count[i] << "штук\n";
    cout << "Выберите товар из списка:\n";
    int n = 0;
    double balance = 2000;
    m: 
    for (int j = 1; j <= 3; j++)
    {
        cout << "Покуnатель " << j << "\n";
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << "\t" << Tovari[i] << "\t" << Price[i] << "\tрубей\t" << "штук\t";
            cin >> n;
           
           
            if (count[i] < n)  //если кол-во меньше чем есть на складе, введите меньшее кол-во
            {
                cout << "Error" << "В наличии \t" << count[i] << "\n" << "Введите количество\t\t";
                cin >> n;
                count[i] = count[i] - n;
                Sum[i] = Price[i] * n;
                continue;
            }
            count[i] = count[i] - n;
            Sum[i] = Price[i] * n;
        }
        for (int i = 0; i < size; i++)
        {
            sum += Sum[i];
        }
        if (sum > balance) { cout << "Сумма превышает ваш баланс \n"; goto m;}
        cout << sum;
        if (sum >= 1000)
        {
            double pay = sum - sum / 100 * 15;
            double ostatok = balance - pay;
            cout << " У Вас 15% скидка!!!\n";
            cout << "Вы должны заплатить - " << pay << "рублей\n";
            cout << "Остаток " << ostatok << "рублей\n";
        }
        else
        {
            cout << "У Вас нет скидки!!!\n";
            cout << "Вы должны заплатить - " << sum << "рублей\n";
            cout << "Остаток " << balance - sum << "рублей\n";
        }
        for (int i = 0; i < size; i++)
            cout << i + 1 << "\t" << Tovari[i] << "\t" << Price[i] << "\tрублей\t" << count[i] << "штук\n";
    }
}