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

int ChainFract(float x, float eps) {
	/*while ((1 / x - int(1/x)) > eps) {
		int a = int(1 / x);
		x = 1 / x - a;
		cout << a << ", ";
	}*/
	while (x > eps && x!=0) {
		cout << int(1/x) << ", ";
		x = (1 / x) - int(1/x);
		ChainFract(x, eps);
	}
	return 0;
}



int Task_1()
{
	cout << "Turn into chain fraction real number from user.\n";
	float c, b, x;
	cout << "Enter fraction (c/b):\n";
	cout << "c = ";
	cin >> c;
	cout << "b = ";
	cin >> b;
	x = c / b;
	int a, k;
	float x0;
	a = int(x);
	x = x - a;
	cout << a << "; ";
	ChainFract(x, 0.25);
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