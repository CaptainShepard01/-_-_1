#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <vector>
using namespace std;

int NotTriangola(float x1, float y1, float x2, float y2, float x3, float y3);
float SquareOfTriangola(float x1, float y1, float x2, float y2, float x3, float y3);
int Task_1();
int Task_13();

struct point;


int OrientTriangl2(const point& p1, const point& p2, const point& p3);
bool isInside(const point& p1, const point& p, const point& p2);
void ConvexHullJarvis(const vector<point>& mas, vector<int>& convex_hull);

