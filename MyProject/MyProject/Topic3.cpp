#include "Topic3.h"
#include <iostream>
#include <climits>

using namespace std;

void Topic3::selectExercise() {
	cout << "Enter exercise number: ";
	cin >> exercise;

	switch (exercise) {
		case 5:
			break;
		case 7:
			cout << "Max long: " << LONG_MAX << endl;
			cout << "Max factorial possible with long: 12! = " << factorialIter(12) << "\n";
			break;
		case 9:
			cout << "\n[EXERCISE 3.9]\n";
			testIntegration();
			break;
	}

	int num, den, num2, den2, numr, denr;

	/*
	num1 = 1;
	den1 = 2;

	num2 = 0;
	den2 = 10;

	addFrac(num1, den1, num2, den2, numr, denr);
	writeFrac(numr, denr);
	*/

	readFrac(num, den);
	reduceFrac(num, den);
	writeFrac(num, den);
}

bool Topic3::readFrac(int &numerator, int &denominator) {
	int n, d;
	char dash;

	cin >> n >> dash >> d;

	if (cin.fail() || dash != '/' || d == 0) {
		numerator = 0;
		denominator = 0;
		return false;
	}
	else {
		numerator = n;
		denominator = d;
		return true;
	}
}

void Topic3::writeFrac(int numerator, int denominator) {
	cout << numerator << "/" << denominator;
}

void Topic3::reduceFrac(int &numerator, int &denominator) {
	int a, b, gcd;
	
	a = numerator;
	b = denominator;

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
	
	numerator /= gcd;
	denominator /= gcd;
}

void Topic3::addFrac(int num1, int den1, int num2, int den2, int &numr, int &denr) {
	int a, b, scm; // Smallest common multiple
	
	if (den1 != den2) {
		if (num1 == 0) {
			numr = num2;
			denr = den2;
		}
		else if (num2 == 0) {
			numr = num1;
			denr = den1;
		}
		else {
			a = den1;
			b = den2;

			while (a != b) {
				if (a > b)
					a -= b;
				else
					b -= a;
			}
			scm = den1 * den2 / a;

			numr = num1 * (scm / den1) + num2 * (scm / den2);
			denr = scm;
		}
	}
	else {
		numr = num1 + num2;
		denr = den1;
	}

	reduceFrac(numr, denr);
}

long Topic3::factorialIter(int n) {
	long result = 1;
	for (int i = n; i >= 2; i--) {
		result *= i;
	}
	return result;
}

long Topic3::factorialRec(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorialRec(n - 1);
}

int Topic3::recursiveEuclid(int m, int n) {
	if (m % n == 0)
		return n;
	else
		return recursiveEuclid(n, m % n);
}

double Topic3::integrateTrapezium(double f(double), double a, double b, int n) {
	double totalArea = 0;
	double width = (b - a) / n;

	for (int i = 1; i <= n; i++) {
		totalArea += (width / 2) * (f(a + (i - 1) * width) + f(a + i * width));
	}

	return totalArea;
}

void Topic3::testIntegration() {
	auto f1 = [](double x) {return pow(x, 2); };
	auto f2 = [](double x) {return sqrt(4 - pow(x, 2)); };
	double result1, result2;

	cout << "n\tg(x)\th(x)\n";

	for (int n = 2; n <= 1024; n *= 2) {
		result1 = integrateTrapezium(f1, 0, 10, n);
		result2 = integrateTrapezium(f2, -2, 2, n);
		
		cout << n << "\t" << result1 << "\t" << result2 << endl;
	}
}