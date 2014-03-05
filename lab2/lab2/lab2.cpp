// tratowski_lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <Windows.h>

using namespace std;

int getTabSize();
float* generateTab(int size);
bool table_contains(float number, float* tab, int size);
float get_random_number(int limiter);

float* generateTab(int size, bool random)
{
	float *tab;
	bool isValid = false;


	tab = new float[size];
	if (random)
		for (int i = 0; i < size; i++)
			tab[i] = get_random_number(1000);
	else
		for (int i = 0; i< size; i++)
		{
			
			cout << "Podaj liczbe rzeczywista ";
			cin >> tab[i];
		}
	return tab;

}

float get_random_number(int limiter)
{
	
	static unsigned int nSeed = 5323;
	nSeed = (8253729 * nSeed + 2396403);
	

	//srand(time(0));
	////srand(rand());
	float result = ((float)(nSeed % limiter));
	result += ((float)(nSeed % 1000) / 1000);
	//Sleep(200);
	return result;
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
	cout << "----------------------" << endl;
	cout.precision(precision);
	cout.setf(ios::fixed);
	for (int i = 0; i<size; i++)
	{

		cout << tab[i] << " ";
	}
	cout << endl;
	cout << "----------------------" << endl;
	
}


int get_precision_zad22()
{
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

void print_in_many_formats_zad23(float *tab, int size, int precision)
{
	cout << setw(10) << internal << "dec"; 
	cout << setw(10) << internal << "oct";
	cout << setw(10) << internal << "hex";
	cout << endl;
	for (int i = 0; i< size; i++)
	{
		int temp = (int)tab[i];
		cout.precision(precision);
		cout << setw(10)<< right << fixed << tab[i];
		cout << setw(10) << right<< oct << temp;
		cout <<setw(10) << right << hex << temp;
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

float* get_double_tab_zad25(float* tab, int size, bool random)
{
	int double_size = size * 2;
	float *tab_copy = generateTab(double_size, random);
	return tab_copy;

}

void copy_tables_zad25(float* tab, int tab_size, float* tab_copy, int tab_copy_size)
{
	int pointer = 0;
	for (int i = 0; i < tab_size; i++)
	{
		if (!table_contains(tab[i], tab_copy, tab_copy_size))
		{
			tab_copy[pointer] = tab[i];
			pointer++;
		}
	}
}

bool table_contains(float number, float* tab, int size)
{
	for (int j = 0; j < size; j++)
	{
		if (tab[j] == number)
			return true;		
	}
	return false;
}

void cleanUp(float *tab)
{
	delete[] tab;
	tab = NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int precision = get_precision_zad22();
	int size = getTabSize();
	float * tab = generateTab(size, true);

	cout << "Wprowadzone liczby" << endl;
	print_zad21(tab, size, precision);

	cout << "Wyswietlenie wprawdzonych liczb w roznych formatach" << endl;
	print_in_many_formats_zad23(tab, size, precision);

	tab = sort_zad24(tab, size);
	cout << "Posortowane liczby" <<endl;
	print_zad21(tab, size, precision);

	cout << "Podwojny rozmiar tablicy" << endl;
	int double_size = size * 2;
	float* tab_copy = get_double_tab_zad25(tab, size, true);
	print_zad21(tab_copy, double_size, precision);

	cout << "Kopiowanie tablic" << endl;
	copy_tables_zad25(tab, size, tab_copy, double_size);
	print_zad21(tab, size, precision);
	print_zad21(tab_copy, double_size, precision);

	
	tab_copy = sort_zad24(tab_copy, double_size);
	cout << "Posortowana podwojona tablica" << endl;
	print_zad21(tab_copy, double_size, precision);

	cleanUp(tab);
	cleanUp(tab_copy);

	system("pause");

	return 0;
}

