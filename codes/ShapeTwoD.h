#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ShapeTwoD
{
	protected:
		string name;
		bool containsWarpSpace;
	public:
		ShapeTwoD(string name, bool containsWarpSpace);
		
		string getName();
		bool getContainsWarpSpace();
		string toString();
		
		double computeArea();
		bool isPointInShape(int x, int y);
		bool isPointOnShape(int x, int y);
		
		void setName(string name);
		void setContainsWarpSpace(bool containsWarpSpace);
		
};

#endif
