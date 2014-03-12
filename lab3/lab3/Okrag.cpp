#include "stdafx.h"
#include "Okrag.h"


Okrag::Okrag()
{
	x = 0;
	y = 0;
	r = 1;
}

Okrag::Okrag(int x =0 , int y=0, float r=1) : x(x), y(y)
{
	if (r <= 0)
	{
		cout << "Promien nie moze byc mniejszy od zera"<<endl;
		return;
	}
	this->r = r;
}

float Okrag::GetPole()
{
	return (float)(M_PI * pow(r, 2));
}

float Okrag::GetObwod()
{
	return r* 2 * M_PI;
}

void Okrag::PrintObwod()
{
	cout << "Obwod okregu: "<< setprecision(4) << this->GetObwod()<<endl;
}

void Okrag::PrintPole()
{
	cout << "Pole okregu: "<< setprecision(4) << this->GetPole() << endl;	
}

int Okrag::X()
{
	return x;
}

int Okrag::Y()
{
	return y;
}

float Okrag::R()
{
	return r;
}

void Okrag::PrintKolo()
{
	cout << setprecision(4) << "wspolrzedne srodka: (" << x << "," << y << ")" << endl;
	cout << setprecision(4) << "Dlugosc promienia: " << r << endl;
}

Okrag::~Okrag()
{
}
