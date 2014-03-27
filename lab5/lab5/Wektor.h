#pragma once
#include "Punkt.h"
#include <math.h>

class Wektor
{
private:
	Punkt start; 
	float x, y; //wsp�rz�dne wektora
public:
	Wektor();
	~Wektor();

	Punkt Start();
	void Start(Punkt p);
	float X();
	void X(float x);
	float Y();
	void Y(float y);
	float getDlugosc();

	//przeci��ony operator iloczynu skalarnego wektor�w
	float operator*(Wektor &w);
};

