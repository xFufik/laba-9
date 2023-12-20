#include <iostream>
#include <string>
using namespace std;
const int MAX_KOL = 30;

/*
* Лабораторная работа 9. Индивидуальный вариант 24.
* Объект – оценки по аттестации и посещаемость студента. Известна фамилия студента, группа, количество дисциплин, оценки по дисциплинам и посещаемость в процентах. Выдать фамилии студентов, имеющих процент посещаемости менее 20.
* return 0 - все ок. return 1 - ошибка.
*/

struct Stud {
	string surname;
	string group;
	int age;
	int discipline_kol;
	int attest_rating[MAX_KOL];
	int visit;
};

int main() {
	Stud st[MAX_KOL];
	int kol_attest, kol_stud;
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	cout << "Введите количество студентов в группе: ";
	cin >> kol_stud;
	if (kol_stud > MAX_KOL) {
		cerr << "Количество студентов не должно привышать " << MAX_KOL << "!";
		return 1;
	}
	cout << "Введите количество дисциплин: ";
	cin >> kol_attest;
	cout << "Введите данные о студентах группы " << endl;
	for (int i = 0; i < kol_stud; i++) {
		cout << "Введите фамилию студента: "; cin.get();
		getline(cin, st[i].surname);
		cout << "Введите название группы: "; 
		getline(cin, st[i].group);
		cout << "Введите возраст: ";
		cin >> st[i].age;
		st[i].discipline_kol = kol_attest;
		cout << "Введите посещаемость студента в процентах: ";
		cin >> st[i].visit;
		cout << "Введите оценки по аттестации" << endl;
		for (int j = 0; j < kol_attest; j++) {
			cout << "Введите оценку по дисциплине " << j + 1 << ": ";
			cin >> st[i].attest_rating[j];
		}
	}

	cout << "Студенты с посещаемостью менее 20%: " << endl;
	for (int i = 0; i < kol_stud; i++) {
		if (st[i].visit < 20) {
			cout << "Студент " << st[i].surname << " из группы " << st[i].group << " имеет посещаемость " << st[i].visit << "%." << endl;
		}
	}
}
