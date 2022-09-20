#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include <vector>
class Sklad
{
protected:
	int ID = 1;
	string name;
	int cost;
	int discount;

	vector<int> IDs;     // Вектор (массив) с айди
	int rand_id_of_IDs;  // Рандомный индекс айди
	int rand_ID;         // Полученный айди по рандомному индексу
	int ID_from_IDs = 1; // ID-значение для заполнения вектора

	int Get_Random_ID()
	{
		if (IDs.size() < 1 && ID_from_IDs < 9999)
		{ //Наполнение вектора числами_ID, если в векторе осталось меньше 1 элемента, а id не превышает 9999
			for (int i = 1; i <= 1000; i++)
			{
				IDs.push_back(ID_from_IDs++); //Добавляем в конец новую пачку ID
			}
		};
		rand_id_of_IDs = 1 + rand() % (IDs.size() - 1); // получение индекса, от 1 до кол-ва элементов находящихся в векторе, чтобы по нему получить ID в векторе
		rand_ID = IDs[rand_id_of_IDs - 1];            //получаем ID; тут элементы начинаются с 0, а не с 1
		IDs.erase(IDs.begin() + rand_id_of_IDs);  // Удаляем из вектора, так как этот ID уже используется; тут элементы начинаются с 1
		return rand_ID;
	}

public:
	string Sklad[40][4];
	int SIZE = 1;

	void GetProducts(string name, int cost, int discount)
	{
		Sklad[SIZE][0] = to_string(Get_Random_ID());
		Sklad[SIZE][1] = name;
		Sklad[SIZE][2] = to_string(cost);
		Sklad[SIZE][3] = to_string(discount);
		SIZE += 1;
	}
};
class Kassa {
private:
	/*int ID;
	int name;
	int cost;
	int amount;
	float check[40][4];*/
	int products[50];
	Sklad sk;
	int SIZE = 0;
	int count = 0;
	float discount = 0;
	int k = 0;

public:
	Kassa(Sklad sk2) {
		sk = sk2;
	}
	void scan(int ID) {
		bool ch = false;
		for (int i = 0; i < sk.SIZE; i++) {
			if (!(sk.Sklad[i][0] == "")) {
				if (stoi(sk.Sklad[i][0]) == ID) {
					products[SIZE] = ID;
					ch = true;
					SIZE += 1;
					break;
				}
			}
		}
		if (ch == false)
			cout << "Не найден товар с штрихкодом: " << ID << endl;
	}
	void discription(int ID) { //описание товара со склада
		bool ch = false;
		for (int i = 0; i < sk.SIZE; i++) {
			if (!(sk.Sklad[i][0] == "")) {
				if (stoi(sk.Sklad[i][0]) == ID) {
					cout << setiosflags(ios::left) << "ID: " << sk.Sklad[i][0] << "\t Name \t" << setw(30) << sk.Sklad[i][1] << "\t Cost \t" << sk.Sklad[i][2] << "\t Discount " << sk.Sklad[i][3] + "%" << endl;
					ch = true;
					break;
				}
			}
		}
		if (ch == false)
			cout << "Не найден товар с штрихкодом: " << ID << endl;
	}
	void discription() { //описание товара со склада
		bool ch = false;
		for (int i = 0; i < sk.SIZE; i++) {
			if (!(sk.Sklad[i][0] == "")) {
				cout << setiosflags(ios::left) << "ID: " << sk.Sklad[i][0] << "\t Name \t" << setw(30) << sk.Sklad[i][1] << "\t Cost \t" << sk.Sklad[i][2] << "\t Discount " << sk.Sklad[i][3] + "%" << endl;
				ch = true;
				//break;

			}
		}
		if (ch == false)
			cout << "Товары не найдены" << endl;
	}
	void deleteScan(int ID) {
		for (int i = 0; i < 50; i++) {
			if (products[i] == ID) {
				products[i] = -99999;

				break;
			}
		}
	}
	void formation() {
		cout << endl << "ЧЕК:" << endl;
		for (int i = 0; i < 50; i++) {
			if (products[i] > 0 && products[i] <= 50) {
				for (int j = 0; j < sk.SIZE; j++) {
					if (!(sk.Sklad[j][0] == "") && stoi(sk.Sklad[j][0]) == products[i]) {
						cout << setiosflags(ios::left) << "ID: " << sk.Sklad[j][0] << "\t Name \t" << setw(30) << sk.Sklad[j][1] << "\t Cost \t" << sk.Sklad[j][2] << "\t Discount " << sk.Sklad[j][3] + "%" << endl;
						count += stoi(sk.Sklad[j][2]);
						discount += stoi(sk.Sklad[j][2]) * stoi(sk.Sklad[j][3]) / 100;
						k++;
						break;
					}
				}
			}
		}
		cout << "Итого скидка: " << discount * 100 / count << "%" << " Рублей съэкономлено: " << discount << endl;
		cout << "Итого к оплате: " << count - discount;
		memset(products, 0, sizeof(products)); // Все значения в массиве заменяет на ноль
		SIZE = 0;
		count = 0;
		discount = 0;
		k = 0;
	}
};




int main()
{
	system("color 0B");
	setlocale(LC_ALL, "Russian");
	Sklad sk;
	sk.GetProducts("сыр советский", 500, 10);
	sk.GetProducts("колбаса", 250, 5);
	sk.GetProducts("сыр президентский", 700, 8);
	sk.GetProducts("молоко", 70, 3);                 // Вбиваем продукты в класс Склад
	sk.GetProducts("хлеб", 40, 1);
	sk.GetProducts("упаковка яиц", 90, 15);
	sk.GetProducts("сырок александров", 60, 3);

	Kassa kasa(sk);
	//kasa.discription(3);
	//kasa.discription(2); // Описание товара с выбранным ID
	//kasa.discription(10);


	//kasa.scan(3);
	//kasa.scan(1); // Сканирование товара
	//kasa.scan(2);
	//kasa.scan(4);
	//kasa.scan(5);

	//kasa.deleteScan(3); // Удаление из сканированных

	//kasa.formation(); // Формируем чек


	//kasa.scan(1);
	//kasa.scan(1);
	//kasa.scan(2);
	//kasa.scan(2);
	//kasa.scan(3);

	//kasa.formation();








	cout << "Инструкция:\n Введите end для формирования чека и delete для удаления товара из чека";

	cout << "Мы имеем на складе:\n";
	kasa.discription();
	cout << "\nВыберите товар из списка:\n";


	string input;
	while (input != "end") {
		cout << "Отсканируйте штрихкод: ";
		cin >> input;
		cout << endl;
		if (input == "delete" || input == "end") {
			if (input == "end") {
				kasa.formation();
			}
			else {
				cout << "Отсканируйте товар, который хотите удалить: ";
				cin >> input;
				kasa.deleteScan(stoi(input));
			}
		}
		else
			kasa.scan(stoi(input));
	}
	return 0;
}