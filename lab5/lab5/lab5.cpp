// lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Czworokat.h"
#include "Trojkat.h"
#include "Osmiokat.h"
#include "Kwadrat.h"
#include <fstream>


bool SaveToFile(string filename);
Figura** ReadFromFile(string filename, int& size);

bool SaveToFile(string filename, Figura **tab, int size)
{
	fstream file;
	file.open(filename, ios_base::out);
	if (!file.good())
		 return false;
	file << size << endl; 
	for (int i = 0; i < size; i++)
		 {
		Figura *temp = tab[i];
		file << (*temp).ToFileString() << endl;
		}
	file.close();
	return true;
}

Figura** ReadFromFile(string filename, int& size)
{
	fstream file;
	file.open(filename, ios_base::in);
	if (!file.good())
		return NULL;
	stringstream ss;
	char source[100];
	file.getline(source, 100);
	ss << source;
	ss >> size;
	if (size <= 0)
		return NULL;
	Figura** tab = new Figura*[size];
	for (int i = 0; i < size; i++)
	{
		stringstream converter;
		file.getline(source, 100);
		string row;
		ss.clear();
		ss << source;
		getline(ss, row, '|');
		int boki;
		converter.str("");
		converter.clear();
		converter << row;
		converter >> boki;
		getline(ss, row, '|');

		Figura *new_figura;
		switch (boki)
		{
		case 3:
			new_figura = new Trojkat(row);
			break;
		case 4:
			new_figura = new Czworokat(row);
			break;
		case 8:
			new_figura = new Osmiokat(row);
			break;
		default:
			break;
		}
		tab[i] = new_figura;
	}
	return tab;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int rozmiar = 3;
	string filename = "plik.txt";
	Figura **figury = new Figura*[rozmiar];

	Czworokat cz1 = Czworokat();
	cz1.setPoint(0, 2, 0);
	cz1.setPoint(2, 2, 1);
	cz1.setPoint(2, 0, 2);
	cz1.setPoint(0, 0, 3);

	figury[0] = &cz1;

	Trojkat t = Trojkat();
	t.setPoint(0, 0, 0);
	t.setPoint(3, 3, 1);
	t.setPoint(6, 0, 2);

	figury[1] = &t;

	Osmiokat k = Osmiokat();
	k.setPoint(1, 3, 0);
	k.setPoint(3, 3, 1);
	k.setPoint(4, 2, 2);
	k.setPoint(4, 1, 3);
	k.setPoint(3, 0, 4);
	k.setPoint(1, 0, 5);
	k.setPoint(0, 1, 6);
	k.setPoint(0, 2, 7);

	figury[2] = &k;

	for (int i = 0; i < rozmiar; i++)
	{
		cout << figury[i]->ToString() << endl;
		cout << "obwod: " << figury[i]->getObwod() << endl;
		cout << "pole: " << figury[i]->getPole() << endl;
		cout << endl;
	}
	SaveToFile(filename, figury, rozmiar);

	Figura **nowe;
	nowe = ReadFromFile(filename, rozmiar);

	for (int i = 0; i < rozmiar; i++)
	{
		cout << nowe[i]->ToString() << endl;
		cout << "obwod: " << figury[i]->getObwod() << endl;
		cout << "pole: " << figury[i]->getPole() << endl;
		cout << endl;
	}

	system("pause");

	delete[] figury;
	figury = NULL;

	delete[] nowe;
	nowe = NULL;

	return 0;
}

