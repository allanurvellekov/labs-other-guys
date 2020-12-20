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
	int getMinut() {
		return minut;
	}
	int getYear() {
		return year;
	}
};

class Action:public Cinema {
private:
	string name;
	int vote;
public:
	Action(int w, int w1, string s, int v) :Cinema(w, w1) {
		name = s;
		vote = v;
	}
	void show() {
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
		cout << "Название: " << name << endl;
		cout << "Продолжительность: " << minut << " минут " << endl;
		cout << "Год выпуска: " << year << endl;
		cout << "Рейтинг: " << vote << endl;
	}
};

string writeWords();
int writeNumbers();

int main() {
	setlocale(0, "rus");
	string s,s1;
	int a, a1, a2;
	cout << "Введите название боевика: ";
	s = writeWords();
	system("cls");
	cout << "Введите продолжительность: ";
	a = writeNumbers();
	system("cls");
	cout << "Введите год выпуска: ";
	a1 = writeNumbers();
	system("cls");
	cout << "Введите рейтинг: ";
	a2 = writeNumbers();
	system("cls");
	Action act(a, a1, s, a2);
	cout << "Введите название мультика: ";
	s = writeWords();
	system("cls");
	cout << "Введите продолжительность: ";
	a = writeNumbers();
	system("cls");
	cout << "Введите год выпуска: ";
	a1 = writeNumbers();
	system("cls");
	cout << "Введите жанр мультика: ";
	s1 = writeWords();
	system("cls");
	Tails tail(a, a1, s, s1);
	cout << "Введите название фантастики: ";
	s = writeWords();
	system("cls");
	cout << "Введите продолжительность: ";
	a = writeNumbers();
	system("cls");
	cout << "Введите год выпуска: ";
	a1 = writeNumbers();
	system("cls");
	cout << "Введите рейтинг: ";
	a2 = writeNumbers();
	system("cls");
	Fantasy fan(a, a1, s, a2);
	act.show();
	cout << endl;
	tail.show();
	cout << endl;
	fan.show();
	cout << endl;
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
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
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