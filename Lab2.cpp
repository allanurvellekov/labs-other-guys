#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

double writeNumbers();

class Circle {
private:
    double radius;
public:
	Circle() {
		radius = 0;
	}
	Circle(double p) {
		radius = p;
	}
    double getDlina() {
        return 2 * M_PI * radius;
    }
    double getSquare() {
        return M_PI * radius * radius;
    }
    double getRadius() {
        return radius;
    }
    void changeRadius(double p) {
        radius = p;
    }
    void show() {
        cout << "Радиус окружности: " << radius << endl;
        cout << "Площадь окружности: " << getSquare() << endl;
        cout << "Длинна окружности: " << getDlina() << endl;
    }
};

int main()
{
	setlocale(0, "rus");
    Circle circ;
	double r;
	cout << "Введите радиус окружности: ";
	r = writeNumbers();
	cout << endl;
	system("cls");
	circ.changeRadius(r);
	circ.show();
	return 0;
}

double writeNumbers() {
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
					if ((key >= '0' && key <= '9') || (key == ',')) {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stof(numbers);
}