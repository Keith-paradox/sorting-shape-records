#include "Cross.h"

Cross::Cross(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
{
	setName(name);
	setContainsWarpSpace(containsWarpSpace);
}
string Cross::getName(){
	return name;
}
bool Cross::getContainsWarpSpace(){
	return containsWarpSpace;
}
string Cross::toString(){
	return "";
}
//compute area of cross by counting all the little squares in shape
double Cross::computeArea(){
	double area = 0;
	for(int i = 0; i < area_x.size(); i++){
		if(count(area_XandY.begin(), area_XandY.end(), ("("+to_string(area_x[i]+1)+", "+to_string(area_y[i]+1)+")")) and count(area_XandY.begin(), area_XandY.end(), ("("+to_string(area_x[i]+1)+", "+to_string(area_y[i])+")")) and count(area_XandY.begin(), area_XandY.end(), ("("+to_string(area_x[i])+", "+to_string(area_y[i]+1)+")"))){
		area++;
		}
	}
	return area;
}
bool Cross::isPointInShape(int x, int y){
	return true;
}
bool Cross::isPointOnShape(int x, int y){
	return true;
}
void Cross::setName(string name){
	this->name = name;
}
void Cross::setContainsWarpSpace(bool containsWarpSpace){
	this->containsWarpSpace = containsWarpSpace;
}
void Cross::askCoordinates(){
	int count = 1;
	cross_x.clear();
	cross_y.clear();
	vertices.clear();
	while(count <= 12){
		bool error = false;
		while(!error){
			//asking user to input the coordinates
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
		x.push_back(stoi(x_point));
		y.push_back(stoi(y_point));
		count++;
	}
	sortXandY();
	cout << "\nRecords successfully stored. Going back to main menu..." << endl;
	
	
}
bool Cross::check_int(string input){
	for(int i = 0; i < input.length(); i++){
		if(isdigit(input[i]) == false){
			return false;
		}
	}
	return true;
}
void Cross::sortXandY(){
	bool swap = true;
	while(swap){
		swap = false;
		
		for(int i = 1; i < cross_x.size(); i++){
			int x1 = cross_x[i-1];
			int x2 = cross_x[i];
			int y1 = cross_y[i-1];
			int y2 = cross_y[i];
			if(x1 > x2){
				cross_x[i-1] = x2;
				cross_x[i] = x1;
				cross_y[i-1] = y2;
				cross_y[i] = y1;
				swap = true;
			}
			else if(x1 == x2){
				if(y1 > y2){
					cross_x[i-1] = x2;
					cross_x[i] = x1;
					cross_y[i-1] = y2;
					cross_y[i] = y1;
					swap = true;
				}
			}
			
		}
	}
}
void Cross::sortXandY_two(){
	bool swap = true;
	while(swap){
		swap = false;
		
		for(int i = 1; i < x.size(); i++){
			int x1 = x[i-1];
			int x2 = x[i];
			int y1 = y[i-1];
			int y2 = y[i];
			if(x1 > x2){
				x[i-1] = x2;
				x[i] = x1;
				y[i-1] = y2;
				y[i] = y1;
				swap = true;
			}
			else if(x1 == x2){
				if(y1 > y2){
					x[i-1] = x2;
					x[i] = x1;
					y[i-1] = y2;
					y[i] = y1;
					swap = true;
				}
			}
			
		}
	}
}
vector<string> Cross::getPointOnPeri(){	
	pointOnPeri.clear();
	int x_start = cross_x[0];
	int y_start = cross_y[0];
	for(int i = 0; i < 12; i++){
	
		bool found = false;
		int plus = 1;
		//data are all sorted so theres a pattern where the point from index 1 3 and 5 are going to be x++ to get to next point
		// until it gets to the next point the points in middle are considered as points on parameter
		if(i == 1 or i == 3 or i == 5){
			while(!found){
				if(count(vertices.begin(), vertices.end(), ("("+to_string(x_start+plus)+", "+to_string(y_start)+")"))){
					found = true;
					x_start = x_start + plus;
					continue;
				}
				else{
					pointOnPeri.push_back("("+to_string(x_start+plus)+", "+to_string(y_start)+")");
					x.push_back(x_start+plus);
					y.push_back(y_start);
				}
				plus++;
			}
		}
		//same goes for this but x--
		else if(i == 7 or i == 9 or i == 11){
			while(!found){
				if(count(vertices.begin(), vertices.end(), ("("+to_string(x_start-plus)+", "+to_string(y_start)+")"))){
					found = true;
					x_start = x_start - plus;
					continue;
				}
				else{
					pointOnPeri.push_back("("+to_string(x_start-plus)+", "+to_string(y_start)+")");
					x.push_back(x_start-plus);
					y.push_back(y_start);
				}
				plus++;
			}
		}
		//for this it is y++
		else if(i == 0 or i == 2 or i == 10){
			while(!found){
				if(count(vertices.begin(), vertices.end(), ("("+to_string(x_start)+", "+to_string(y_start+plus)+")"))){
					found = true;
					y_start = y_start + plus;
					continue;
				}
				else{
					pointOnPeri.push_back("("+to_string(x_start)+", "+to_string(y_start+plus)+")");
					x.push_back(x_start);
					y.push_back(y_start+plus);
				}
				plus++;
			}
		}
		//for this is y--
		else if(i == 4 or i == 6 or i == 8){
			while(!found){
				if(count(vertices.begin(), vertices.end(), ("("+to_string(x_start)+", "+to_string(y_start-plus)+")"))){
					found = true;
					y_start = y_start - plus;
					continue;
				}
				else{
					pointOnPeri.push_back("("+to_string(x_start)+", "+to_string(y_start-plus)+")");
					x.push_back(x_start);
					y.push_back(y_start-plus);
				}
				plus++;
			}
		}
	}
	
	sort(pointOnPeri.begin(), pointOnPeri.end());
	
	return pointOnPeri;
}
vector<string> Cross::getVertices(){
	return vertices;
}
vector<string> Cross::getPointInPeri(){
	pointInPeri.clear();
	
	sortXandY_two();
	//by going from the bottom point of vertices and point on paremeter and then y++ until it reaches the top point and minus vertices and point on parameter and get all the points within shape
	for(int i = 0; i < x.size(); i++){
		area_x.push_back(x[i]);
		area_y.push_back(y[i]);
		area_XandY.push_back("("+to_string(x[i])+", "+to_string(y[i])+")");
	}
	
	for(int k =0; k < x.size(); k++){
		if(x[k] == x[k+1]){
			for(int j = y[k]+1; j < y[k+1]; j++){
				if(count(pointOnPeri.begin(), pointOnPeri.end(), ("("+to_string(x[k])+", "+to_string(j)+")"))){
				}
				else{
				pointInPeri.push_back("("+to_string(x[k])+", "+to_string(j)+")");
				area_x.push_back(x[k]);
				area_y.push_back(j);
				area_XandY.push_back("("+to_string(x[k])+", "+to_string(j)+")");
				}
			}
		}
		else{
			continue;
		}
		
	}
	
	return pointInPeri;
}
