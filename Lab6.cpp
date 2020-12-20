#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Cinema {
protected:
	string type;
	int year;
public:
	Cinema() {
		year = 0;
	};
	string getType() {
		return type;
	}
	int getYear() {
		return year;
	}
	void changeYear(int p) {
		year = p;
	}
	void changeType(string p) {
		type = p;
	}
	void show() {
		cout << "Жанр: " << type << endl;
		cout << "Год выпуска: " << year << endl;
	}
};

class Func :virtual public Cinema {
protected:
	int minut;
	int vote;
public:
	Func() {
		minut = 0;
		vote = 0;
	}
	int getVote() {
		return vote;
	}
	int getMinut() {
		return minut;
	}
	void changeVote(int p) {
		vote = p;
	}
	void cahngeMinut(int p) {
		minut = p;
	}
	void show() {
		cout << "Продолжительность: " << minut << " минут " << endl;
		cout << "Рейтинг: " << vote << endl;
	}
};

class Desc :virtual public Cinema {
protected:
	string sname;
	string country;
public:
	string getSname() {
		return sname;
	}
	string getCountry() {
		return country;
	}
	void changeSname(string p) {
		sname = p;
	}
	void changeCountry(string p) {
		country = p;
	}
	void show() {
		cout << "Фамилия режиссера: " << sname << endl;
		cout << "Страна производитель: " << country << endl;
	}
};

class Film :public Func, public Desc {
private:
	string name;
public:
	Film() {};
	string getName() {
		return name;
	}
	void changeName(string p) {
		name = p;
	}
	void showAll() {
		cout << "Название фильма: " << name << endl;
		Cinema::show();
		Desc::show();
		Func::show();
	}
};

int chooseMenu();
string writeWords();
int writeNumbers();
int chooseWhoRed(Film*&, int);
int chooseWhatRed(Film*&, int);

int main() {
	setlocale(0, "rus");
	int nFilms = 0;
	Film* films = new Film[nFilms];
	while (true) {
		int choose = chooseMenu();
		if (choose == 1) {
			if (nFilms != 0) {
				while (true) {
					int choose1 = chooseWhoRed(films, nFilms);
					if (choose1 == nFilms) break;
					while (true) {
						int choose2 = chooseWhatRed(films, choose1);
						if (choose2 == 7) break;
						string ptr1; int ptr;
						if (choose2 == 0) {
							cout << "Введите название: ";
							ptr1 = writeWords();
							films[choose1].changeName(ptr1);
							system("cls");
						}
						else
							if (choose2 == 1) {
								cout << "Введите жанр: ";
								ptr1 = writeWords();
								films[choose1].changeType(ptr1);
								system("cls");
							}
							else
								if (choose2 == 2) {
									cout << "Введите год выпуска: ";
									ptr = writeNumbers();
									films[choose1].changeYear(ptr);
									system("cls");
								}
								else
									if (choose2 == 3) {
										cout << "Введите продолжительность: ";
										ptr = writeNumbers();
										films[choose1].cahngeMinut(ptr);
										system("cls");
									}
									else
										if (choose2 == 4) {
											cout << "Введите рейтинг: ";
											ptr = writeNumbers();
											films[choose1].changeVote(ptr);
											system("cls");
										}
										else
											if (choose2 == 5) {
												cout << "Введите фамилию режиссера: ";
												ptr1 = writeWords();
												films[choose1].changeSname(ptr1);
												system("cls");
											}
											else
												if (choose2 == 6) {
													cout << "Введите страну: ";
													ptr1 = writeWords();
													films[choose1].changeCountry(ptr1);
													system("cls");
												}
					}
				}
			}
			else {
				cout << "Вы еще не добавили историй" << endl;
				system("pause");
				system("cls");
			}
		}
		else
			if (choose == 0) {
				Film p;
				string ptr1; int ptr;
				cout << "Введите название: ";
				ptr1 = writeWords();
				p.changeName(ptr1);
				system("cls");
				cout << "Введите жанр: ";
				ptr1 = writeWords();
				p.changeType(ptr1);
				system("cls");
				cout << "Введите год выпуска: ";
				ptr = writeNumbers();
				p.changeYear(ptr);
				system("cls");
				cout << "Введите продолжительность: ";
				ptr = writeNumbers();
				p.cahngeMinut(ptr);
				system("cls");
				cout << "Введите рейтинг: ";
				ptr = writeNumbers();
				p.changeVote(ptr);
				system("cls");
				cout << "Введите фамилию режиссера: ";
				ptr1 = writeWords();
				p.changeSname(ptr1);
				system("cls");
				cout << "Введите страну: ";
				ptr1 = writeWords();
				p.changeCountry(ptr1);
				system("cls");
				nFilms++;
				Film* ptrr = new Film[nFilms];
				for (int i = 0; i < nFilms - 1; i++)
					ptrr[i] = films[i];
				films = ptrr;
				ptrr = NULL;
				delete[]ptrr;
				films[nFilms - 1] = p;
			}
			else
				if (choose == 2) {
					for (int i = 0; i < nFilms; i++) {
						films[i].showAll();
						cout << endl;
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) break;
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

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Добавить фильм" << endl; }
		else { cout << " Добавить фильм" << endl; }

		if (choose_menu == 1) { cout << " -> Редактировать фильмы" << endl; }
		else { cout << " Редактировать фильмы" << endl; }

		if (choose_menu == 2) { cout << " -> Просмотр фильмов" << endl; }
		else { cout << " Просмотр фильмов" << endl; }

		if (choose_menu == 3) { cout << " -> Завершить программу" << endl; }
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

int chooseWhoRed(Film*& films, int nFilms) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + (nFilms + 1)) % (nFilms + 1);

		for (int i = 0; i < nFilms; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << films[i].getName() << endl; }
			else { cout << " " << i + 1 << " - " << films[i].getName() << endl; }

		if (choose_menu == nFilms) { cout << " -> Выйти с выбора фильма" << endl; }
		else cout << " Выйти с выбора фильма" << endl;

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

int chooseWhatRed(Film*& films, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 8) % 8;

		if (choose_menu == 0) { cout << " -> Название: " << films[choose].getName() << endl; }
		else cout << " Название: " << films[choose].getName() << endl;

		if (choose_menu == 1) { cout << " -> Жанр: " << films[choose].getType() << endl; }
		else cout << " Жанр: " << films[choose].getType() << endl;

		if (choose_menu == 2) { cout << " -> Год выпуска: " << films[choose].getYear() << endl; }
		else cout << " Год выпуска: " << films[choose].getYear() << endl;

		if (choose_menu == 3) { cout << " -> Продолжительность: " << films[choose].getMinut() << endl; }
		else cout << " Продолжительность: " << films[choose].getMinut() << endl;

		if (choose_menu == 4) { cout << " -> Рейтинг: " << films[choose].getVote() << endl; }
		else cout << " Рейтинг: " << films[choose].getVote() << endl;

		if (choose_menu == 5) { cout << " -> Фамилия режиссера: " << films[choose].getSname() << endl; }
		else cout << " Фамилия режиссера: " << films[choose].getSname() << endl;

		if (choose_menu == 6) { cout << " -> Страна: " << films[choose].getCountry() << endl; }
		else cout << " Страна: " << films[choose].getCountry() << endl;

		if (choose_menu == 7) { cout << " -> Выйти в меню выбора " << endl; }
		else cout << " Выйти в меню выбора " << endl;


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





