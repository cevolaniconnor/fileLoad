#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Car {
private:
	string manufacturer;
	string model;

public:
	Car(const string &manu, const string &mod) : manufacturer(manu), model(mod) {}

	// Getter for manufacturer
	string getManufacturer() const {
		return manufacturer;
	}
	friend ostream& operator<<(ostream &os, const Car &car) {
        os << "Manufacturer: " << car.manufacturer << ", Model: " << car.model;
        return os;
    }

	// Getter for model
	string getModel() const {
		return model;
	}
	string toString() const {
		return manufacturer + "," + model;
	}
};

void load(vector<Car> &vec, string fileName){
	ifstream file(fileName);
	string line, manufacturer, model;

	while (getline(file, line)) {
		size_t comma = line.find(',');
		if (comma != string::npos) {
			manufacturer = line.substr(0, comma);
			model = line.substr(comma + 1);
			vec.push_back(Car(manufacturer, model));
		}
	}
	file.close();
}

void print(vector<Car> &vec){
	//prints out vector
	for(const auto &l : vec){
		cout << l << endl;
	}
}

void save(vector<Car> &vec, string fileName){
	//writes to "list.txt"
	ofstream outfile(fileName, ios::trunc);
	for (const auto &car : vec) {
		outfile << car.toString() << endl;
	}
	outfile.close();
}


void addItem(vector<Car> &vec, string fileName){
	//takes in user input for new item
	string manufacturer, model;
	cout << "Enter Manufacturer: ";
	getline(cin, manufacturer);
	cout << "Enter Model: ";
	getline(cin, model);
	vec.push_back(Car(manufacturer, model));
}

void remove(vector<Car> &vec){
 cout << "Delete car (by index): ";
    int removeIndex;
    cin >> removeIndex;

    if (removeIndex >= 0 && removeIndex < vec.size()) {
        vec.erase(vec.begin() + removeIndex);
        cout << "Car removed successfully." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
    cin.ignore(); // Clear the newline character from input
}


int main(){
	string fileName = "list.txt";

	vector<Car> data;

	load(data, fileName);

	addItem(data, fileName);
	save(data, fileName);

	remove(data);
	save(data, fileName);

	print(data);


	return 0;
}