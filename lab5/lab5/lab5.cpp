// lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Czworokat.h"
#include "Trojkat.h"
#include "Osmiokat.h"
#include "Kwadrat.h"
#include <fstream>


bool SaveToFile(string filename);

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

	system("pause");

	delete[] figury;
	figury = NULL;

	return 0;
}

