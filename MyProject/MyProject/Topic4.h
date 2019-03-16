#pragma once
#include <string>

using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

class Topic4 {
public:
	void selectExercise();
private:
	short exercise;

	bool isHydroxide(char compound[]); // C string version
	bool isHydroxide(string compound); // C++ string version
	bool sequenceSearch(string s, int nc, char c);
	void testSequenceSearch();
	void decompose(string compound);
	string normalizeName(string name);
	
	Fraction readFrac();
	void writeFrac(Fraction f);
	Fraction reduceFrac(Fraction f);
	Fraction addFrac(Fraction f1, Fraction f2);
	Fraction subtractFrac(Fraction f1, Fraction f2);
	Fraction multiplyFrac(Fraction f1, Fraction f2);
	Fraction divideFrac(Fraction f1, Fraction f2);

	void readIntArray(int a[], size_t nElem);
	size_t searchValueInIntArray(const int a[], size_t nElem, int value, int index[]);
	void testIntArray();
};