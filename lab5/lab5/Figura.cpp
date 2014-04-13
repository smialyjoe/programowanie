#include "stdafx.h"
#include "Figura.h"


Figura::Figura()
{
}


Figura::~Figura()
{
	delete[] wierzcholki;
	wierzcholki = NULL;
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

string Figura::ToFileString()
{
	string w = "";
	stringstream ss;
	ss << liczba_wierzcholkow;
	w.append(ss.str());
	w.append("|");
	for (int i = 0; i < liczba_wierzcholkow; i++)
		w.append(wierzcholki[i].ToString().append(";"));
	w = w.substr(0, w.size() - 1);
	w.append("");
	return w;
}

fstream &operator<<(fstream &stream, Figura& f)
{
	string w = "{";
	stringstream ss;
	ss << f.liczba_wierzcholkow;
	w.append(ss.str());
	w.append("|[");
	for (int i = 0; i < f.liczba_wierzcholkow; i++)
		w.append(f.wierzcholki[i].ToString().append(";"));
	w = w.substr(0, w.size() - 1);
	w.append("]}");
	//stream << w;
	return stream;
}

void Figura::convertFromString(string source, int boki)
{
	stringstream ss;
	ss << source;
	for (int i = 0; i < boki; i++)
	{
		string point;
		getline(ss, point, ';');
		Punkt p = Punkt(point);
		this->wierzcholki[i] = p;
	}
}

void Figura::copyConstructorHelper(const Figura& f)
{
	this->liczba_wierzcholkow = f.liczba_wierzcholkow;
	this->wierzcholki = new Punkt[liczba_wierzcholkow];
	for (int i = 0; i < liczba_wierzcholkow; i++)
	{
		this->wierzcholki[i] = Punkt(f.wierzcholki[i].X(), f.wierzcholki[i].Y());
	}
}