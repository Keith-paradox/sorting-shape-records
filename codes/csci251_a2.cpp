#include "ShapeTwoD.cpp"
#include "Cross.cpp"
#include "Rectangle.cpp"
#include "Square.cpp"
#include "Circle.cpp"

using namespace std;

//variables
int choice;
string SPtype, name, sort_option;
bool warp, quit_sort;
bool records_in, area_calculated = false;
int shape_num = 0;

//vectors to store all the data of user's
vector<int> Shape_nums;
vector<string> Names;
vector<string> Warps;
vector<double> Areas;
vector<vector<string>> PointOnPeri;
vector<vector<string>> PointInPeri;
vector<vector<string>> Vertices;

//methods
float round(float n);
void sortName();
void sortNum();
void sortAsc();
void sortDes();
void sortSpecialDES();
void sortSpecialASC();
void displayRecords();

void mainMenu();

int main()
{
	mainMenu();
	return 0;
}

//round out the area of circle to 2 decimals
float round(float n){
	float result = (int)(n * 100 + .5);
	return (float)result/100;
}

//main menu 
void mainMenu()
{
	bool quit = false;
	while (!quit){
		bool name_error = false;
		bool warp_error = false;
		cout << "Student ID\t: 8039173" << endl;
		cout << "Student Name\t: Min Khant Thu" << endl;
		cout << "-----------------------------------------------" << endl;
		
		cout << "Welcome to Assn2 program!" << endl;
		cout << endl;
	
		int n = 1;
		
		//put all the options in array
		string options[] = {"Input sensor data", "Compute area(for all records)", "Print shapes report", "Sort shape data", "Quit"};
	
		for(string option: options){
			cout << n << ")\t" << option << endl;
			n++;
		}
		
		//asking user what option he wants to choose
		cout << "\nPlease enter your choice: ";
		
		if(cin >> choice)switch(choice){
			case 1:
				cout << endl;
				records_in = true;
				area_calculated = false;
				cout << "[" << options[0] << "]\n" << endl;

				//asking user which shape he wants to add
				while(!name_error){
					cout << "Please enter name of shape: ";
					cin >> name;
					//if the input is not the option ask again
					if(name == "Rectangle" or name == "Square" or name == "Circle" or name == "Cross"){
					name_error = true;
					}
					else{
					cout << "Invalid shape name. Try again." << endl;
					}
				}
				
				//asking user the special type 
				while(!warp_error){
					cout << "Please enter special type: ";
					cin >> SPtype;
					//if the input is not WS or NS then ask again
					if(SPtype == "WS"){
						warp = true;
						warp_error = true;
					}
					else if(SPtype == "NS"){
						warp = false;
						warp_error = true;
					}
					else{
						cout << "Invalid space type. Try again." << endl;
					}
				}
				if(name == "Rectangle"){
					Rectangle rect(name, warp);
					//put name and special type data into vector to keep track of all data
					Shape_nums.push_back(shape_num);
					Names.push_back(name);
					Warps.push_back(SPtype);
					//asking user to put in coordinates
					rect.askCoordinates();
					//getting points on perimeter, points within shape, vertices and areas calculates through function then add them into vector to keep track of the data
					PointOnPeri.push_back(rect.getPointOnPeri());
					PointInPeri.push_back(rect.getPointInPeri());
					Vertices.push_back(rect.getVertices());
					Areas.push_back(rect.computeArea());
				}
				else if(name == "Square"){
					Square square(name, warp);
					Shape_nums.push_back(shape_num);
					Names.push_back(name);
					Warps.push_back(SPtype);
					square.askCoordinates();
					PointOnPeri.push_back(square.getPointOnPeri());
					PointInPeri.push_back(square.getPointInPeri());
					Vertices.push_back(square.getVertices());
					Areas.push_back(square.computeArea());
				}
				else if(name == "Cross"){
					Cross cross(name, warp);
					Shape_nums.push_back(shape_num);
					Names.push_back(name);
					Warps.push_back(SPtype);
					cross.askCoordinates();
					PointOnPeri.push_back(cross.getPointOnPeri());
					PointInPeri.push_back(cross.getPointInPeri());
					Vertices.push_back(cross.getVertices());
					Areas.push_back(cross.computeArea());
				}
				else if(name == "Circle"){
					Circle circle(name, warp);
					Shape_nums.push_back(shape_num);
					Names.push_back(name);
					Warps.push_back(SPtype);
					circle.askCoordinates();
					PointOnPeri.push_back(circle.getPointOnPeri());
					PointInPeri.push_back(circle.getPointInPeri());
					Vertices.push_back(circle.getVertices());
					Areas.push_back(round(circle.computeArea()));
				}
				shape_num++;
				cout << endl;
				break;
			case 2:
				cout << endl;
				
				if(records_in == false){
					cout << "User hasn't input any records yet." << endl;
				}
				else{
				//display how many record areas have been calculated
				cout << "Computation completed! ( " << Areas.size() << " records were updated )" << endl;
				area_calculated = true;
				}
				cout << endl;
				break;
			case 3:
				//if the user hasn't input any records 
				if(records_in == false){
					cout << "User hasn't input any records yet." << endl;
				}
				//if the user hasn't calculated all the areas
				else if(area_calculated == false){
					cout << "All areas haven't been calculated." << endl;
				}
				//displaying all the records
				else{
					cout << endl;
					cout << "Total no. of records available = " << Names.size() << endl;
					cout << endl;
					displayRecords();
				}
				
				cout << endl;
				break;
			case 4:
				if(records_in == false){
					cout << "User hasn't input any records yet." << endl;
				}
				else if(area_calculated == false){
					cout << "All areas haven't been calculated." << endl;
				}
				else{
				//showing all the sorting options
					cout << endl;
					quit_sort = false;
					while(!quit_sort){
					cout << "\ta) Sort by area (ascending)" << endl;
					cout << "\tb) Sort by area (descending)" << endl;
					cout << "\tc) Sort by special type and area (descending)" << endl;
					cout << "\td) Sort by special type and area (ascending)" << endl;
					cout << "\te) Sort by name of the shape" << endl;
					cout << "\tf) Sort by no. of the shape" << endl;
					cout << endl;
					//asking user the option
					cout << "Please select sort option('q' to go to main menu):";
					cin >> sort_option;
					if(sort_option == "a"){
					//calling function to sort in ascending order
						sortAsc();
						cout << "\nSort by area (smallest to largest) ...\n" << endl;
						displayRecords();
						quit_sort = true;
					}
					else if(sort_option == "b"){
					//calling functions to sort in descending order
						sortDes();
						cout << "\nSort by area (largest to smallest) ...\n" << endl;
						displayRecords();
						quit_sort = true;
					}
					else if(sort_option == "c"){
					//calling function to sort by special type and area in decending order
						sortSpecialDES();
						cout << "\nSort by special type and area (descending) ...\n" << endl;
						displayRecords();
						quit_sort = true;
					}
					else if(sort_option == "d"){
					//calling function to sort by special type and area in ascending order
						sortSpecialASC();
						cout << "\nSort by special type and area (ascending) ...\n" << endl;
						displayRecords();
						quit_sort = true;
					}
					else if(sort_option == "e"){
					//calling function to sort by special type and area in ascending order
						sortName();
						cout << "\nSort by name of the shape ...\n" << endl;
						displayRecords();
						quit_sort = true;
					}
					else if(sort_option == "f"){
					//calling function to sort by special type and area in ascending order
						sortNum();
						cout << "\nSort by no. of the shape ...\n" << endl;
						displayRecords();
						quit_sort = true;
					}
					else if(sort_option == "q"){
						cout << "You chose to quit returning to main menu ..." << endl;
						quit_sort = true;
					}
					else{
						cout << "Invalid choice. Try again" << endl;
					}
				}
				
				}
				cout << endl;
				break;
			case 5:
				cout << endl;
				cout << "[" << options[4] << "]\n" << endl;
				cout << endl;
				quit = true;
				break;
			default:
				cout << endl;
				cout << "Invalid number, Please choose again." << endl;
				cout << endl;
				break;
		}
		else{
			cout << endl;
			cout << "Invalid input, Please choose again." << endl;
			cout << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void sortName(){
	bool swap = true;
	while(swap){
		swap = false;
		
		for(int i = 1; i < Areas.size(); i++){
			double a1 = Areas[i-1];
			double a2 = Areas[i];
			string b1 = Names[i-1];
			string b2 = Names[i];
			string c1 = Warps[i-1];
			string c2 = Warps[i];
			vector<string> d1 = PointOnPeri[i-1];
			vector<string> d2 = PointOnPeri[i];
			vector<string> e1 = PointInPeri[i-1];
			vector<string> e2 = PointInPeri[i];
			vector<string> f1 = Vertices[i-1];
			vector<string> f2 = Vertices[i];
			int g1 = Shape_nums[i-1];
			int g2 = Shape_nums[i];
			//compare area
			if(b1.compare(b2) > 0){
				Areas[i-1] = a2;
				Areas[i] = a1;
				Names[i-1] = b2;
				Names[i] = b1;
				Warps[i-1] = c2;
				Warps[i] = c1;
				PointOnPeri[i-1] = d2;
				PointOnPeri[i] = d1;
				PointInPeri[i-1] = e2;
				PointInPeri[i] = e1;
				Vertices[i-1] = f2;
				Vertices[i] = f1;
				Shape_nums[i-1] = g2;
				Shape_nums[i] = g1;
				swap = true;
			}
			else if(b1.compare(b2) == 0){
				//sorting in descending order of same type
				if(a1 < a2){
					Areas[i-1] = a2;
					Areas[i] = a1;
					Names[i-1] = b2;
					Names[i] = b1;
					Warps[i-1] = c2;
					Warps[i] = c1;
					PointOnPeri[i-1] = d2;
					PointOnPeri[i] = d1;
					PointInPeri[i-1] = e2;
					PointInPeri[i] = e1;
					Vertices[i-1] = f2;
					Vertices[i] = f1;
					Shape_nums[i-1] = g2;
					Shape_nums[i] = g1;
					swap = true;
				}
			}
			
		}
	}
}

void sortNum(){
	bool swap = true;
	while(swap){
		swap = false;
		
		for(int i = 1; i < Areas.size(); i++){
			double a1 = Areas[i-1];
			double a2 = Areas[i];
			string b1 = Names[i-1];
			string b2 = Names[i];
			string c1 = Warps[i-1];
			string c2 = Warps[i];
			vector<string> d1 = PointOnPeri[i-1];
			vector<string> d2 = PointOnPeri[i];
			vector<string> e1 = PointInPeri[i-1];
			vector<string> e2 = PointInPeri[i];
			vector<string> f1 = Vertices[i-1];
			vector<string> f2 = Vertices[i];
			int g1 = Shape_nums[i-1];
			int g2 = Shape_nums[i];
			//compare area
			if(g1 > g2){
				//changing all the data index
				Areas[i-1] = a2;
				Areas[i] = a1;
				Names[i-1] = b2;
				Names[i] = b1;
				Warps[i-1] = c2;
				Warps[i] = c1;
				PointOnPeri[i-1] = d2;
				PointOnPeri[i] = d1;
				PointInPeri[i-1] = e2;
				PointInPeri[i] = e1;
				Vertices[i-1] = f2;
				Vertices[i] = f1;
				Shape_nums[i-1] = g2;
				Shape_nums[i] = g1;
				swap = true;
			}
			
		}
	}
}

//bubble sorting by comparing area
void sortAsc(){
	bool swap = true;
	while(swap){
		swap = false;
		
		for(int i = 1; i < Areas.size(); i++){
			double a1 = Areas[i-1];
			double a2 = Areas[i];
			string b1 = Names[i-1];
			string b2 = Names[i];
			string c1 = Warps[i-1];
			string c2 = Warps[i];
			vector<string> d1 = PointOnPeri[i-1];
			vector<string> d2 = PointOnPeri[i];
			vector<string> e1 = PointInPeri[i-1];
			vector<string> e2 = PointInPeri[i];
			vector<string> f1 = Vertices[i-1];
			vector<string> f2 = Vertices[i];
			int g1 = Shape_nums[i-1];
			int g2 = Shape_nums[i];
			//compare area
			if(a1 > a2){
				//changing all the data index
				Areas[i-1] = a2;
				Areas[i] = a1;
				Names[i-1] = b2;
				Names[i] = b1;
				Warps[i-1] = c2;
				Warps[i] = c1;
				PointOnPeri[i-1] = d2;
				PointOnPeri[i] = d1;
				PointInPeri[i-1] = e2;
				PointInPeri[i] = e1;
				Vertices[i-1] = f2;
				Vertices[i] = f1;
				Shape_nums[i-1] = g2;
				Shape_nums[i] = g1;
				swap = true;
			}
			
		}
	}
}

void sortDes(){
	bool swap = true;
	while(swap){
		swap = false;
		
		for(int i = 1; i < Areas.size(); i++){
			double a1 = Areas[i-1];
			double a2 = Areas[i];
			string b1 = Names[i-1];
			string b2 = Names[i];
			string c1 = Warps[i-1];
			string c2 = Warps[i];
			vector<string> d1 = PointOnPeri[i-1];
			vector<string> d2 = PointOnPeri[i];
			vector<string> e1 = PointInPeri[i-1];
			vector<string> e2 = PointInPeri[i];
			vector<string> f1 = Vertices[i-1];
			vector<string> f2 = Vertices[i];
			int g1 = Shape_nums[i-1];
			int g2 = Shape_nums[i];
			if(a1 < a2){
				Areas[i-1] = a2;
				Areas[i] = a1;
				Names[i-1] = b2;
				Names[i] = b1;
				Warps[i-1] = c2;
				Warps[i] = c1;
				PointOnPeri[i-1] = d2;
				PointOnPeri[i] = d1;
				PointInPeri[i-1] = e2;
				PointInPeri[i] = e1;
				Vertices[i-1] = f2;
				Vertices[i] = f1;
				Shape_nums[i-1] = g2;
				Shape_nums[i] = g1;
				swap = true;
			}
			
		}
	}
}
void sortSpecialDES(){
	bool swap = true;
	while(swap){
		swap = false;
		
		for(int i = 1; i < Areas.size(); i++){
			double a1 = Areas[i-1];
			double a2 = Areas[i];
			string b1 = Names[i-1];
			string b2 = Names[i];
			string c1 = Warps[i-1];
			string c2 = Warps[i];
			vector<string> d1 = PointOnPeri[i-1];
			vector<string> d2 = PointOnPeri[i];
			vector<string> e1 = PointInPeri[i-1];
			vector<string> e2 = PointInPeri[i];
			vector<string> f1 = Vertices[i-1];
			vector<string> f2 = Vertices[i];
			int g1 = Shape_nums[i-1];
			int g2 = Shape_nums[i];
			//compare the WS and NS
			if(c1.compare(c2) < 0){
				Areas[i-1] = a2;
				Areas[i] = a1;
				Names[i-1] = b2;
				Names[i] = b1;
				Warps[i-1] = c2;
				Warps[i] = c1;
				PointOnPeri[i-1] = d2;
				PointOnPeri[i] = d1;
				PointInPeri[i-1] = e2;
				PointInPeri[i] = e1;
				Vertices[i-1] = f2;
				Vertices[i] = f1;
				Shape_nums[i-1] = g2;
				Shape_nums[i] = g1;
				swap = true;
			}
			else if(c1.compare(c2) == 0){
				//sorting in descending order of same type
				if(a1 < a2){
					Areas[i-1] = a2;
					Areas[i] = a1;
					Names[i-1] = b2;
					Names[i] = b1;
					Warps[i-1] = c2;
					Warps[i] = c1;
					PointOnPeri[i-1] = d2;
					PointOnPeri[i] = d1;
					PointInPeri[i-1] = e2;
					PointInPeri[i] = e1;
					Vertices[i-1] = f2;
					Vertices[i] = f1;
					Shape_nums[i-1] = g2;
					Shape_nums[i] = g1;
					swap = true;
				}
			}
		}
	}
}
void sortSpecialASC(){
	bool swap = true;
	while(swap){
		swap = false;
		
		for(int i = 1; i < Areas.size(); i++){
			double a1 = Areas[i-1];
			double a2 = Areas[i];
			string b1 = Names[i-1];
			string b2 = Names[i];
			string c1 = Warps[i-1];
			string c2 = Warps[i];
			vector<string> d1 = PointOnPeri[i-1];
			vector<string> d2 = PointOnPeri[i];
			vector<string> e1 = PointInPeri[i-1];
			vector<string> e2 = PointInPeri[i];
			vector<string> f1 = Vertices[i-1];
			vector<string> f2 = Vertices[i];
			int g1 = Shape_nums[i-1];
			int g2 = Shape_nums[i];
			//compare the WS and NS
			if(c1.compare(c2) < 0){
				Areas[i-1] = a2;
				Areas[i] = a1;
				Names[i-1] = b2;
				Names[i] = b1;
				Warps[i-1] = c2;
				Warps[i] = c1;
				PointOnPeri[i-1] = d2;
				PointOnPeri[i] = d1;
				PointInPeri[i-1] = e2;
				PointInPeri[i] = e1;
				Vertices[i-1] = f2;
				Vertices[i] = f1;
				Shape_nums[i-1] = g2;
				Shape_nums[i] = g1;
				swap = true;
			}
			else if(c1.compare(c2) == 0){
				//sorting in ascending order of same type
				if(a1 > a2){
					Areas[i-1] = a2;
					Areas[i] = a1;
					Names[i-1] = b2;
					Names[i] = b1;
					Warps[i-1] = c2;
					Warps[i] = c1;
					PointOnPeri[i-1] = d2;
					PointOnPeri[i] = d1;
					PointInPeri[i-1] = e2;
					PointInPeri[i] = e1;
					Vertices[i-1] = f2;
					Vertices[i] = f1;
					Shape_nums[i-1] = g2;
					Shape_nums[i] = g1;
					swap = true;
				}
			}
		}
	}
}

void displayRecords(){
	for(int i =0; i < Names.size(); i++){
	//data are all stored and connected through index of vector so by accessing same index of the vector we can get data of each
	cout << "Shape [" << Shape_nums[i] << "]" << endl;
	cout << "Name : " << Names[i] << endl;
	cout << "Special Type : " << Warps[i] << endl;
	cout << "Area : " << Areas[i] << " units square" << endl;
	cout << "Vertices : " << endl;
	int vertices_no = 0;
	
	for(string point : Vertices[i]){
		cout << "Point [" << vertices_no << "] : " << point << endl;
		vertices_no++;
	}
	cout << endl;
	cout << "Points on perimeter : ";
	if(PointOnPeri[i].empty()){
		cout << "null!";
	}
	else{
		for(string point : PointOnPeri[i]){
			cout << point;
		}
	}
	cout << endl;
	cout << endl;
	cout << "Points within shape : ";
	if(PointInPeri[i].empty()){
		cout << "null!";
	}
	else{
		for(string point : PointInPeri[i]){
			cout << point;
		}
	}
	cout << endl;
	cout << endl;
	}
}
