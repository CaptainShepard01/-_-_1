#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <vector>
using namespace std;

struct point;

int NotTriangola(point, point, point);
float SquareOfTriangola(point, point, point);
int Task_1();
int Task_13();




float OrientTriangl2(const point& p1, const point& p2, const point& p3);
bool isInside(const point& p1, const point& p, const point& p2);
void ConvexHullJarvis(const vector<point>& mas, vector<int>& convex_hull);

int Task_13_alternative();
void ConvexHullJarvisAlt(int &t, int n, const point mas[], int count[]);