#include "Topic4.h"
#include <iostream>

void Topic4::selectExercise() {
	cout << "Enter exercise number: ";
	cin >> exercise;

	switch (exercise) {
		case 1:
			break;
		case 2:
			testSequenceSearch();
			break;
		case 3:
			string compound;
			cout << "Enter compound: ";
			cin >> compound;
			decompose(compound);
	}
}

bool Topic4::isHydroxide(char compound[]) {
	int length = strlen(compound);
	return (compound[length - 2] == 'O' && compound[length - 1] == 'H');
}

bool Topic4::isHydroxide(string compound) {
	return compound.substr(compound.length() - 2) == "OH";
}

bool Topic4::sequenceSearch(string s, int nc, char c) {
	int count = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == c)
			count++;
		else
			count = 0;

		if (count == nc)
			return true;
	}

	return false;
}

void Topic4::testSequenceSearch() {
	cout << "Testing values (english, 1, i): " << sequenceSearch("english", 1, 'i') << endl;
	cout << "Testing values (boolean, 2, o): " << sequenceSearch("boolean", 2, 'o') << endl;
	cout << "Testing values (boolean, 3, o): " << sequenceSearch("boolean", 3, 'o') << endl;
	cout << "Testing values (xxxxx, 4, x): " << sequenceSearch("xxxxx", 4, 'x') << endl;
}

void Topic4::decompose(string compound) {
	char c;

	cout << "The compound has the elements: ";
	for (int i = 0; i < compound.length(); i++) {
		c = compound[i];

		if (isalpha(c)) {
			if (i > 0) {
				if (isupper(c) && isalpha(compound[i - 1])) {
					cout << ", ";
				}
			}
			cout << c;
		}
		else if (isdigit(c) && i != compound.length() - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}
