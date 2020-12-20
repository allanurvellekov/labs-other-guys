#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <cstring>


using namespace std;

class String {
	char* s = new char;
	int n;
public:
	String() {
		n = 0;
	};
	String& operator+=(char* str) {
		int n1 = strlen(s);
		int n2 = strlen(str);
		int j = n1 + n2;
		strcat(s, str);
		s[j] = '\0';
		n = j;
		return *this;
	}
	String& operator=(char* str) {
		n = strlen(str);
		s = str;
		return *this;
	}
	String(char* s1) {
		s = s1;
		n = strlen(s);
	}
	String(const String& str) {
		s = str.s;
		n = str.n;
	}
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, String&);
};

istream& operator>>(istream& in, String& str)
{
	cout << "Введите строку = ";
	in >> str.s;
	return in;
}

ostream& operator<<(ostream& out, String& str)
{
	out << str.s;
	return out;
}


int main() {
	setlocale(0, "rus");
	char* s1 = new char[255];
	String str;
	cin >> str;
	cout << "Введите вторую строку которую прибавить = ";
	cin >> s1;
	cout << "Первая строка = ";
	cout << str;
	cout << endl;
	str += s1;
	cout << "str += s - ";
	cout << str;
	cout << endl;
	str = s1;
	cout << "str = s - ";
	cout << str;
	cout << endl;
	return 0;
}