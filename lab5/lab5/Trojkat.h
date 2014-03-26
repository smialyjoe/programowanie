#pragma once
#include "Figura.h"

class Trojkat : public Figura
{
public:
	
	Trojkat();
	~Trojkat();

	virtual void printWierzochlki();
	virtual float getPole();
//	virtual float getObwod();
	virtual bool SaveToFile(string filename);
	virtual bool ReadFromFile(string filename) ;
};

