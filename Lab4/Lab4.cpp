#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <conio.h>
#include "Header.h";
using namespace std;

int menu();
int main()
{
	setlocale(LC_ALL, "Russian");
	int answer = menu();
	switch (answer)
	{
	case 0:Palindromer(); break;
	case 1:Triangola_Creator(); break;
		system("pause");
		return 0;
	}
	return 0;
}

int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 2) % 2;
		if (key == 0) cout << "-> Palindrom (Task_1)" << endl;
		else  cout << "   Palindrom (Task_1)" << endl;
		if (key == 1) cout << "-> Triangola_Creator (Task_2)" << endl;
		else  cout << "   Triangola_Creator (Task_2)" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

