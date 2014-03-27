#include "stdafx.h"
#include "Czworokat.h"


Czworokat::Czworokat()
{
	liczba_wierzcholkow = 4;
	wierzcholki = new Punkt[liczba_wierzcholkow];
}


float Czworokat::getPole()
{
	//dzielimy czwrok¹t na 4 trójk¹ty i sumujemy ich pola
	//nie najelegantsze rozwi¹zanie, ale nie ma wektorów

	Punkt s1 = Punkt(abs(wierzcholki[2].X() - wierzcholki[0].X()) / 2, abs(wierzcholki[2].Y() - wierzcholki[0].Y()) / 2);
	Punkt s2 = Punkt(abs(wierzcholki[3].X() - wierzcholki[1].X()) / 2, abs(wierzcholki[3].Y() - wierzcholki[1].Y()) / 2);
	
	if (s1.X() != s2.X() && s1.Y() != s2.Y())
		return -1;
	float pole = 0;
	Trojkat *temp = new Trojkat();
	temp->setPoint(wierzcholki[0], 0);
	temp->setPoint(wierzcholki[1], 1);
	temp->setPoint(s1, 2);
	pole += temp->getPole();

	delete temp;
	temp = new Trojkat();
	temp->setPoint(wierzcholki[1], 0);
	temp->setPoint(wierzcholki[2], 1);
	temp->setPoint(s1, 2);
	pole += temp->getPole();

	delete temp;
	temp = new Trojkat();
	temp->setPoint(wierzcholki[2], 0);
	temp->setPoint(wierzcholki[3], 1);
	temp->setPoint(s1, 2);
	pole += temp->getPole();

	delete temp;
	temp = new Trojkat();
	temp->setPoint(wierzcholki[3], 0);
	temp->setPoint(wierzcholki[0], 1);
	temp->setPoint(s1, 2);
	pole += temp->getPole();
	return pole;
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