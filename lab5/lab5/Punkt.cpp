#include "stdafx.h"
#include "Punkt.h"
#include <math.h>


Punkt::Punkt(float x, float y)
: x(x), y(y)
{
}

Punkt::Punkt()
{

}

Punkt::Punkt(string point)
{
	convertFromString(point);
}

float Punkt::X()
{
	return this->x;
}

float Punkt::Y()
{
	return this->y;
}

void Punkt::X(float x)
{
	this->x = x;
}

void Punkt::Y(float y)
{
	this->y = y;
}

float Punkt::getDistanceToPoint(Punkt p)
{
	return sqrt(pow(p.X() - this->X(), 2) + pow(p.Y() - this->Y(), 2));
}

string Punkt::ToString()
{
	stringstream ss;
	string w = "";
	ss << x;
	w.append("(").append(ss.str()).append(",");
	ss.clear();
	ss.str("");
	ss << y;
	w.append(ss.str()).append(")");
	return w;
}

Punkt Punkt::operator=(Punkt &p)
{
	this->x = p.X();
	this->y = p.Y();
	return *this;
}

void Punkt::convertFromString(string source)
{
	//source = source.substr(1, source.length - 1);
	string substring;
	stringstream ss, source_ss;
	source_ss << source.substr(1, source.length() - 1);
	getline(source_ss, substring, ',');
	ss.clear();
	ss.str("");
	ss << substring;
	float temp;
	ss >> temp;
	this->X(temp);
	ss.clear();
	ss.str("");
	substring = "";
	getline(source_ss, substring, ',');
	ss << substring;
	ss >> temp;
	this->Y(temp);
}

Punkt::~Punkt()
{
}
