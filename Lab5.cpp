#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Cinema {
protected:
	int minut;
	int year;
public:
	Cinema(int w, int w1) {
		minut = w;
		year = w1;
	}
	virtual void show() = 0;
};

class Action :public Cinema {
private:
	string name;
	int vote;
public:
	Action(int w, int w1, string s, int v) :Cinema(w, w1) {
		name = s;
		vote = v;
	}
	void show() {
		cout << "	Боевик:" << endl;
		cout << "Название боевика: " << name << endl;
		cout << "Продолжительность: " << minut << " минут " << endl;
		cout << "Год выпуска: " << year << endl;
		cout << "Рейтинг: " << vote << endl;
	}
};

class Tails :public Cinema {
private:
	string name;
	string type;
public:
	Tails(int w, int w1, string s, string s1) :Cinema(w, w1) {
		name = s;
		type = s1;
	}
	void show() {
		cout << "	Мультфильм:" << endl;
		cout << "Название мультика: " << name << endl;
		cout << "Продолжительность: " << minut << " минут " << endl;
		cout << "Год выпуска: " << year << endl;
		cout << "Жанр мультика: " << type << endl;
	}
};

class Fantasy :public Cinema {
private:
	string name;
	int vote;
public:
	Fantasy(int w, int w1, string s, int v) :Cinema(w, w1) {
		name = s;
		vote = v;
	}
	void show() {
		cout << "	Фантастика:" << endl;
		cout << "Название: " << name << endl;
		cout << "Продолжительность: " << minut << " минут " << endl;
		cout << "Год выпуска: " << year << endl;
		cout << "Рейтинг: " << vote << endl;
	}
};


void Acti(int&, int&, string&, int&);
void Tail(int&, int&, string&, string&);
void Fant(int&, int&, string&, int&);
int chooseMenu();
string writeWords();
int writeNumbers();

int main() {
	setlocale(0, "rus");
	int n = 1;
	Cinema** mas = new Cinema * [n];
	n--;
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			int y, y1, y2;
			string name;
			Acti(y, y1, name, y2);
			mas[n] = new Action(y, y2, name, y2);
			mas[n]->show();
			n++;
			n++;
			Cinema** ptr = new Cinema * [n];
			n--;
			copy(mas, mas + n, ptr);
			mas = ptr;
			ptr = NULL;
			delete[]ptr;
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) {
				int y, y1;
				string name, type;
				Tail(y, y1, name, type);
				mas[n] = new Tails(y, y1, name, type);
				mas[n]->show();
				n++;
				n++;
				Cinema** ptr = new Cinema * [n];
				n--;
				copy(mas, mas + n, ptr);
				mas = ptr;
				ptr = NULL;
				delete[]ptr;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) {
					int y, y1, y2;
					string name;
					Fant(y, y1, name, y2);
					mas[n] = new Fantasy(y, y1, name, y2);
					mas[n]->show();
					n++;
					n++;
					Cinema** ptr = new Cinema * [n];
					n--;
					copy(mas, mas + n, ptr);
					mas = ptr;
					ptr = NULL;
					delete[]ptr;
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) {
						for (int i = 0; i < n; i++)
							mas[i]->show();
						system("pause");
						system("cls");
					}
					else break;
	}
	return 0;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
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
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { cout << " -> Боевик" << endl; }
		else { cout << " Боевик" << endl; }

		if (choose_menu == 1) { cout << " -> Мультик" << endl; }
		else { cout << " Мультик" << endl; }

		if (choose_menu == 2) { cout << " -> Фантастика" << endl; }
		else { cout << " Фантастика" << endl; }

		if (choose_menu == 3) { cout << " -> Вывод всей информации" << endl; }
		else { cout << " Вывод всей информации" << endl; }

		if (choose_menu == 4) { cout << " -> Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

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

void Acti(int& y, int& y1, string& name, int& y2) {
	cout << "Введите название боевика: ";
	name = writeWords();
	cout << endl;
	cout << "Введите продолжительность: ";
	y = writeNumbers();
	cout << endl;
	cout << "Введите год выпуска: ";
	y1 = writeNumbers();
	cout << endl;
	cout << "Введите рейтинг: ";
	y2 = writeNumbers();
	system("cls");
}

void Tail(int& y, int& y1, string& name, string& type) {
	cout << "Введите название мультика: ";
	name = writeWords();
	cout << endl;
	cout << "Введите продолжительность: ";
	y = writeNumbers();
	cout << endl;
	cout << "Введите год выпуска: ";
	y1 = writeNumbers();
	cout << endl;
	cout << "Введите жанр мультика: ";
	type = writeWords();
	system("cls");
}

void Fant(int& y, int& y1, string& name, int& y2) {
	cout << "Введите название фантастики: ";
	name = writeWords();
	cout << endl;
	cout << "Введите продолжительность: ";
	y = writeNumbers();
	cout << endl;
	cout << "Введите год выпуска: ";
	y1 = writeNumbers();
	cout << endl;
	cout << "Введите рейтинг: ";
	y2 = writeNumbers();
	system("cls");
}