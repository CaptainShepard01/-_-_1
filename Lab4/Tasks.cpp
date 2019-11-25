#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <conio.h>
#include "Header.h";
using namespace std;

bool ok(char* s, int a, int b) {
	bool p = true;
	for (int i = 0; i <= (b - a) / 2; i++) {
		if (s[a + i] != s[b - i - 1]) {
			p = false; break;
		}

	}
	return p;
}

void Palindromer()
{
	char* s = new char[100];
	cout << "Enter your string which you'd like to turn into Palindrom: ";
	cin.getline(s, 100);
	int h = 0;
	while (s[h] >= 0)
		h++;
	h--;
	int i;
	for (i = 0; i < h; i++) {
		if (ok(s, i, h)) {
			break;
		}
	}
	cout << "Here is Palindrom: ";
	int j = 0;
	while (s[j] > 0) {
		cout << s[j];
		j++;
	}
	for (int j = i - 1; j >= 0; j--) {
		cout << s[j];
	}
	cout << endl;
}

bool IsAcute(int a, int b, int c) {
	if (pow(a, 2) + pow(a, 2) > pow(c, 2) && pow(b, 2) + pow(c, 2) > pow(a, 2) && pow(c, 2) + pow(a, 2) > pow(b, 2)) {
		return true;
	}
	return false;
}

struct Triangola { int a, b, c; };

int multiplication(int a, int b, int c) {
	return a * b * c;
}

int sum(int a, int b, int c) {
	return a + b + c;
}

bool IsTriangola(int a, int b, int c) {
	if (a == b + c || b == a + c || c == a + b)return false;
	return true;
}

bool IsNotRepeated(Triangola x, Triangola* y, int l, int z) {
	bool flag = false;
	for (int m = l+1; m < z; ++m) {
		if ((multiplication(x.a, x.b, x.c) == multiplication(y[m].a, y[m].b, y[m].c)) && (sum(x.a, x.b, x.c) == sum(y[m].a, y[m].b, y[m].c))) {
			flag = false;
			break;
		}
		else {
			flag = true;
		}
	}
	return flag;
}

void Triangola_Creator()
{
	cout << "There are N natural numbers, this piece of programme should show us all such trios of numbers without repeats, which are sides of acute-angled triangolas.\n";
	int n;
	cout << "Enter number of natural numbers: ";
	cin >> n;
	int* mas = new int[n];
	cout << "Enter numbers: \n";
	for (int i = 0; i < n; ++i) {
		cin >> mas[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (mas[j] < mas[i]) {
				int temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}
		}
	}

	Triangola* temp = new Triangola[n * (n - 2) * (n - 3)];
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (IsAcute(mas[i], mas[j], mas[k]) && IsTriangola(mas[i], mas[j], mas[k])) {
					temp[count].a = mas[i];
					temp[count].b = mas[j];
					temp[count].c = mas[k];
					count++;
				}
			}
		}
	}

	cout << "\nTriangolas which are with such properties: \n\n";
	for (int i = 0; i < count; ++i) {

		if (IsNotRepeated(temp[i], temp, i, count)) {
			cout << temp[i].a << ' ' << temp[i].b << ' ' << temp[i].c << endl;
		}

	}
	cout << endl;
	delete[] mas;
	delete[] temp;
}