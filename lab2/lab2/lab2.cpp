// tratowski_lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int getTabSize();
float* generateTab(int size);

float* generateTab(int size)
{
	float *tab;
	bool isValid = false;


	tab = new float[size];

	for (int i = 0; i< size; i++)
	{
		cout << "Podaj liczbe rzeczywista ";
		cin >> tab[i];
	}
	return tab;

}

int getTabSize()
{
	bool isValid = false;
	int max;
	do
	{
		cout << "Podaj rozmiar tablicy ";
		cin >> max;
		if (max > 0)
			isValid = true;
		else
		{
			cout << "rozmiar tablicy nie moze byc mniejszy od zera" << endl;
		}
	} while (!isValid);
	return max;
}

void print_zad21(float* tab, int size, int precision)
{
	cout.precision(precision);
	cout.setf(ios::fixed);
	for (int i = 0; i<size; i++)
	{

		cout << tab[i] << " ";
	}
	cout << endl;
}


int zad22()
{
	//dorzuciæ dok³adnoœæ wyœwietlania po przecinku i pytaæ usera o to
	bool isValid = false;
	int precision;
	do
	{
		cout << "Podaj precyzje wyswietlania liczb po przecinku: ";
		cin >> precision;
		if (precision > 0)
			isValid = true;
		else
		{
			cout << "Precyzja nie moze byc mnniejsza od zera";
		}
	} while (!isValid);
	return precision;

}

void zad23(int precision)
{
	int size = getTabSize();
	float *tab = generateTab(size);

	for (int i = 0; i< size; i++)
	{
		int temp = (int)tab[i];
		cout.precision(precision);
		cout.setf(ios::fixed);
		cout << tab[i] << " ";
		cout.unsetf(ios::fixed);
		//cout.setf(ios::oct, ios::basefield);
		cout << oct << temp << " ";
		//cout.unsetf(ios::oct);
		//cout.setf(ios::hex, ios::basefield);
		cout << hex << temp << " ";
		//cout.unsetf(ios::hex);
		cout << endl;
	}

}

float* sort_zad24(float* tab, int size)
{
	bool asc = false;
	char input;
	cout << "Sortowanie [r]osnaco, czy [m]alejaco? ";
	cin >> input;
	if (input == 'r' || input == 'R')
		asc = true;
	if (input == 'm' || input == 'M')
		asc = false;
	float temp;
	bool swap = false;
	do
	{
		for (int i = 0; i<size - 1; i++)
		{
			if (asc)
				swap = (tab[i] > tab[i + 1]);
			else
				swap = (tab[i] < tab[i + 1]);
			if (swap)
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
		}
		size--;
	} while (size > 1);

	return tab;
}

void cleanUp(float *tab)
{
	delete[] tab;
	tab = NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	///tablica dynamiczna z max wsczytanym od usera na pocz¹tku
	//wycztywanie liczb rzeczywistych, zeby nie przekroczy³o tablicy

	int precision = 2;//zad22();
	int size = 3;//getTabSize();
	float * tab = generateTab(size);
	//zad21(precision);
	//zad23(precision);
	print_zad21(tab, size, precision);
	tab = sort_zad24(tab, size);
	print_zad21(tab, size, precision);
	cleanUp(tab);

	system("pause");

	return 0;
}

