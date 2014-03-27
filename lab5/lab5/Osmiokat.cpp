#include "stdafx.h"
#include "Osmiokat.h"


Osmiokat::Osmiokat()
{
	liczba_wierzcholkow = 8;
	wierzcholki = new Punkt[liczba_wierzcholkow];
}


float Osmiokat::getPole()
{
	Czworokat cz1 = Czworokat();
	for (int i = 0; i < 4; i++)
		cz1.setPoint(wierzcholki[0], 0);
	Czworokat cz2 = Czworokat();
	for (int i = 0; i < 4; i++)
		cz2.setPoint(wierzcholki[0], 0);
	return cz1.getPole() + cz2.getPole();
}
