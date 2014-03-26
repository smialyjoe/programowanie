#include "stdafx.h"
#include "Figura.h"


Figura::Figura()
{
}


Figura::~Figura()
{
}

bool Figura::setPoint(Punkt p, int indeksWierzcholka)
{
	if (indeksWierzcholka > liczba_wierzcholkow - 1)
		return false;
	if (wierzcholki == NULL)
		return false;
	wierzcholki[indeksWierzcholka] = p;
	return true;
}

bool Figura::setPoint(float x, float y, int indeksWierzcholka)
{
	Punkt p = Punkt(x, y);
	return setPoint(p, indeksWierzcholka);
}