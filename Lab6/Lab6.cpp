#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <conio.h>
#include "Header.h";

using namespace std;

bool SmlrWrds(char** s, char a, int n, int an)
{
	for (int i = 0; i < n; ++i) {
		
	}
}


void Task_1()
{
	ifstream in("text.txt");
	cout << "There is a text. Set all the text for the left side and delete duplicated words and spaces.\n";
	char* text = new char[256];
	while (!in.eof()) {
		in.getline(text, 256);
		int count = 0, curIter = 0, iterI = 0, I = 0;
		char temp = '\0';
		char** words = new char* [256];
		for (int i = 0; i < 256; ++i) {
			words[i] = new char[256];
		}
		char** words1 = new char* [256];
		for (int i = 0; i < 256; ++i) {
			words1[i] = new char[256];
		}
		int j = 0;
		for (int i = 0; text[i - 1] != '\0'; i++)
		{
			if (temp == '\0' && text[i] != ' ')
			{
				curIter = i;
				temp = text[i];
			}

			if (text[i + 1] == ' ' || text[i + 1] == '\0')
			{
				if (curIter <= i && temp != '\0')
				{
					for (int j = curIter, g = 0; j <= i; j++)
					{
						words[iterI][g++] = text[j];
					}
					iterI++;
				}
				temp = '\0';
			}
		}
		for (int i = 0; text[i - 1] != '\0'; i++)
		{
			if (temp == '\0' && text[i] != ' ')
			{
				curIter = i;
				temp = text[i];
			}

			if (text[i + 1] == ' ' || text[i + 1] == '\0')
			{
				if (curIter <= i && temp != '\0')
				{
					for (int j = curIter, g = 0; j <= i; j++)
					{
						words1[I][g++] = text[j];
					}
					I++;
				}
				temp = '\0';
			}
		}
		cout << endl;
		for (int i = 0; i < iterI; i++)
		{
			for (int k = 0; words[i][k] > 0; k++) {
				cout << words[i][k];
			}
			cout << ' ';
		}
	}
	cout << endl;
	in.close();
}

int leftrotate(int x, int c)
{
	return x << c || x >> (32 - c);
}

