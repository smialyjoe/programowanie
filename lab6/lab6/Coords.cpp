#include "stdafx.h"
#include "Coords.h"


Coords::Coords()
{
	x = 0;
	y = 0;
}

Coords::Coords(Coords &c)
{
	this->x = c.X();
	this->y = c.Y();
}

Coords::Coords(int x, int y)
{
	/*if (x >= 0 && y >= 0)
	{
		this->y = y;
		this->x = x;
	}
	else
		x = y = 0;*/
	this->X(x);
	this->Y(y);
}

int Coords::X()
{
	return this->x;
}

int Coords::Y()
{
	return this->y;
}

void Coords::X(int x)
{
	if (x >= 0)
		this->x = x; 
	//else rzuæ wyj¹tkiem?
}

void Coords::Y(int y)
{
	if (this->y >= 0)
	{
		this->y = y;
	}
}

bool Coords::operator==(Coords &c)
{
	int x = c.X();
	int y = c.Y();
	if (this->X() == c.X() && this->Y() == c.Y())
		return true;
	return false;
}

Coords::~Coords()
{
}
