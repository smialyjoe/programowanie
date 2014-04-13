#include "stdafx.h"
#include "Trojkat.h"


Trojkat::Trojkat()
{
	liczba_wierzcholkow = 3;
	wierzcholki = new Punkt[liczba_wierzcholkow];
}

Trojkat::Trojkat(string boki)
	:Trojkat()
{
	convertFromString(boki, liczba_wierzcholkow);
}

Trojkat::Trojkat(const Trojkat &t)
{
	copyConstructorHelper(t);
}

void Trojkat::printWierzochlki()
{
	cout << this->ToString();
}

float Trojkat::getPole()
{
	float podstawa = wierzcholki[0].getDistanceToPoint(wierzcholki[2]);
	Punkt polowa_podstawy = Punkt((wierzcholki[2].X() - wierzcholki[0].X()) / 2,
		(wierzcholki[2].Y() - wierzcholki[0].Y()) / 2);
	float h = wierzcholki[1].getDistanceToPoint(polowa_podstawy);
	return podstawa * h / 2;
}


bool Trojkat::SaveToFile(string filename)
{
	return true;
}
bool Trojkat::ReadFromFile(string filename)
{
	return true;
}