#pragma once
#include <iostream>
#include <unordered_map>
#include "Coords.h"
#include <string>
#include <sstream>

using namespace std;

class Matrix
{
private:
	size_t getHash(Coords c);
	typedef int(*MatrixHash)(Coords);
	unordered_map<Coords, float, MatrixHash> matrix;
	Coords max_coords;
	
public:
	Matrix(int x_size, int y_size);
	~Matrix();

	float GetValue(int x, int y); //dorzuciæ przeci¹¿ony operator []
	void SetValue(int x, int y); //przeci¹¿ony operator []
	string ToString();
	friend ostream& operator<<(ostream& stream, Matrix &m);
};

