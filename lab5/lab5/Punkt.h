#pragma once
#include <string>
#include <sstream>

using namespace std;

class Punkt
{
private:
	float x, y;
public:

	Punkt(float x, float y);
	Punkt();
	float X();
	float Y();
	void X(float x);
	void Y(float y);
	float getDistanceToPoint(Punkt p);
	string ToString();
	~Punkt();
	Punkt operator=(Punkt &p);
};

