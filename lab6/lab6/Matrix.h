#pragma once
#include <iostream>
#include <unordered_map>
#include "Coords.h"
#include <string>
#include <sstream>
#include "MHash.h"

using namespace std;

template<>
struct hash<Coords>{
public:
	size_t operator()(const Coords& k) const
	{
		size_t h1 = hash<int>()(k.X());
		size_t h2 = hash<int>()(k.Y());
		return h1 ^ (h2 << 1);
	}
};

class Matrix
{
private:
	
	unordered_map<Coords, float> matrix;
	Coords max_coords;
	
public:
	Matrix(int x_size, int y_size);
	~Matrix();

	float GetValue(int x, int y); //dorzuciæ przeci¹¿ony operator []
	void SetValue(int x, int y); //przeci¹¿ony operator []
	string ToString();
	friend ostream& operator<<(ostream& stream, Matrix &m);

};

