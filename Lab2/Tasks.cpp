#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include "Header.h";
#include <vector>;
using namespace std;

/*1)	Задаються три пари чисел, які задають трикутник на площині. Крім того,задається ще одна пара чисел, яка задає точку на площині. Визначити, чи лежить точка усередині трикутника, чи на одному з його ребер, чи зовні.*/

int NotTriangola(float x1, float y1, float x2, float y2, float x3, float y3)
{
	if (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) == (sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2)) + sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2)))) {
		return 1;
	}
	return 0;
}

float SquareOfTriangola(float x1, float y1, float x2, float y2, float x3, float y3) {
	return (0, 5 * (abs((x1 - x2) * (y3 - y2) - (x3 - x2) * (y1 - y2))));
}

int Task_1()
{
	setlocale(LC_ALL, "Russian");
	cout << "Задаются 3 пары чисел, которые задают трехугольник на плоскости. Кроме того, задается еще одна пара чисел (еще одна точка). Определить, лежит ли точка внутри трехугольника, снаружи или на ребре.\n";
	float x1, y1, x2, y2, x3, y3, ax, ay;
	float square1, square2, square3, square;
	do {
		cout << "Введите координаты первой точки трехугольника A (x1 и y1):\n";
		cin >> x1 >> y1;
		cout << "Введите координаты второй точки трехугольника B (x2 и y2):\n";
		cin >> x2 >> y2;
		cout << "Введите координаты третьей точки трехугольника C (x3 и y3):\n";
		cin >> x3 >> y3;
		if (NotTriangola(x1, y1, x2, y2, x3, y3) || NotTriangola(x2, y2, x3, y3, x1, y1) || NotTriangola(x3, y3, x1, y1, x2, y2)) {
			cout << "Это не трехугольник\n";
			system("cls");
		}
	} while (NotTriangola(x1, y1, x2, y2, x3, y3) || NotTriangola(x2, y2, x3, y3, x1, y1) || NotTriangola(x3, y3, x1, y1, x2, y2));

	cout << "Введите координаты точки на плоскости (x и y):\n";
	cin >> ax >> ay;

	square = SquareOfTriangola(x1, y1, x2, y2, x3, y3);
	square1 = SquareOfTriangola(x2, y2, ax, ay, x1, y1);
	square2 = SquareOfTriangola(x3, y3, ax, ay, x2, y2);
	square3 = SquareOfTriangola(x1, y1, ax, ay, x3, y3);

	float sum = square1 + square2 + square3;
	if (sum > square) {
		cout << "Точка снаружи трехугольника\n";
		return 0;
	}
	else if (square1 == 0 && sum == square) {
		cout << "Точка лежит на ребре AB\n";
		return 0;
	}
	else if (square2 == 0 && sum == square) {
		cout << "Точка лежит на ребре BC\n";
		return 0;
	}
	else if (square3 == 0 && sum == square) {
		cout << "Точка лежит на ребре AC\n";
		return 0;
	}
	else if (sum == square && square1 != 0 && square2 != 0 && square3 != 0) {
		cout << "Точка внутри трехугольника\n";
		return 0;
	}
	return 0;
}

/*13) Дано n точок на площині. Побудувати їх опуклу лінійну оболонку */

/*Построение выпуклой оболочки обходом Грэхэма
:
Даны N точек на плоскости. Построить их выпуклую оболочку, т.е. наименьший выпуклый многоугольник, содержащий
 все эти точки.
Мы рассмотрим метод Грэхэма (Graham) (предложен в 1972 г.) с улучшениями Эндрю (Andrew) (1979 г.). С
его помощью можно построить выпуклую оболочку за время O (N log N) с использованием только операций
сравнения, сложения и умножения. Алгоритм является асимптотически оптимальным (доказано, что не
существует алгоритма с лучшей асимптотикой), хотя в некоторых задачах он неприемлем (в случае
параллельной обработки или при online-обработке).
Описание
Алгоритм. Найдём самую левую и самую правую точки A и B (если таких точек несколько, то возьмём самую нижнюю
среди левых, и самую верхнюю среди правых). Понятно, что и A, и B обязательно попадут в выпуклую оболочку.
Далее, проведём через них прямую AB, разделив множество всех точек на верхнее и нижнее подмножества S1 и S2
 (точки, лежащие на прямой, можно отнести к любому множеству - они всё равно не войдут в оболочку). Точки A и B отнесём к обоим множествам. Теперь построим для S1 верхнюю оболочку, а для S2 - нижнюю оболочку, и объединим их, получив ответ. Чтобы получить, скажем, верхнюю оболочку, нужно отсортировать все точки по абсциссе, затем пройтись по всем точкам, рассматривая на каждом шаге кроме самой точки две предыдущие точки, вошедшие в оболочку. Если текущая тройка точек образует не правый поворот (что легко проверить с помощью Ориентированной площади), то ближайшего соседа нужно удалить из оболочки. В конце концов, останутся только точки, входящие в выпуклую оболочку.
Итак, алгоритм заключается в сортировке всех точек по абсциссе и двух (в худшем случае) обходах всех точек,
т.е. требуемая асимптотика O (N log N) достигнута.

Реализация
struct pt {
double x, y;
};
bool cmp (pt a, pt b) {
return a.x < b.x || a.x == b.x && a.y < b.y;
}
bool cw (pt a, pt b, pt c) {
return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool ccw (pt a, pt b, pt c) {
return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
void convex_hull (vector<pt> & a) {
if (a.size() == 1) return;
sort (a.begin(), a.end(), &cmp);
pt p1 = a[0], p2 = a.back();
vector<pt> up, down;
up.push_back (p1);
down.push_back (p1);
for (size_t i=1; i<a.size(); ++i) {
if (i==a.size()-1 || cw (p1, a[i], p2)) {
while (up.size()>=2 && !cw (up[up.size()-2], up[up.
size()-1], a[i]))
up.pop_back();
up.push_back (a[i]);
}
if (i==a.size()-1 || ccw (p1, a[i], p2)) {
while (down.size()>=2 && !ccw (down[down.size()-2],
down[down.size()-1], a[i]))
down.pop_back();
down.push_back (a[i]);
}
}
a.clear();
for (size_t i=0; i<up.size(); ++i)
a.push_back (up[i]);
for (size_t i=down.size()-2; i>0; --i)
a.push_back (down[i]);
}*/

