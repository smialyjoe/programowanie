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

int Coords::X() const
{
	return x;
}

int Coords::Y()
{
	return this->y;
}

int Coords::Y() const
{
	return y;
}

void Coords::X(int x)
{
	if (x >= 0)
		this->x = x; 
	//else rzuæ wyj¹tkiem?
}

void Coords::Y(int y)
{
	if (y >= 0)
	{
		this->y = y;
	}
}

bool Coords::operator==(const Coords &c) const
{
	//int x = c.X();
	//int y = c.Y();
	if (x == c.x && y == c.y)
		return true;
	return false;
}



Coords::~Coords()
{
}
