#pragma once
#include "Punkt.h"

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
};

