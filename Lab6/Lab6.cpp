#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <bitset>
#include <conio.h>
using namespace std;

void md5(char* p, int n) {
	int s[64] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 };
	int k[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee , 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 , 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c , 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 , 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };
	int a0 = 0x67452301;   //A
	int b0 = 0xefcdab89;   //B
	int c0 = 0x98badcfe;   //C
	int d0 = 0x10325476;   //D
	string ss; p += 1;
	//cout <<p<<"k"<<sizeof(p);
	int a = 6;
	int nn = 9;//bool k;
	bitset<512> * u = new bitset<512>[ceil((double)n / 64) + 1];
	int j, jui = ceil((double)n / 64);
	for (j = 0; j < ceil((double)n / 64 - 1); j++) {
		//const size_t N = 4;  // bound on string length

		for (int i = 0; i < 64; i++) {
			//if (p[i] < 0)
			  //break;
			char c = p[64 * j + i];
			for (int jj = 7; jj >= 0 && c; --jj) {
				if (c & 0x1) {
					u[j].set(8 * i + jj);
				}
				c >>= 1;
			}
		}

		for (int ii = 0; ii < 256; ii++) {
			bool  k = u[j][ii];
			u[j][ii] = u[j][512 - ii - 1];
			u[j][512 - ii - 1] = k;
		}

	}
	int i;
	for (i = 0; i < 64; i++) {
		if (p[i] < 0)
			break;
		char c = p[64 * j + i];
		for (int jj = 7; jj >= 0 && c; --jj) {
			if (c & 0x1) {
				u[j].set(8 * i + jj);
			}
			c >>= 1;
		}
	}
	for (int ii = 0; ii < 256; ii++) {
		bool k = u[j][ii];
		u[j][ii] = u[j][512 - ii - 1];
		u[j][512 - ii - 1] = k;
	}


	if (i >= 54) {
		//cout << i << endl;
		u[jui] = (long)n * 8;
		if (i == 64)
			u[jui][511] = 1;
		jui++;
	}
	else {
		u[j][511 - i * 8 + 8] = 1;
		long ll = 0, nn = (long)(n - 1) * 8;
		while (nn > 0) {
			cout << nn % 2 << endl;
			u[jui - 1][ll] = nn % 2;
			nn /= 2;
			ll++;

		}
	}
	cout << u[j] << endl;
	bitset<32> m[16];
	for (int i = 0; i < 16; ++i) {
		for (int ii = 32 * i; ii < 32 * i + 32; ++ii) {
			m[i][ii % 32] = u[j][ii];
		}
	}
	int A = a0;
	int B = b0;
	int C = c0;
	int D = d0;
	for (int i = 0; i < jui; ++i) {
		int F, g;
		if (i >= 0 && i <= 15) {
			F = (B & C) | ((~B) & D);
			g = i;
		}
		else if (i <= 31 && i >= 16) {
			F = (D & B) | ((~D) & C);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i <= 47) {
			F = ((~B & C) | (B & ~C) & ~D) | (D & ~((~B & C) | (B & ~C)));
			g = (3 * i + 5) % 16;
		}
		else if (i >= 48 && i <= 63) {
			F = ((C & ~(B | ~D)) | (~C & (B | ~D)));
			g = (7*i) % 16;
		}
		F = F + A + k[i] + m[g];
		A = D;
		D = C;
		C = B;
		B = B + leftrotate(F, s[i]);
	}
}
//u = 256 * p[0] +p[1];
//cout << u;




//////////////////
int main()
{
	char s[11] = " bibb cock";
	//int b = 13;
	md5(s, 10);
}