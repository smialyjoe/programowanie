#include "stdafx.h"
#include "Osmiokat.h"


Osmiokat::Osmiokat()
{
	liczba_wierzcholkow = 8;
	wierzcholki = new Punkt[liczba_wierzcholkow];
}

Osmiokat::Osmiokat(const Osmiokat &o)
{
	copyConstructorHelper(o);
}

Osmiokat::Osmiokat(string boki)
:Osmiokat()
{
	convertFromString(boki, liczba_wierzcholkow);
}


float Osmiokat::getPole()
{
	Czworokat cz1 = Czworokat();
	for (int i = 0; i < 4; i++)
		cz1.setPoint(wierzcholki[i], i);
	Czworokat cz2 = Czworokat();
	cz2.setPoint(wierzcholki[7], 0);
	cz2.setPoint(wierzcholki[3], 1);
	cz2.setPoint(wierzcholki[4], 2);
	cz2.setPoint(wierzcholki[6], 3);

	Czworokat cz3 = Czworokat();
	cz3.setPoint(wierzcholki[6], 0);
	cz3.setPoint(wierzcholki[3], 1);
	cz3.setPoint(wierzcholki[4], 2);
	cz3.setPoint(wierzcholki[5], 3);

	float pole = cz1.getPole() + cz2.getPole() + cz3.getPole();
	return pole;
}

void Osmiokat::printWierzochlki()
{
	cout << this->ToString();
}

bool Osmiokat::SaveToFile(string filename) 
{
	return true;
}

bool Osmiokat::ReadFromFile(string filename)
{
	return true;
}