#pragma once
#include "Punkt.h"
#include <string>
#include <iostream>

using namespace std;

class Figura
{
protected:
	int liczba_wierzcholkow;
	Punkt *wierzcholki; //za�o�enie: wierzoch�ki b�d� przechowywane zgodnie z ruchem wskaz�wek zegara, zaczynajac od lewego g�rnego wierzcho�ka
public:
	Figura();
	~Figura();

	virtual void printWierzochlki() = 0;
	virtual float getPole() = 0;
	virtual float getObwod() = 0;
	virtual string ToString() = 0;
	virtual bool SaveToFile(string filename)= 0;
	virtual bool ReadFromFile(string filename) =0;
	bool setPoint(Punkt p, int indeksWierzcholka);
	bool setPoint(float x, float y, int indeksWierzcholka);
};

