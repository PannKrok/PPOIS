#include <iostream>
#include <vector>
#include <string>
#include "turingmachin.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Turing_Machine tm;
	int condit, n, num;
	char c;
	string pool, tape, term;

	cout << "Введите алфавит: ";
	cin >> pool;
	tm.Set_Pool(pool);
	pool = pool + '~';

	do {
		cout << "Введите слово на ленте: ";
		cin >> tape;
	} while (!tm.Set_Tape(tape));

	cout << "Введите количество состояний: ";
	cin >> condit;
	tm.Set_Condit(condit);
	cin.ignore();

	do {
		for (int i = 0; i < condit; i++) {
			for (char j : pool) {
				do {
					cout << "Введите правило для состояния " << i << " и символа " << j << ": ";
					getline(cin, term);
				} while (!tm.Set_Term(term));
			}
			tm.Push_Back();
		}
	} while (!tm.Check_Fin());
	cout << endl;

	tm.Show_Tape();
	tm.Show_Terms();

	while (true) {
		cout << "Выберите следующее действие:\n0 - просмотреть ленту и таблицу\n1 - изменить значение на ленте\n2 - изменить правило\n3 - запустить машину\n";
		cin >> n;
		cout << endl;

		switch (n) {
		case 0:
			tm.Show_Tape();
			tm.Show_Terms();
			break;
		case 1:
			while (true)
			{
				cout << "Введите номер символа, который хотите изменить: " << endl;
				cin >> num;
				if ((num < 1) || (num > tape.length()))
					cout << "Неправильный ввод" << endl;
				else
					break;
			}
			do
			{
				cout << "Введите новый символ" << endl;
				cin >> c;
			} while (!tm.Change_Tape(num, c));
			cout << endl;
			break;
		case 2:
			do
			{
				cout << "Введите состояние: ";
				cin >> num;
				cout << "Введите символ: ";
				cin >> c;
				cout << "Введите правило: ";
				cin.ignore();
				getline(cin, term);
			} while (!tm.Change_Term(num, c, term));
			break;
		case 3:
			while (true)
			{
				cout << "Выводить на экран информацию после каждого шага? (Y/N): ";
				cin >> c;
				if ((c != 'Y') && (c != 'N'))
				{
					cout << "Неправильный ввод" << endl;
					continue;
				}
				cout << endl;
				tm.Execute(c);
				if (c == 'N')
				{
					tm.Show_Tape();
					tm.Show_Terms();
				}
				return 0;
			}
			return 0;
		default:
			cout << "Неправильный ввод" << endl;
		}
	}
}