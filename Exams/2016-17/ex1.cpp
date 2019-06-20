#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
// (A)

using namespace std;

void simplify(const string &name, string &sName);

int main() {
	ifstream ifs("people1.txt");
	
	if (ifs.fail()) {
		cerr << "people1.txt not found" << endl;
		exit(1);
	}
	
	vector<string> names; // (B)
	string name;
	
	while (!ifs.eof()) {
		getline(ifs, name);
		names.push_back(name); // (C)
	}
	
	ifs.close();
	
	ofstream ofs("people2.txt");
	
	for(size_t i = 0; i < names.size(); i++) { // (D)
		simplify(names[i], name); // (E)
		ofs << name << endl;
	}
	
	ofs.close();
	
	return 0;
}

void simplify(const string &name, string &sName) {
	istringstream iss(name);
	
	string firstName, lastName;
	
	iss >> firstName;
	if (iss.eof()) {
		sName = firstName;
	}
	else {
		while(!iss.eof()) {
			iss >> lastName;
		}
		sName = firstName + " " + lastName;
	}
}

/* 1C

(A) - #include <set>
(B) - set<string> names;
(C) - names.insert(name);
(D) - for(set<string>::iterator it = names.begin(); it != names.end(); it++) {
(E) - simplify(*it, name);

*/