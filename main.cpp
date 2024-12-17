#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
using namespace std;

void load(vector<string> &vec, string fileName){
	ifstream file(fileName);
	string line;

	while(getline(file, line)){
		vec.push_back(line);
	}

	file.close();
}

void print(vector<string> &vec){
	//prints out vector
	for(const auto &l : vec){
		cout << l << endl;
	}
}

void save(vector<string> &vec, string fileName){
	//writes to "list.txt"
	ofstream outfile(fileName, ios::trunc);
	for (string item: vec){
		outfile << item << endl;
	}
	
	outfile.close();
}

void addItem(vector<string> &vec, string fileName){
	//takes in user input for new item
	string itemDescip;
	getline(cin,itemDescip);
	vec.push_back(itemDescip);
}

void remove(vector<string> &vec){
	cout << "Delete task (By index): " << endl;
	int remove;

	cin >> remove;
	//check to see if the vector has the required index
	if (remove >= 0 && remove < vec.size()) {
        vec.erase(vec.begin() + remove);  
        // Remove the task at the specified index
    } else {
        cout << "Invalid index!" << endl;
    }
}



int main(){
	string fileName = "list.txt";

	vector<string> data;
	load(data, fileName);

	remove(data);

	save(data, fileName);

	print(data);

	return 0;
}