#pragma once
class Coords
{
private:
	int x, y; //wsp�rz�dne macierzy
public:
	Coords();
	Coords(Coords &c);
	Coords(int x, int y);
	~Coords();

	void X(int x); //refactor do operator�w przypisania
	void Y(int y);
	int X();
	int Y();
	bool operator==(Coords &c);
};

