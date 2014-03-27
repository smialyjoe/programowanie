#include "stdafx.h"
#include "Wektor.h"


Wektor::Wektor()
{
}


Wektor::~Wektor()
{
}

Punkt Wektor::Start()
{
	return this->start;
}

void Wektor::Start(Punkt p)
{
	this->start = p;
}

float Wektor::X()
{
	return this->x;
}

void Wektor::X(float x)
{
	this->x = x;
}

float Wektor::Y()
{
	return this->y;
}

void Wektor::Y(float y)
{
	this->y = y;
}

float Wektor::getDlugosc()
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

float Wektor::operator*(Wektor &w)
{
	float wynik = this->x * w.X() + this->Y() * w.Y();
	return wynik;
}