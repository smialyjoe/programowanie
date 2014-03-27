// lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Czworokat.h"
#include "Trojkat.h"


int _tmain(int argc, _TCHAR* argv[])
{

	int rozmiar = 2;
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

	for (int i = 0; i < rozmiar; i++)
	{
		cout << figury[i]->ToString() << endl;
		cout << "obwod: " << figury[i]->getObwod() << endl;
		cout << "pole: " << figury[i]->getPole() << endl;
		cout << endl;
	}
	
	system("pause");

	delete[] figury;
	figury = NULL;

	return 0;
}