void md5(char* p, int n) {
	int s[64] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 };
	unsigned int k[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee , 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 , 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c , 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 , 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };
	unsigned int a0 = 0x67452301;   //A
	unsigned int b0 = 0xefcdab89;   //B
	unsigned int c0 = 0x98badcfe;   //C
	unsigned int d0 = 0x10325476;   //D
	string ss; //p += 1;
	//cout <<p<<"k"<<sizeof(p);
	//int a = 6;
	//int nn = 9;//bool k;
	unsigned int** u = new unsigned int* [ceil((double)n / 64) + 1];
	for (int i = 0; i < ceil((double)n / 64) + 1; i++)
		u[i] = new unsigned int[16];
	int j, jui = ceil((double)n / 64);
	for (int i = 0; i < ceil((double)n / 64) + 1; i++)
		for (int j = 0; j < 16; j++)
			u[i][j] = 0;
	for (j = 0; j < ceil((double)n / 64 - 1); j++) {

		for (int i = 64 * j + 3; i < 64 * j + 64; i += 4) {
			int y = 0;
			//if (i >= n) {
				//	break;
				//}
			for (int g = i + 4; g > i; g--) {

				y *= 256;
				y += p[g];
			}
			u[j][(i - 64 * j) / 4] = y;
			cout << u[j][(i - 64 * j) / 4] << ' ';
		}
		cout << endl;
	}
	int tick = 0, ttick = 0;
	//for (j = 0; j < ceil((double)n / 64 ); j++) {

	for (int i = 64 * j + 3; i < 64 * j + 64; i += 4) {
		int y = 0;
		//if (i >= n) {
		//break;
	//}
		tick = 0;
		for (int g = i; g > i - 4; g--) {

			y *= 256;
			if (g >= n) {
				//	cout << tick << 'j';
				tick = g - i + 3;
			}
			else y += p[g];
			//cout << g << ' '<< y << endl;
		}
		if (tick > 0) {

			y *= pow(256, 4 - tick);
			u[j][(i - 64 * j) / 4] = y + pow(256, 3 - tick);
			cout << u[j][(i - 64 * j) / 4] << ' ';
			ttick++;
			break;
		}
		ttick++;
		u[j][(i - 64 * j) / 4] = y;
		cout << u[j][(i - 64 * j) / 4] << ' ';
	}
	cout << endl;
	//}
		//cout << ttick;

	if (ttick < 14) {
		u[j][14] = n / pow(2, 32);
		u[j][15] = n % ((int)pow(2, 32));
		//cout << u[j][15];
	}
	else {
		jui++;
		u[j + 1][14] = n / pow(2, 32);
		u[j + 2][15] = n % ((int)pow(2, 32));
	}

	for (int i = 0; i < 16; i++)
		cout << u[0][i] << ' ';
	cout << endl; system("pause");

	////
	int** uu = new int* [jui];
	int r;
	/*for (int i = 0; i < jui; i++) {
		uu[i] = new int[16];
		for (int j = 0; j < 16; j++) {
			r = 0x0;
			for (int g = 32 * (j); g < 32*(j +1); g++) {
				r *= 2;
				r += u[i][g];
			} ///// divide into groups 4 bit each zen skleit
			switch (r) {
			case 1:
				uu[i][j] = 0x1;
				break;case 2:
				uu[i][j] = 0x2;
				break;case 3:
				uu[i][j] = 0x3;
				break;case 4:
				uu[i][j] = 0x4;
				break;case 5:
				uu[i][j] = 0x5;
				break;case 6:
				uu[i][j] = 0x6;
				break;case 7:
				uu[i][j] = 0x7;
				break;case 8:
				uu[i][j] = 0x8;
				break;case 9:
				uu[i][j] = 0x9;
				break;case 10:
				uu[i][j] = 0xa;
				break;case 11:
				uu[i][j] = 0xb;
				break;case 12:
				uu[i][j] = 0xc;
				break;case 13:
				uu[i][j] = 0xd;
				break;case 14:
				uu[i][j] = 0xe;
				break;case 15:
				uu[i][j] = 0xf;
				break;
			}
			//
		}
	}
	*/
	//cout << u[j] << endl;
	int A, B, C, D, f, g;
	for (int j = 0; j < jui; j++) {
		//int m[16];
		//for (int i = 0; i < 16; i++) {
			//for (int ii = 32 * i; ii < 32 * i + 32; ii++) {
			//	m[i][ii % 32] = u[j][ii];
			//}
		//}
		A = a0;
		B = b0;
		C = c0;
		D = d0;
		for (int i = 0; i < 64; i++) {
			if (i < 16) {
				f = (B & C) | (~B & D);
				g = i;
			}
			else if (i < 32) {
				f = (D & B) | ((~D) & C);
				g = (5 * i + 1) % 16;
			}
			else if (i < 48) {
				f = (((~B & C) | (~C & B)) & ~D) | (~((~B & C) || (~C & B)) & D);
				g = (3 * i + 5) % 16;
			}
			else {
				f = (C & ~(B | ~D)) | (~C & (B | ~D));
				g = (7 * i) % 16;
			}
			f = f + A + k[i] + u[j][g];
			A = D;
			D = C;
			C = B;
			B = B + leftrotate(f, s[i]);
		}
		a0 = a0 + A;
		b0 = b0 + B;
		c0 = c0 + C;
		d0 = d0 + D;
	}
	//bitset<8> o, b, c;`
	//o[0] = b[0] + c[0];
	cout << endl << a0 << ' ' << b0 << ' ' << c0 << ' ' << d0 << endl;
}

//bitset<8> o, b, c;`
//o[0] = b[0] + c[0];

//u = 256 * p[0] +p[1];
//cout << u;




//////////////////
int main()
{
	char s[11] = "abcdefghik";
	//cin >> s;
	//cout << s << endl;
	//s -= 1;
	//cout << s << endl;

	//s[0]= 'p';
	//cout << s << endl;
	//int b = 13;
	//int y = 0x0;
	//cout << (y + 0xa)<<' ';
	//unsigned int i = pow(2, 32);
	//cout << i << endl;
	//cout << (int)'d';
	md5(s, 10);
}
