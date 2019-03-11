#pragma once

#include <iostream>

using namespace std;

class Topic3 {
public:
	void selectExercise();
private:
	bool readFrac(int &numerator, int &denominator);
	void writeFrac(int numerator, int denominator);
	void reduceFrac(int &numerator, int &denominator);
	
	void addFrac(int num1, int den1, int num2, int den2, int &numr, int &denr);
};