#pragma once
class Coords
{
private:
	int x, y; //wspó³rzêdne macierzy
public:
	Coords();
	Coords(Coords &c);
	Coords(int x, int y);
	~Coords();

	void X(int x); //refactor do operatorów przypisania
	void Y(int y);
	int X();
	int X() const;
	int Y();
	int Y() const;
	bool operator==(const Coords &c) const;
};

