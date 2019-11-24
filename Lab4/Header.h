#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <vector>
using namespace std;

void Palindromer();
bool ok(char* s, int a, int b);

struct Triangola;
void Triangola_Creator();
bool IsAcute(int a, int b, int c);
bool IsNotRepeated(Triangola x, Triangola* y, int l, int z);
bool IsTriangola(int a, int b, int c);
int sum(int a, int b, int c);
int multiplication(int a, int b, int c);
