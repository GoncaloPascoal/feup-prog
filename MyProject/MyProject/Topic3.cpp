#include "Topic3.h"

void Topic3::selectExercise() {
	int num1, den1, num2, den2, numr, denr;

	num1 = 1;
	den1 = 2;

	num2 = 0;
	den2 = 10;

	addFrac(num1, den1, num2, den2, numr, denr);
	writeFrac(numr, denr);

	/*
	readFrac(num, den);
	reduceFrac(num, den);
	writeFrac(num, den);
	*/
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