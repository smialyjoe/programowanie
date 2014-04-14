// lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"



int _tmain(int argc, _TCHAR* argv[])
{
	int max_x, max_y;
	max_x = max_y = 10;
	Matrix m = Matrix(max_x, max_y);
	cout << m << endl;
	system("pause");
	return 0;
}