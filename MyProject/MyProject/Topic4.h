#pragma once
#include <string>

using namespace std;

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
};