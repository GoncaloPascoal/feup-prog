#include "Topic4.h"
#include <iostream>
#include <algorithm>
#include <fstream>

void Topic4::selectExercise() {
	cout << "Enter exercise number: ";
	cin >> exercise;

	string compound, name;
	Fraction f1, f2;

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
			f1 = readFrac();
			f2 = readFrac();
			
			f1 = reduceFrac(f1);
			f2 = reduceFrac(f2);
			
			cout << "F1: ";
			writeFrac(f1);
			cout << " | F2: ";
			writeFrac(f2);
			cout << endl;

			cout << "SUM: ";
			writeFrac(addFrac(f1, f2));
			cout << "\nDIFF: ";
			writeFrac(subtractFrac(f1, f2));
			cout << "\nMULT: ";
			writeFrac(multiplyFrac(f1, f2));
			cout << "\nDIV: ";
			writeFrac(divideFrac(f1, f2));

			cout << endl;

			break;
		case 6:
			testIntArray();
			break;
		case 8:
			testBubbleSort();
			break;
		case 9:
			testBinarySearch();
			break;
		case 12:
			testExecuteOperation();
			break;
		case 13:
			sortNamesInFile();
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
	bool negative;
	int a, b, gcd;

	negative = f.numerator < 0 != f.denominator < 0;

	f.numerator = abs(f.numerator);
	f.denominator = abs(f.denominator);

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

	if (negative)
		f.numerator /= -gcd;
	else
		f.numerator /= gcd;
	f.denominator /= gcd;

	return f;
}

Fraction Topic4::addFrac(Fraction f1, Fraction f2) {
	Fraction result;

	if (f1.denominator == 0 || f2.denominator == 0) {
		result.numerator = 0;
		result.denominator = 0;
	}
	else if (f1.numerator == 0)
		result = f2;
	else if (f2.numerator == 0)
		result = f1;
	else {
		int a, b, scm; // Smallest common multiple

		a = f1.denominator;
		b = f2.denominator;

		// Euclid's algorithm
		while (a != b) {
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		scm = f1.denominator * f2.denominator / a;

		result.numerator = f1.numerator * (scm / f1.denominator) + f2.numerator * (scm / f2.denominator);;
		result.denominator = scm;

		result = reduceFrac(result);
	}

	return result;
}

Fraction Topic4::subtractFrac(Fraction f1, Fraction f2) {
	f2.numerator = -f2.numerator;
	
	return addFrac(f1, f2);
}

Fraction Topic4::multiplyFrac(Fraction f1, Fraction f2) {
	Fraction result;
	
	result.numerator = f1.numerator * f2.numerator;
	result.denominator = f1.denominator * f2.denominator;

	result = reduceFrac(result);

	return result;
}

Fraction Topic4::divideFrac(Fraction f1, Fraction f2) {
	Fraction result;

	if (f2.numerator == 0) {
		result.numerator = 0;
		result.denominator = 0;
	}
	else {
		result.numerator = f1.numerator * f2.denominator;
		result.denominator = f1.denominator * f2.numerator;
	}

	result = reduceFrac(result);

	return result;
}

void Topic4::readIntArray(int a[], size_t nElem) {
	for (size_t i = 0; i < nElem; i++) {
		cout << "Integer #" << i << ": ";
		cin >> a[i];
	}
}

size_t Topic4::searchValueInIntArray(const int a[], size_t nElem, int value, int index[]) {
	int occurrences = 0;

	for (size_t i = 0; i < nElem; i++) {
		if (a[i] == value) {
			index[occurrences] = i;
			occurrences++;
		}
	}

	return occurrences;
}

void Topic4::testIntArray() {
	const size_t ARRAY_SIZE = 10;
	int arr[ARRAY_SIZE], index[ARRAY_SIZE];
	int value;
	size_t occurrences;

	cout << "Reading integer array...\n";
	readIntArray(arr, ARRAY_SIZE);
	
	cout << "Enter a value: ";
	cin >> value;
	occurrences = searchValueInIntArray(arr, ARRAY_SIZE, value, index);

	if (occurrences == 0)
		cout << "Value not found in the array.\n";
	else {
		cout << "The value appears " << occurrences << " time(s) in the array.\n";
		cout << "Indexes of occurrences: ";
		for (size_t i = 0; i < occurrences; i++) {
			cout << index[i];
			if (i < occurrences - 1)
				cout << ", ";
		}
		cout << endl;
	}
}

template <typename T> void Topic4::bubbleSort(vector<T> &v) {
	T temp;

	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

/*
void Topic4::bubbleSort(vector<string> &v) {
	string temp;

	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}
*/

void Topic4::testBubbleSort() {
	vector<string> vec;
	size_t size;

	cout << "Size of vector to sort: ";
	cin >> size;
	vec.resize(size);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (size_t i = 0; i < size; i++) {
		cout << "Element #" << i << ": ";
		getline(cin, vec[i]);
	}

	bubbleSort(vec);
	
	for (string name : vec) {
		cout << name << " ";
	}
	cout << endl;
}

int Topic4::binarySearch(const vector<string> &v, string value) {
	int bottom = 0, top = v.size() - 1, middle;
	bool found = false;
	
	while (bottom <= top && !found) {
		middle = (top + bottom) / 2;
		if (v[middle] == value)
			found = true;
		else {
			if (v[middle] < value)
				bottom = middle + 1;
			else
				top = middle - 1;
		}
	}

	if (found)
		return middle;
	else
		return -1;
}

void Topic4::testBinarySearch() {
	vector<string> vec = { "Charles", "David", "Mary", "Nora", "Patrick", "Rachel", "Sharon" };
	string name = "Nathan";

	cout << "Binary search (" << name << "): " << binarySearch(vec, name) << endl;
}

double Topic4::executeOperation(string op) {
	double a, b;
	char c;

	for (int i = 0; i < op.length(); i++) {
		c = op[i];
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			a = stod(op.substr(0, i));
			b = stod(op.substr(i + 1));
			break;
		}
	}

	switch (c) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
}

void Topic4::testExecuteOperation() {
	string op;

	cout << "Enter an operation (A op B): ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, op);
	cout << op << " = " << executeOperation(op) << endl;
}

void Topic4::sortNamesInFile() {
	string fileName, fileNameSorted, name;
	ifstream fr;
	ofstream fw;
	vector<string> names;

	cout << "Enter filename (example.txt): ";
	cin >> fileName;

	fileNameSorted = fileName.substr(0, fileName.length() - 4) + "_sorted.txt";

	fr.open(fileName);
	
	if (!fr.is_open()) {
		cerr << "File " << fileName << " not found.\n";
		return;
	}

	while (!fr.eof()) {
		getline(fr, name);
		names.push_back(name);
	}

	fr.close();

	bubbleSort(names);

	fw.open(fileNameSorted);
	for (size_t i = 0; i < names.size(); i++) {
		fw << names[i];
		if (i < names.size() - 1)
			fw << endl;
	}
	fw.close();
}