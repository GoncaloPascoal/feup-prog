#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// 1A
void get_code_sum(const string &code_grades, int num_grades, string &code, double &sum) {
	double grade;
	string s;
	istringstream iss(code_grades);
	sum = 0;
	
	iss >> code;
	iss >> s; // Dash
	
	for (size_t i = 0; i < num_grades; i++) {
		iss >> grade;
		sum += grade;
	}
}

// 1B
int main() {
	string fileRoot, fileIn, fileOut;
	
	cout << "Enter the file root: ";
	cin >> fileRoot;
	
	fileIn = fileRoot + ".txt";
	fileOut = fileRoot + "_final.txt";
	
	ifstream ifs(fileIn);
	
	if (ifs.fail()) {
		cerr << "Couldn't open file." << endl;
		exit(1);
	}
	
	int numGrades;
	ifs >> numGrades;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');
	
	string codeGrades, code;
	double sum;
	
	ofstream ofs(fileOut);
	
	while(!ifs.eof()) {
		getline(ifs, codeGrades);
		get_code_sum(codeGrades, numGrades, code, sum);
		ofs << setw(10) << code << " - " << sum << endl;
	}
	
	ifs.close();
	ofs.close();
	
	return 0;
}