#include "Circle.h"

Circle::Circle(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
{
	setName(name);
	setContainsWarpSpace(containsWarpSpace);
}
string Circle::getName(){
	return name;
}
bool Circle::getContainsWarpSpace(){
	return containsWarpSpace;
}
string Circle::toString(){
	return "";
}
double Circle::computeArea(){
	//calculate radius by equation
	double area = 3.14159 * (stoi(radius) * stoi(radius));
	return area;
}
bool Circle::isPointInShape(int x, int y){
	return true;
}
bool Circle::isPointOnShape(int x, int y){
	return true;
}
void Circle::setName(string name){
	this->name = name;
}
void Circle::setContainsWarpSpace(bool containsWarpSpace){
	this->containsWarpSpace = containsWarpSpace;
}
void Circle::askCoordinates(){
	cross_x.clear();
	cross_y.clear();
	vertices.clear();
	bool error = false;
	while(!error){
	//asking user to input the coordinate
		cout << "Please enter x-ordinate of center: ";
		cin >> x_point;
		//checking if the user input is int or not
		if(check_int(x_point) == false){
			cout << "Invalid input. Type Again" << endl;
			continue;
		}
		
		cout << "Please enter y-ordinate of center: ";
		cin >> y_point;
		if(check_int(y_point) == false){
			cout << "Invalid input. Type Again" << endl;
				continue;
		}
		cout << "Please enter radius (units): ";
		cin >> radius;
		if(check_int(radius) == false){
			cout << "Invalid input. Type Again" << endl;
			continue;
		}
		
		error = true;
	}
	cross_x.push_back(stoi(x_point));
	cross_y.push_back(stoi(y_point));
	vertices.push_back("("+x_point+", "+y_point+")");
	cout << "\nRecords successfully stored. Going back to main menu..." << endl;
}
bool Circle::check_int(string input){
	for(int i = 0; i < input.length(); i++){
		if(isdigit(input[i]) == false){
			return false;
		}
	}
	return true;
}
vector<string> Circle::getPointOnPeri(){	
	pointOnPeri.clear();
	//center of circle plus or minus radius is point on parameter
	pointOnPeri.push_back("(" + to_string(cross_x[0] + stoi(radius)) + ", " + to_string(cross_y[0]) + ")");
	pointOnPeri.push_back("(" + to_string(cross_x[0] - stoi(radius)) + ", " + to_string(cross_y[0]) + ")");
	pointOnPeri.push_back("(" + to_string(cross_x[0]) + ", " + to_string(cross_y[0] + stoi(radius)) + ")");
	pointOnPeri.push_back("(" + to_string(cross_x[0]) + ", " + to_string(cross_y[0] - stoi(radius)) + ")");
	
	sort(pointOnPeri.begin(), pointOnPeri.end());
	
	
	return pointOnPeri;
}
vector<string> Circle::getVertices(){
	return vertices;
}
vector<string> Circle::getPointInPeri(){
	pointInPeri.clear();
	//make the circle into square and get all the coordinates inside and we get points inside shape
	int x1 = cross_x[0] - stoi(radius);
	int x2 = cross_x[0] + stoi(radius);
	int y1 = cross_y[0] - stoi(radius);
	int y2 = cross_y[0] + stoi(radius);
	
	for(int i = x1; i < x2-1; i++){
		for(int j = y1+1; j < y2; j++){
			if(i+1 == cross_x[0] and j == cross_y[0]){
				continue;
			}
			else{
				pointInPeri.push_back("("+to_string(i+1)+", "+to_string(j)+")");
			}
		}
	}
	
	return pointInPeri;
}

