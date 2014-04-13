#include "stdafx.h"
#include "Czworokat.h"


Czworokat::Czworokat()
{
	liczba_wierzcholkow = 4;
	wierzcholki = new Punkt[liczba_wierzcholkow];
}

Czworokat::Czworokat(string boki)
	:Czworokat()
{
	convertFromString(boki, liczba_wierzcholkow);
}

Czworokat::Czworokat(const Czworokat &cz)
{
	copyConstructorHelper(cz);
}

float Czworokat::getPole()
{
	//definiowanie przek¹tnych jako wektorów
	Wektor d1 = Wektor();
	d1.Start(wierzcholki[0]);
	d1.X(this->wierzcholki[2].X() - wierzcholki[0].X());
	d1.Y(wierzcholki[2].Y() - wierzcholki[0].Y());

	Wektor d2 = Wektor();
	d2.Start(wierzcholki[1]);
	d2.X(wierzcholki[3].X() - wierzcholki[1].X());
	d2.Y(wierzcholki[3].Y() - wierzcholki[1].Y());

	//obliczanie k¹ta miêdzy przek¹tnymi
	
	float skalar = d1*d2;
	float cos_alfa = skalar / (d1.getDlugosc() * d2.getDlugosc());
	float alfa = acos(cos_alfa);
	float sin_alfa = sin(alfa);

	float pole = 0.5 * d1.getDlugosc() * d2.getDlugosc() * sin_alfa;
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