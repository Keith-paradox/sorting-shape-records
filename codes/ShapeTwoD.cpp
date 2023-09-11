#include "ShapeTwoD.h"

ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace)
{
	setName(name);
	setContainsWarpSpace(containsWarpSpace);
}

string ShapeTwoD::getName()
{

	return name;
};

bool ShapeTwoD::getContainsWarpSpace()
{

	return containsWarpSpace;
};

string ShapeTwoD::toString()
{	
	return "";
};

double ShapeTwoD::computeArea()
{
	double area;
	return area;
};

bool ShapeTwoD::isPointInShape(int x, int y)
{

	return true;
};

bool ShapeTwoD::isPointOnShape(int x, int y)
{

	return true;
};

void ShapeTwoD::setName(string name)
{
	this->name = name;

};
void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
	this->containsWarpSpace = containsWarpSpace;
};

