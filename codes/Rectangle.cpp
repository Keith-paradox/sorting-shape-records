#include "Rectangle.h"

Rectangle::Rectangle(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
{
	setName(name);
	setContainsWarpSpace(containsWarpSpace);
}
string Rectangle::getName(){
	return name;
}
bool Rectangle::getContainsWarpSpace(){
	return containsWarpSpace;
}
string Rectangle::toString(){
	return "";
}
double Rectangle::computeArea(){
	side_1 = x[1] - x[0];
	side_2 = y[1] - y[0];
	double area = side_1 * side_2;
	return area;
}
bool Rectangle::isPointInShape(int x, int y){
	return true;
}
bool Rectangle::isPointOnShape(int x, int y){
	return true;
}
void Rectangle::setName(string name){
	this->name = name;
}
void Rectangle::setContainsWarpSpace(bool containsWarpSpace){
	this->containsWarpSpace = containsWarpSpace;
}
void Rectangle::askCoordinates(){
	int count = 1;
	cross_x.clear();
	cross_y.clear();
	vertices.clear();
	while(count <= 4){
		bool error = false;
		while(!error){
			//asking the user the coordinates
			cout << "\nPlease enter x-cooridnate of pt"+to_string(count)+" : ";
			cin >> x_point;
			//checking if the user input is int or not
			if(check_int(x_point) == false){
				cout << "Invalid input. Type Again" << endl;
				continue;
			}
			
			cout << "Please enter y-cooridnate of pt"+to_string(count)+" : ";
			cin >> y_point;
			if(check_int(y_point) == false){
				cout << "Invalid input. Type Again" << endl;
				continue;
			}
			error = true;
			
		}
		cross_x.push_back(stoi(x_point));
		cross_y.push_back(stoi(y_point));
		vertices.push_back("("+x_point+", "+y_point+")");
		count++;
	}
	if(checkInputs()){
		cout << "\nRecords successfully stored. Going back to main menu..." << endl;
	}
	else{
		askCoordinates();
	}
	
}
bool Rectangle::check_int(string input){
	for(int i = 0; i < input.length(); i++){
		if(isdigit(input[i]) == false){
			return false;
		}
	}
	return true;
}
bool Rectangle::checkInputs(){
	x.clear();
	y.clear();
	for(int i = 0; i < cross_x.size(); i++){
		if(count(x.begin(),x.end(),cross_x[i])){
			continue;
		}
		else{
			x.push_back(cross_x[i]);
		}
	}
	for(int i = 0; i < cross_y.size(); i++){
		if(count(y.begin(),y.end(),cross_y[i])){
			continue;
		}
		else{
			y.push_back(cross_y[i]);
		}
	}
	//remove the duplicates from user input x and y and if there is only 2 from each of them its square or rectangle
	if(x.size() == 2 and y.size() == 2){
	}
	else{
		cout << "The cooridnates you typed in are not of Rectangle" << endl;
		return false;
	}
	
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	
	return true;
}
vector<string> Rectangle::getPointOnPeri(){	
	pointOnPeri.clear();
	//x++ or y++ from one coordinate to other and we get the points on perimeter
	for(int j = x[0]+1; j < x[1]; j++){
		pointOnPeri.push_back("(" + to_string(j) + ", " + to_string(y[0]) + ")");
		pointOnPeri.push_back("(" + to_string(j) + ", " + to_string(y[1]) + ")");
	}
	
		
	for(int j = y[0]+1; j < y[1]; j++){
		pointOnPeri.push_back("(" + to_string(x[0]) + ", " + to_string(j) + ")");
		pointOnPeri.push_back("(" + to_string(x[1]) + ", " + to_string(j) + ")");
	}
	
	sort(pointOnPeri.begin(), pointOnPeri.end());
	
	
	return pointOnPeri;
}
vector<string> Rectangle::getVertices(){
	return vertices;
}
vector<string> Rectangle::getPointInPeri(){
	pointInPeri.clear();
	//y++ from bottom point to the top point of square until it reaches the next vertice at the bottom of the rectangle
	for(int i = x[0]; i < x[1]-1; i++){
		for(int j = y[0]+1; j < y[1]; j++){
			pointInPeri.push_back("("+to_string(i+1)+", "+to_string(j)+")");
		}
	}
	
	return pointInPeri;
}
