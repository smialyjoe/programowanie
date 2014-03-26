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

string Figura::ToString()
{
	string w = "(";
	for (int i = 0; i < liczba_wierzcholkow; i++)
		w.append(wierzcholki[i].ToString().append(","));
	w = w.substr(0, w.size() - 1);
	w.append(")");
	return w;
}

float Figura::getObwod()
{
	float obwod = 0;
	for (int i = 0; i < liczba_wierzcholkow - 1; i++)
		obwod += wierzcholki[i].getDistanceToPoint(wierzcholki[i + 1]);
	obwod += wierzcholki[liczba_wierzcholkow - 1].getDistanceToPoint(wierzcholki[0]);
	return obwod;
}