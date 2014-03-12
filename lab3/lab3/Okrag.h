#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

class Okrag
{
private:
	int x, y;
	float r;
public:
	Okrag();
	Okrag(int x, int y, float r);
	float GetPole();
	float GetObwod();
	void PrintObwod();
	void PrintPole();
	void PrintKolo();
	~Okrag();


};

