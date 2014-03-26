#include "stdafx.h"
#include "Czworokat.h"


Czworokat::Czworokat()
{
	liczba_wierzcholkow = 4;
	wierzcholki = new Punkt[liczba_wierzcholkow];
}


Czworokat::~Czworokat()
{
	delete[] wierzcholki;
	wierzcholki = NULL;
}
//
//float Czworokat::getObwod()
//{
//	float obwod = wierzcholki[0].getDistanceToPoint(wierzcholki[1])
//		+ wierzcholki[1].getDistanceToPoint(wierzcholki[2])
//		+ wierzcholki[2].getDistanceToPoint(wierzcholki[3])
//		+ wierzcholki[3].getDistanceToPoint(wierzcholki[0]);
//	return obwod;
//}

float Czworokat::getPole()
{
	float d1 = wierzcholki[0].getDistanceToPoint(wierzcholki[2]);
	float d2 = wierzcholki[1].getDistanceToPoint(wierzcholki[3]);
	//todo; Policzyæ sinus kata miedzy przekatnymi
	return -1;
}


void Czworokat::printWierzochlki()
{
	cout << this->ToString();
}

bool Czworokat::SaveToFile(string filename)
{
	return true;
}

bool Czworokat::ReadFromFile(string filename)
{
	return true;
}