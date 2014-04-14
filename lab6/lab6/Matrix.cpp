#include "stdafx.h"
#include "Matrix.h"


Matrix::Matrix(int x_size, int y_size)
{
	max_coords = Coords(x_size, y_size);
	for (int i = 0; i < max_coords.X(); i++)
	{
		for (int j = 0; j < max_coords.Y(); j++)
		{
			Coords temp(i, j);
			//std::pair<Coords, float> pair(t1, 0);
			//std::pair<Coords, float> pair = std::make_pair<Coords, float>(temp, 0.0f); //problem z hashowaniem
			matrix.emplace(std::make_pair(temp, 0));
			
		}
	}
}


Matrix::~Matrix()
{
}

string Matrix::ToString()
{
	string m;
	for (int i = 0; i < max_coords.X(); i++)
	{
		for (int j = 0; j < max_coords.Y(); j++)
		{
			Coords temp = Coords(i, j);
			stringstream ss;
			ss << matrix.at(temp);
			m.append(ss.str());
			ss.str("");
			ss.clear();
		}
		m.append(";");
	}
	return m;
}

void Matrix::SetValue(int x, int y)
{
	
}

float Matrix::GetValue(int x, int y)
{
	Coords temp = Coords(x, y);
	float value = matrix.find(temp)->second;
	return value;
}

ostream& operator<<(ostream& stream, Matrix &m)
{
	string res = m.ToString();
	stream << res;
	return stream;
}


