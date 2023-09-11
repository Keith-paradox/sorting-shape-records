#ifndef CROSS_H
#define CROSS_H

#include "ShapeTwoD.h"

using namespace std;

class Cross: public ShapeTwoD
{
	protected:
		string name;
		bool containsWarpSpace;
		
		string x_point;
		string y_point;
		int side_1;
		int side_2;
		
		vector<int> cross_x;
		vector<int> cross_y;
		
		vector<string> vertices;
		vector<string> pointOnPeri;
		vector<string> pointInPeri;
		
		vector<int> x;
		vector<int> y;
		
		vector<int> area_x;
		vector<int> area_y;
		vector<string> area_XandY;
	public:
		Cross(string name, bool containsWarpSpace);
		
		string getName();
		bool getContainsWarpSpace();
		string toString();
		
		double computeArea();
		bool isPointInShape(int x, int y);
		bool isPointOnShape(int x, int y);
		
		void setName(string name);
		void setContainsWarpSpace(bool containsWarpSpace);
		
		void askCoordinates();
		bool check_int(string input);
		
		void sortXandY();
		void sortXandY_two();
		vector<string> getPointOnPeri();
		vector<string> getVertices();
		vector<string> getPointInPeri();
};

#endif
