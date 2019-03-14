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
};