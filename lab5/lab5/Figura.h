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
	virtual ~Figura();

	virtual void printWierzochlki() = 0;
	virtual float getPole() = 0;
	virtual float getObwod();
	virtual string ToString();
	string ToFileString();
	void copyConstructorHelper(const Figura& f);
	virtual bool ReadFromFile(string filename) =0;
	bool setPoint(Punkt p, int indeksWierzcholka);
	bool setPoint(float x, float y, int indeksWierzcholka);
	friend fstream &operator<<(fstream &stream, Figura& f);
	void convertFromString(string source, int boki);

};

