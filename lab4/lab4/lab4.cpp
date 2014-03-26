// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

Fraction FractionalShortening(Fraction source);
int NWD(int a, int b);

Fraction* ReadFromFile(string filename, int &size)
{
	Fraction *frac = new Fraction();
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
	Fraction *tab = new Fraction[size];
	for (int i = 0; i < size; i++)
	{
		int d, n;
		stringstream converter;
		char row[100];
		file.getline(row, 100);
		string var;
		ss.clear();
		ss << row;
		getline(ss, var, '/');
		converter << var;
		converter >> n;
		converter.clear();
		getline(ss, var, ';');
		converter << var;
		converter >> d;
		converter.clear();
		Fraction temp = Fraction(n, d);
		tab[i] = temp;
	}
	file.close();
	return tab;
}

void SaveToFile(string filename, Fraction *tab, int size)
{
	fstream file;
	file.open(filename, ios_base::out);
	if (!file.good())
		return;
	file << size << endl;
	for (int i=0; i < size; i++)
	{
		file << tab[i].ToStringInproper() << endl;
	}
	file.close();
}

void CleanUp(Fraction *tab)
{
	delete[] tab;
	tab = NULL;
}

Fraction FractionalShortening(Fraction source)
{
	int n = source.getNumerator();
	int d = source.getDenominator();
	int nwd = NWD(n, d);
	Fraction frac = Fraction(n / nwd, d / nwd);
	return frac;
}

int NWD(int a, int b)
{
	while (b != 0)
	{
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "plik.txt";
		/*Fraction ulamek1 = Fraction(1, 2);
		Fraction ulamek2 = Fraction(1, 2);
		cout << ulamek1+ulamek2<<endl;
		cout << ulamek1 - ulamek2 << endl;
		cout << ulamek1 * ulamek2 << endl;
		cout << ulamek1 / ulamek2 << endl;
		cout << ulamek1.fsqrt();
		cout << endl<<ulamek1.ConvertToDecimalFraction()<<endl;

		cout << endl << endl;
		Fraction ulamek3 = Fraction(128, 16);
		ulamek3 = FractionalShortening(ulamek3);
		cout << ulamek3 << endl;
		cout << ulamek3.ToStringMixedNumber() << endl;
		*/
	int size = 0;
		Fraction *tab = ReadFromFile(filename, size);
		for (int i = 0; i < size; i++)
		{
			cout << tab[i] << endl;
		}
		SaveToFile(filename, tab, size + 2);
		CleanUp(tab);
	system("pause");
	return 0;
}

