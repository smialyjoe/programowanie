#include "stdafx.h"
#include "Trojkat.h"


Trojkat::Trojkat()
{
	liczba_wierzcholkow = 3;
	wierzcholki = new Punkt[liczba_wierzcholkow];
}


Trojkat::~Trojkat()
{
	delete[] wierzcholki;
	wierzcholki = NULL;
}

float Trojkat::getObwod()
{
	float obwod = wierzcholki[0].getDistanceToPoint(wierzcholki[1])
		+ wierzcholki[1].getDistanceToPoint(wierzcholki[2])
		+ wierzcholki[2].getDistanceToPoint(wierzcholki[0]);
	return obwod;
}

void Trojkat::printWierzochlki()
{
	cout << this->ToString();
}

float Trojkat::getPole()
{
	return -1;
}
string Trojkat::ToString()
{
	
}

bool SaveToFile(string filename);
bool ReadFromFile(string filename);