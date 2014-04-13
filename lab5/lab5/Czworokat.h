#pragma once
#include "Figura.h"
#include <iostream>
#include "Wektor.h"

using namespace std;

class Czworokat : public Figura
{
private:
protected:
	
public:
	virtual void printWierzochlki();
	virtual float getPole();
	virtual bool SaveToFile(string filename);
	virtual bool ReadFromFile(string filename);

	Czworokat();
	Czworokat(string boki);
	Czworokat(const Czworokat &cz);
	//~Czworokat();
};