struct point
{
	int x, y;
};

int OrientTriangl2(const point& p1, const point& p2, const point& p3)
{
	return (p1.x - p2.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p1.y-p2.y);
}

bool isInside(const point& p1, const point& p, const point& p2)
{
	return (p1.x <= p.x && p.x <= p2.x &&
		p1.y <= p.y && p.y <= p2.y);
}

void ConvexHullJarvis(const vector<point>& mas, vector<int>& convex_hull)
{
	// находим самую левую из самых нижних
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
	// эта точка точно входит в выпуклую оболочку
	convex_hull.push_back(base);

	int first = base;
	int cur = base;
	do
	{
		int next = (cur + 1) % n;
		for (int i = 0; i < n; i++)
		{
			int sign = OrientTriangl2(mas[cur], mas[next], mas[i]);
			// точка mas[i] находится левее прямой ( mas[cur], mas[next] )
			if (sign < 0) // обход выпуклой оболочки против часовой стрелки
				next = i;
			// точка лежит на прямой, образованной точками  mas[cur], mas[next]
			else if (sign == 0)
			{
				// точка mas[i] находится дальше, чем mas[next] от точки mas[cur]
				if (isInside(mas[cur], mas[next], mas[i]))
					next = i;
			}
		}
		cur = next;
		convex_hull.push_back(next);
	} while (cur != first);
}

int Task_13() {
	setlocale(LC_ALL, "Russian");
	cout << "Дано n точек на плоскости, построить их выпуклую оболочку.\n";
	int n;
	cout << "Введите n\n";
	vector<point> mas;
	vector<int> convex_hull;
	cin >> n;
	mas.resize(n);
	cout << "Введите координаты точек (x и y):\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " ------> ";
		cin >> mas[i].x >> mas[i].y;
	}
	ConvexHullJarvis(mas, convex_hull);
	cout << "Порядок обхода точек:\n";
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << " ------> " << convex_hull[i] << endl;
	}
	return 0;
}


void ConvexHullJarvisAlt(int n, const point mas[], point convex_hull[], int count[])
{
	// находим самую левую из самых нижних
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
	// эта точка точно входит в выпуклую оболочку
	convex_hull[base] = mas[base];
	count[base] = base;

	int first = base;
	int cur = base;
	do
	{
		int next = (cur + 1) % n;
		for (int i = 0; i < n; i++)
		{
			int sign = OrientTriangl2(mas[cur], mas[next], mas[i]);
			// точка mas[i] находится левее прямой ( mas[cur], mas[next] )
			if (sign < 0) // обход выпуклой оболочки против часовой стрелки
				next = i;
			// точка лежит на прямой, образованной точками  mas[cur], mas[next]
			else if (sign == 0)
			{
				// точка mas[i] находится дальше, чем mas[next] от точки mas[cur]
				if (isInside(mas[cur], mas[next], mas[i]))
					next = i;
			}
		}
		cur = next;
		convex_hull[next] = mas[next];
		count[next] = next;
	} while (cur != first);
}

int Task_13_alternative()
{
	setlocale(LC_ALL, "Russian");
	cout << "Дано n точек на плоскости, построить их выпуклую оболочку.\n";
	int n, i, j;
	cout << "Введите n\n";
	cin >> n;
	point* convex_hull = new point[n];
	point* Mass = new point[n];
	int* Count = new int[n];
	cout << "Введите координаты точек (x и y):\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " ------> ";
		cin >> Mass[i].x >> Mass[i].y;
	}
	ConvexHullJarvisAlt(n, Mass, convex_hull, Count);
	cout << "Порядок обхода точек:\n";
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << " ------> " << Count[i] << endl;
	}
	delete[] Mass;
	delete[] convex_hull;
	delete[] Count;
	return 0;
}