#pragma once

class Topic3 {
public:
	void selectExercise();
private:
	short exercise;

	double round(double x, unsigned n);
	void testRound();

	bool readFrac(int &numerator, int &denominator);
	void writeFrac(int numerator, int denominator);
	void reduceFrac(int &numerator, int &denominator);
	
	void addFrac(int num1, int den1, int num2, int den2, int &numr, int &denr);

	long factorialIter(int n);
	long factorialRec(int n);
	int recursiveEuclid(int m, int n);
	double integrateTrapezium(double f(double), double a, double b, int n);
	void testIntegration();
};