#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include "Header.h";
#include <vector>;
using namespace std;

struct point
{
	float x, y;
};

/*1)	There are 3 pairs of numbers (coordinates of a triangola). There is 1 more pair of numbers (point). Determine if the point is inside the triangola, outside or on 1 of its sides.*/

int NotTriangola(point a, point b, point c)
{
	if (sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2)) == (sqrt(pow((a.x - c.x), 2) + pow((a.y - c.y), 2)) + sqrt(pow((b.x - c.x), 2) + pow((b.y - c.y), 2)))) {
		return 1;
	}
	return 0;
}

float SquareOfTriangola(point a, point b, point c) {
	return ((abs((a.x - b.x) * (c.y - b.y) - (c.x - b.x) * (a.y - b.y))) / 2);
}

int Task_1()
{
	setlocale(LC_ALL, "Russian");
	cout << "There are 3 pairs of numbers (coordinates of a triangola). There is 1 more pair of numbers (point). Determine if the point is inside the triangola, outside or on 1 of its sides.\n";
	point a, b, c, ax;
	float square1, square2, square3, square;
	do {
		cout << "Enter coordinates of the first vertex of the triangola A (x1 and y1):\n";
		cin >> a.x >> a.y;
		cout << "Enter coordinates of the first vertex of the triangola B (x2 and y2):\n";
		cin >> b.x >> b.y;
		cout << "Enter coordinates of the first vertex of the triangola C (x3 and y3):\n";
		cin >> c.x >> c.y;
		if (NotTriangola(a, b, c) || NotTriangola(b, c, a) || NotTriangola(c, a, b)) {
			cout << "It is not a triangola!!!\n";
			system("cls");
		}
	} while (NotTriangola(a, b, c) || NotTriangola(b, c, a) || NotTriangola(c, a, b));

	cout << "Enter coordinates of the point (x and y):\n";
	cin >> ax.x >> ax.y;

	square = SquareOfTriangola(a, b, c);
	square1 = SquareOfTriangola(b, ax, a);
	square2 = SquareOfTriangola(c, ax, b);
	square3 = SquareOfTriangola(a, ax, c);

	float sum = square1 + square2 + square3;
	if (sum > square) {
		cout << "Point is outside\n";
		return 0;
	}
	else if (square1 == 0 && sum == square) {
		cout << "Point is on the side AB\n";
		return 0;
	}
	else if (square2 == 0 && sum == square) {
		cout << "Point is on the side BC\n";
		return 0;
	}
	else if (square3 == 0 && sum == square) {
		cout << "Point is on the side AC\n";
		return 0;
	}
	else if (sum == square && square1 != 0 && square2 != 0 && square3 != 0) {
		cout << "Point is inside\n";
		return 0;
	}
	return 0;
}

/*13) There are n points, build convex hull */

float OrientTriangl2(const point& p1, const point& p2, const point& p3)
{
	return ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

bool isInside(const point& p1, const point& p, const point& p2)
{
	return (p1.x <= p.x && p.x <= p2.x &&
		p1.y <= p.y && p.y <= p2.y);
}

void ConvexHullJarvis(const vector<point>& mas, vector<int>& convex_hull)
{
	// finding the leftest of the downest
	int base = 0;
	int n = mas.size();
	for (int i = 1; i < n; i++)
	{
		if (mas[i].y < mas[base].y)
			base = i;
		else
			if (mas[i].y == mas[base].y &&
				mas[i].x < mas[base].x)
				base = i;
	}
	// this point is in our hull
	convex_hull.push_back(base);

	int first = base;
	int cur = base;
	do
	{
		int next = (cur + 1) % n;
		for (int i = 0; i < n; i++)
		{
			int sign = OrientTriangl2(mas[cur], mas[next], mas[i]);
			//point mas[i] is left from line ( mas[cur], mas[next] )
			if (sign < 0) // counterclockwise
				next = i;
			// point is on the line ( mas[cur], mas[next] )
			else if (sign == 0)
			{
				// point mas[i] is further, than mas[next] from point mas[cur]
				if (isInside(mas[cur], mas[next], mas[i]))
					next = i;
			}
		}
		cur = next;
		convex_hull.push_back(next);
	} while (cur != first);
}

int Task_13() {
	cout << "There are n points, build convex hull\n";
	int n;
	cout << "Enter n\n";
	vector<point> mas;
	vector<int> convex_hull;
	cin >> n;
	mas.resize(n);
	cout << "Enter coordinates of points (x and y):\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " ------> ";
		cin >> mas[i].x >> mas[i].y;
	}
	cout << endl;
	ConvexHullJarvis(mas, convex_hull);
	cout << "Convex hull counterclockwise:\n";
	for (int i = 0; i < convex_hull.size(); ++i) {
		cout << i + 1 << " ------> " << convex_hull[i] + 1 << endl;
	}
	return 0;
}




void ConvexHullJarvisAlt(int& t, int n, const point mas[], int count[])
{
	// finding the leftest of the downest
	int base = 0;
	for (int i = 1; i < n; i++)
	{
		if (mas[i].y < mas[base].y)
			base = i;
		else
			if (mas[i].y == mas[base].y &&
				mas[i].x < mas[base].x)
				base = i;
	}
	//this point is in our hull
	count[0] = base;
	int k = 0;
	int first = base;
	int cur = base;
	do
	{
		int next = (cur + 1) % n;
		for (int i = 0; i < n; i++)
		{
			int sign = OrientTriangl2(mas[cur], mas[next], mas[i]);
			//point mas[i] is left from line ( mas[cur], mas[next] )
			if (sign < 0) // counterclockwise
				next = i;
			//point is on the line ( mas[cur], mas[next] )
			else if (sign == 0)
			{
				// point mas[i] is further, than mas[next] from point mas[cur]
				if (isInside(mas[cur], mas[next], mas[i]))
					next = i;
			}
		}
		cur = next;
		count[++k] = cur;
	} while (cur != first);
	t = k;
}

int Task_13_alternative()
{
	cout << "There are n points, build convex hull\n";
	int n, i, j;
	int t = 0;
	cout << "Enter n\n";
	cin >> n;
	point* Mass = new point[n];
	int* Count = new int[n];
	cout << "Enter coordinates of points (x and y):\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " ------> ";
		cin >> Mass[i].x >> Mass[i].y;
	}
	ConvexHullJarvisAlt(t, n, Mass, Count);
	cout << "Convex hull counterclockwise:\n";
	for (int i = 0; i < t + 1; ++i) {
		cout << i + 1 << " ------> " << Count[i] + 1 << endl;
	}
	delete[] Mass;
	delete[] Count;
	return 0;
}