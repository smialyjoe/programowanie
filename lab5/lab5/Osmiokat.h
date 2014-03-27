#pragma once
#include "Figura.h"
#include "Czworokat.h"


class Osmiokat : public Figura
{
public:
	Osmiokat();

	//virtual void printWierzochlki();
	virtual float getPole();	
	//virtual bool SaveToFile(string filename) = 0;
	//virtual bool ReadFromFile(string filename) = 0;
};

