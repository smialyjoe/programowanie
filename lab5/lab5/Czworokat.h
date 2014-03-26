#pragma once
#include "Figura.h"
#include <iostream>

using namespace std;

class Czworokat : public Figura
{
private:
protected:
	
public:
	virtual void printWierzochlki();
	virtual float getPole();
	virtual float getObwod();
	virtual string ToString();
	virtual bool SaveToFile(string filename);
	virtual bool ReadFromFile(string filename);

	Czworokat();
	~Czworokat();
};

