// lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Czworokat.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Czworokat cz1 = Czworokat();
	cz1.setPoint(0, 2, 0);
	cz1.setPoint(2, 2, 1);
	cz1.setPoint(2, 0, 2);
	cz1.setPoint(0, 0, 3);

	cout << cz1.ToString() << endl;

	system("pause");
	return 0;
}

