#include "Topic4.h"
#include <iostream>
#include <algorithm>

void Topic4::selectExercise() {
	cout << "Enter exercise number: ";
	cin >> exercise;

	string compound, name;
	Fraction f;

	switch (exercise) {
		case 1:
			break;
		case 2:
			testSequenceSearch();
			break;
		case 3:
			cout << "Enter compound: ";
			cin >> compound;
			decompose(compound);
			break;
		case 4:
			cout << "Enter name: ";
			cin.ignore();
			getline(cin, name);
			cout << normalizeName(name) << endl;
			break;
		case 5:
			f = readFrac();
			f = reduceFrac(f);
			writeFrac(f);
			cout << endl;
			break;
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

	for (size_t i = 0; i < s.length(); i++) {
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
	for (size_t i = 0; i < compound.length(); i++) {
		c = compound[i];

		if (i > 0) {
			if (isupper(c) && isalpha(compound[i - 1]))
				cout << ", " << c;
			else if (isdigit(c) && i != compound.length() - 1)
				cout << ", ";
			else if (isalpha(c))
				cout << c;
		}
		else
			cout << c;
	}
	cout << endl;
}

string Topic4::normalizeName(string name) {
	string parts[] = { " DE ", " DO ", " DA ", " DOS ", " DAS ", " E " };
	int spaceCount = 0;

	transform(name.begin(), name.end(), name.begin(), toupper);

	// Remove particles
	for (string s : parts) {
		while (name.find(s) != -1) {
			name.replace(name.find(s), s.length(), " ");
		}
	}

	// Erase spaces at the beginning
	for (size_t i = 0; i < name.length(); i++) {
		if (name[i] == ' ')
			spaceCount++;
		else
			break;
	}

	name.erase(0, spaceCount);
	spaceCount = 0;
	
	// Erase spaces at the end
	for (int i = name.length() - 1; i >= 0; i--) {
		if (name[i] == ' ')
			spaceCount++;
		else
			break;
	}

	if (spaceCount != 0)
		name.erase(name.length() - spaceCount, spaceCount);

	// Replace multiple spaces with one
	while (name.find("  ") != -1) {
		name.replace(name.find("  "), 2, " ");
	}

	return name;
}

Fraction Topic4::readFrac() {
	Fraction f;
	char dash;

	cout << "Enter a fraction (numerator / denominator): ";
	cin >> f.numerator >> dash >> f.denominator;

	if (cin.fail() || dash != '/' || f.denominator == 0) {
		f.numerator = 0;
		f.denominator = 0;
	}

	return f;
}

void Topic4::writeFrac(Fraction f) {
	cout << f.numerator << "/" << f.denominator;
}

Fraction Topic4::reduceFrac(Fraction f) {
	int a, b, gcd;

	a = f.numerator;
	b = f.denominator;

	// Euclid's algorithm
	if (a != 0) {
		while (a != b) {
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		gcd = a;
	}
	else
		gcd = 1;

	f.numerator /= gcd;
	f.denominator /= gcd;

	return f;
}