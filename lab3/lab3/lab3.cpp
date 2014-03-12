// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Okrag.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int x, y;
	float r;
	cout << "Podaj x: ";
	cin >> x;
	cout << "Podaj y: ";
	cin >> y;
	cout << "Podaj promien: ";
	cin >> r;
	Okrag *kolo1 = new Okrag(x, y, r);
	kolo1->PrintKolo();
	system("pause");
	return 0;
}

