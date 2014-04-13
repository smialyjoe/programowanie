#pragma once
#include "Figura.h"
#include "Czworokat.h"


class Osmiokat : public Figura
{
public:
	Osmiokat();
	Osmiokat(string boki);
	Osmiokat(const Osmiokat &o);
	virtual float getPole();	
	virtual void printWierzochlki();
	virtual bool SaveToFile(string filename);
	virtual bool ReadFromFile(string filename);
};

