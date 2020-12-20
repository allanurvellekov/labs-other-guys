#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

template <typename T>
class Set {
private:
	T *a = new T;
	int n;
public:
	Set() {
		n = 0;
	}
	void show() {
		cout << "Множество: {";
		for (int i = 0; i < n - 1; i++)
			cout << a[i] << ",";
		if (n != 0) cout << a[n - 1] << "}" << endl;
		else cout << "}" << endl;
	}
	void check(T b) {
		int ch = 0;
		for (int i = 0; i < n; i++)
			if (a[i] == b) { ch = 1; break; }
		if (ch == 1) cout << "Элемент уже есть в множестве." << endl;
		else cout << "Элементы нет в множестве." << endl;
		system("pause");
		system("cls");
	}
	void operator+=(T b) {
		int ch = 0;
		for (int i = 0; i < n; i++)
			if (a[i] == b) { ch = 1; break; }
		if (ch == 0) {
			T* ptr = new T[n + 1];
			for (int i = 0; i < n; i++)
				ptr[i] = a[i];
			a = ptr;
			ptr = NULL;
			delete[]ptr;
			a[n] = b;
			n++;
		}
	}
	void del(T b) {
		int j = -1;
		for(int i = 0; i < n; i++)
			if (a[i] == b) {
				j = i;
				break;
			}
		if (j != -1) {
			for (int i = j; i < n - 1; i++)
				a[i] = a[i + 1];
			n--;
		}
	}
	void operator*(Set& s2) {
		cout << "Пересечение множеств: ";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < s2.n; j++)
				if (a[i] == s2.a[j]) cout << a[i] << " ";
		cout << endl;
		system("pause");
		system("cls");
	}
};

int chooseSet(int nSets) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + (nSets + 1)) % (nSets + 1);

		for (int i = 0; i < nSets; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << i << "-множество" << endl; }
			else { cout << " " << i + 1 << " - " << i << "-множество" << endl; }

		if (choose_menu == nSets) { cout << " -> Выйти с выбора" << endl; }
		else cout << " Выйти с выбора" << endl;

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseMenu() {
	int choose_menu = 0, key = 0;
	system("cls");
	while (true) {
		choose_menu = (choose_menu + 7) % 7;

		if (choose_menu == 0) cout << "-> Добавить множество" << endl;
		else cout << " Добавить множество" << endl;

		if (choose_menu == 1) cout << "-> Посмотреть множества" << endl;
		else cout << " Посмотреть множества" << endl;

		if (choose_menu == 2) cout << " -> Проверка элемента в множестве" << endl;
		else cout << " Проверка элемента в множестве" << endl;

		if (choose_menu == 3) cout << " -> Добавить элемент в множество" << endl;
		else cout << " Добавить элемент в множество" << endl;

		if (choose_menu == 4) cout << " -> Удалить элемент из множества" << endl;
		else cout << " Удалить элемент из множества" << endl;

		if (choose_menu == 5) cout << " -> Пересечение множеств" << endl;
		else cout << " Пересечение множеств" << endl;

		if (choose_menu == 6) cout << " -> Выход" << endl;
		else cout << " Выход" << endl;

		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72) choose_menu--;
			if (key == 80) choose_menu++;
		}
		if (key == 13) {
			system("cls");
			return choose_menu;
		}
		system("cls");
	}
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0 && numbers != "-") break;
				else
					if ((key >= '0' && key <= '9') || (key == '-' && numbers.length() == 0)) {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

int main() {
	setlocale(0, "rus");
	int nSet = 0;
	Set<int> *sets = new Set<int>[1];
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			nSet++;
			Set<int>* ptr = new Set<int>[nSet];
			for (int i = 0; i < nSet - 1; i++)
				ptr[i] = sets[i];
			sets = ptr;
			ptr = NULL;
			delete[]ptr;
			cout << "Множество созданно." << endl;
			system("pause");
			system("cls");
		}else
			if (choose == 1) {
				for (int i = 0; i < nSet; i++)
					sets[i].show();
				system("pause");
				system("cls");
			}else
				if (choose == 2) {
					int check = chooseSet(nSet);
					if (check == nSet) continue;
					int a;
					cout << "Введите элемент на проверку: ";
					a = writeNumbers();
					sets[check].check(a);
					system("cls");
				}else
					if (choose == 3) {
						int check = chooseSet(nSet);
						if (check == nSet) continue;
						int a;
						cout << "Введите элемент: ";
						a = writeNumbers();
						sets[check] += a;
						system("cls");
					}else
						if (choose == 4) {
							int check = chooseSet(nSet);
							if (check == nSet) continue;
							int a;
							cout << "Введите элемент для удаления: ";
							a = writeNumbers();
							sets[check].del(a);
							system("cls");
						}
						else
							if (choose == 5) {
								int check = chooseSet(nSet);
								if (check == nSet) continue;
								int check1 = chooseSet(nSet);
								if (check1 == nSet) continue;
								sets[check] * sets[check1];
							}
							else break;
	}
	return 0;
}
