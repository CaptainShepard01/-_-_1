#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include "Header.h";
using namespace std;

/*1)	Вводиться N. Розкласти число N! на прості множники. Наприклад, користувач вводить 10, програма виводить {2, 8}, {3, 4}, {5, 2}, {7, 1}.*/

int Task_1()
{
	setlocale(LC_ALL, "Russian");
	int n;
	do {
		cout << "Введите целое положительное число N:\n";
		cin >> n;
	} while (n <= 0);

	return 0;
}

/*9)	Дано два натуральних числа a та b. Вивести на екран період дробу a/b.*/

int Task_9() 
{
	cout << " Есть два натуральных числа a та b. Вывести на экран период дроби a/b. " << endl;
	long double a = 0, b = 0, temp_res = 0;

	int mb_period = 0, count = 0, temp = 1, real_period = 0;

	cout << "Ведите натуральное число A: " << endl;
	cin >> a;

	cout << "Ведите натуральное число B: " << endl;
	cin >> b;

	if (a - (int)a != 0 || b - (int)b != 0)  
	{
		cout << "Некоректное введение!" << endl;
		return;
	}

	double ret = a * double(100000000000000000); 
	long double res = ret / b;
	long double res2 = res / 100000000000000000;

	for (int i = 0; i < 15000; i++) 
	{
		real_period = 0;
		temp_res = res2;
		temp = 1;
		count++;
		for (int j = 0; j < count; j++) temp_res *= 10;
		mb_period = (int)temp_res;
		for (int j = 0; j < count; j++) temp *= 10;

		temp_res -= (int)temp_res;
		temp_res *= temp;

		if (i % 14 == 0 && i != 0) //check for limitation of C++ by type double
		{
			count = 0;
			res2 *= 10;
			res2 -= (int)res;
			mb_period = 0;
			continue;
		}

		if (mb_period == (int)temp_res) real_period++; //first check of period
		else continue;

		if (mb_period >= 1000)
		{
			break;
		}

		temp_res -= (int)temp_res;
		temp_res *= temp;

		if (mb_period == (int)temp_res) real_period++; //second check for period
		else continue;

		if (real_period == 2) break; 
	}

	cout << "Перiод дробу a/b = " << mb_period << endl;
}
