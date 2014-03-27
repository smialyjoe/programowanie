#pragma once
#include "Punkt.h"
#include <math.h>

class Wektor
{
private:
	Punkt start; 
	float x, y; //wspó³rzêdne wektora
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

	//przeci¹¿ony operator iloczynu skalarnego wektorów
	float operator*(Wektor &w);
};

