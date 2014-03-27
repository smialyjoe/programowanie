#include "stdafx.h"
#include "Kwadrat.h"


Kwadrat::Kwadrat(float x, float y, float dlBoku)
	:Czworokat()
{
	Punkt start = Punkt(x, y);
	wierzcholki[0] = start;
	start.X(start.X() + dlBoku);
	wierzcholki[1] = start;
	start.Y(start.Y() - dlBoku);
	wierzcholki[2] = start;
	start.X(start.X() - dlBoku);
	wierzcholki[3] = start;
}


