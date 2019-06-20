/*
	DISCLAIMER: This is a solution to an exam exercise and uses file paths that may not exist on your system.
	If you want to run the program, change the file paths.
*/

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

void toUpperStr(string &s) {
	for (size_t i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
}

string transformLine(string s) {
	toUpperStr(s);
	for (size_t i = 0; i < s.length(); i++) {
		if (!isalpha(s[i]) && s[i] != ' ') {
			s[i] = ' ';
		}
	}
	return s;
}

void decomposeLine(string line, vector<string> &words) {
	string transformed = transformLine(line);
	string word;

	istringstream iss(transformed);
	while (!iss.eof()) {
		iss >> word;
		words.push_back(word);
	}
}

int main() {
	ifstream ifs("C:\\docs\\text.txt");
	vector<string> lines, words;
	string line;

	while (!ifs.eof()) {
		getline(ifs, line);
		lines.push_back(line);
	}

	ifs.close();

	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++) {
		decomposeLine(*it, words);
	}
	
	sort(words.begin(), words.end());

	ofstream ofs("words.txt");
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
		ofs << *it << endl;
	}
	ofs.close();

	return 0;
}

/* 1E
We could use a set, since sets don't allow for repeated values

set<string> words;
words.insert(word);

instead of

vector<string> words;
words.push_back(word);
*/