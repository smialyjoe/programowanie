// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Okrag.h"
#include <string>
#include <fstream>

using namespace std;

float getDistanceBetweenCircleCenters(Okrag o1, Okrag o2);

bool SaveToFile(string filename, Okrag* tab, int size)
{
	fstream file;
	file.open(filename, ios_base::out);
	if (!file.good())
		return false;
	file << size << endl;
	for (int i = 0; i < size; i++)
	{
		Okrag temp = tab[i];
		file << temp.X() << ";" << temp.Y() << "," << temp.R() << endl;
	}
	file.close();
	return true;
}

Okrag* REadFromFile(string filename, Okrag* tab, int size)
{
	tab = new Okrag[size];
	fstream file;
	file.open(filename, ios_base::in);
	if (!file.good())
		return tab;
	char source[100];
	string sour;
	file.getline(source,100);
	int s = (int)(*source) - 48;
	bool flag = true;
	int i = 0;
	while (flag)
	{
		char b = source[i];
		i++;
	}
	for (int i = 0; i < size; i++)
	{
		file.get(source, '#');
	}
}

int getRandomInt(int limiter)
{
	static unsigned int nSeed = 5323;
	nSeed = (8253729 * nSeed + 2396403);
	float result = ((nSeed % limiter));
	result += ((nSeed % 1000) / 1000);
	return result;
}

float getRandomFloat(int limiter)
{
	static unsigned int nSeed = 5323;
	nSeed = (8253729 * nSeed + 2396403);
	float result = ((float)(nSeed % limiter));
	result += ((float)(nSeed % 1000) / 1000);
	return result;
}

void checkCommonPoints(Okrag o1, Okrag o2)
{
	/*
		|o1,o2| = r1 + r2 = jeden punkt wspólny
		|o1,o2| > r1 + r2 = brak punktów wspólnych
		|o1,o2| < r1 + r2 = dwa punkty wspólne
		|o1,o2| =  0 ^ r1 = r2 = wszystkie punkty wspólne
	*/

	float suma_r = o1.R() + o2.R();
	float distance = getDistanceBetweenCircleCenters(o1, o2);

	cout << "Sprawdzanie punktow wspolnych dla okregow" << endl;
	cout << "o1:" << endl;
	o1.PrintKolo();
	cout << "o2" << endl;
	o2.PrintKolo();
	cout << endl;

	if (distance == 0 && suma_r == 2 * o1.R())
		cout << "Okregi maja nieskonczenie wiele punktow wspolnych" << endl;
	else
	{
		if (suma_r == distance)
			cout << "Okregi maja jeden punkt wspolny"<<endl;
		if (suma_r < distance)
			cout << "Okregi nie maja punktow wspolnych"<<endl;
		if (suma_r > distance)
			cout << "Okregi maja dwa punkty wspolne" << endl;
	}
}

float getDistanceBetweenCircleCenters(Okrag o1, Okrag o2)
{
	return sqrt(pow(o2.X() - o1.X(), 2) + pow(o2.Y() - o1.Y(), 2));
}

int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "plik.txt";
	
	int size = 0;
	cout << "Podaj rozmiar tablicy: " << endl;
	cin >> size;
	Okrag* tab = new Okrag[size];
	//REadFromFile(filename, tab, size);
	for (int i = 0; i < size; i++)
	{
		int x = getRandomInt(100), y = getRandomInt(100);
		float r = getRandomFloat(100);
		Okrag kolo1 = Okrag(x, y, r);
		kolo1.PrintKolo();
		tab[i] = kolo1;
	}
	int o1 = getRandomInt(size -1);
	int o2 = getRandomInt(size -1);
	checkCommonPoints(tab[o1], tab[o2]);
	//SaveToFile(filename, tab, size);
	delete[] tab;
	tab = NULL;
	system("pause");
	return 0;
}

