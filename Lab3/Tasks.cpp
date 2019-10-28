#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <conio.h>
#include "Header.h";
using namespace std;

/*1) Turn into chain fraction real number from user.*/

struct Fraction {
	int up;
	int down;
};

void ChainFract(Fraction a, float eps) {
	for (int i = 0; i < 1000 && (a.up / a.down) >= eps;++i) {
		int temp = a.up;
		a.up = a.down;
		a.down = temp;
		int b = int(a.up / a.down);
		if (a.up % a.down == 0) cout << b << endl;
		else cout << b << ", ";
		if (a.up % a.down == 0)return;
		a.up -= (b * a.down);		
	}
	return;
}



int Task_1()
{
	cout << "Turn into chain fraction real number from user.\n";
	Fraction ax;
	float eps;
	cout << "Enter fraction (a/b):\n";
	cout << "a = ";
	cin >> ax.up;
	cout << "b = ";
	cin >> ax.down;
	if (ax.down == 0) {
		cout << "There is no deviding by 0 in this task.\n";
		return 0;
	}
	if (ax.up == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << "Enter epsylon:\n";
	cin >> eps;
	int a;
	cout << "Fractions:\n"; 
	a = int(ax.up / ax.down);
	ax.up -= (int(ax.up / ax.down) * ax.down);
	cout << a << "; ";
	ChainFract(ax, eps);
	return 0;
}



/*15) There is a function. Find lineal function, which approximate it the best. With a method of the smallest squares.*/

int Task_15()
{
	cout << "  There is function f(X). Find function ax+b,\n\
which approximate first the best way. With a method of the smallest squares." << endl;

	setlocale(LC_ALL, "ukr");
	double a = 0, b = 0, x = 0, y = 0, c = 0, d = 0, e = 0, f = 0;
	char choice = 0;
	int n = 0;

	cout << "Enter x and y: " << endl;
	while (choice != 48)
	{
		n++;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		cout << endl << "To continue entering, press Enter, to quit 0!" << endl;

		c += x;
		d += x * x;
		e += x * y;
		f += y;

		b = ((n * e) - (c * f)) / ((n * d) - (c * c)); //cofficients a and b
		a = (e - (d * b)) / c;

		choice = _getche();
	}

	system("cls");
	bool temp = a > a - 100;
	if (temp)
		cout << "Result: " << endl << "a = " << a << endl << "b = " << b << endl;
	else cout << "Incorrect enter, with MSS such a and b do not exist! " << endl;
	return 0;
}