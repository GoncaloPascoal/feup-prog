#include "Topic1.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>

using namespace std;

void testOperations() {
	// variable declarations and initialization
	int operand1, operand2, result, answer;
	char operators[4] = { '+','-','*','/' };
	char operation;
	int numCorrectAnswers = 0;
	int maxOperandValue;
	int numOperations;

	// initialize random number generator
	srand((unsigned int)time(NULL));

	cout << "Max operand value: ";
	cin >> maxOperandValue;
	cout << "Number of operations: ";
	cin >> numOperations;

	for (int i = 1; i <= numOperations; i++) {
		// randomly generate operands and operator
		operand1 = rand() % maxOperandValue + 1;
		operand2 = rand() % maxOperandValue + 1;
		operation = operators[rand() % 4];

		// calculate the correct result
		switch (operation)
		{
		case '+':
			result = operand1 + operand2;
			break;
		case '-':
			result = operand1 - operand2;
			break;
		case '*':
			result = operand1 * operand2;
			break;
		case '/':
			result = operand1 / operand2;
			break;
		}

		// ask the answer from the user
		cout << operand1 << " " << operation << " " << operand2 << " ? ";
		cin >> answer;

		// verify if the answer of the user is correct
		if (answer == result) {
			cout << "Correct answer. Congratulations\n";
			numCorrectAnswers++;
		}
		else
			cout << "Wrong answer ...\n";
	}

	//show final result
	cout << "Number of correct answers: " << numCorrectAnswers << endl;

	// classify results
	if (numCorrectAnswers <= int(0.3 * numOperations))
		cout << "VERY BAD ......\n";
	else
		if (numCorrectAnswers <= int(0.5 * numOperations))
			cout << "POOR...\n";
		else
			if (numCorrectAnswers <= int(0.7 * numOperations))
				cout << "FAIR\n";
			else
				if (numCorrectAnswers <= int(0.9 * numOperations))
					cout << "GOOD !\n";
				else
					cout << "EXCELLENT !!!\n";
}

void Topic1::selectExercise() {
	cout << "Enter exercise number: ";
	cin >> exercise;

	switch (exercise) {
		case 1:
			asciiCode();
			break;
		case 2:
			avgAndDeviation();
			break;
		case 3:
			sphereMass();
			break;
		case 4:
			solveLinEqSys();
			break;
		case 5:
			sumTimes();
			break;
		case 6:
			heronTriangleArea();
			break;
	}
}

void Topic1::asciiCode() {
	char c;
	cin >> c;
	cout << int(c);
}

void Topic1::avgAndDeviation() {
	float a, b, c, avg, aDev, bDev, cDev;

	// Get values from user
	cout << "A = ";
	cin >> a;
	cout << "B = ";
	cin >> b;
	cout << "C = ";
	cin >> c;

	// Calculations
	avg = (a + b + c) / 3;
	aDev = a - avg;
	bDev = b - avg;
	cDev = c - avg;

	// Results
	cout << "average = " << fixed << setprecision(3) << avg << endl;
	cout << "A-average = " << aDev << endl;
	cout << "B-average = " << bDev << endl;
	cout << "C-average = " << cDev << endl;
}

void Topic1::sphereMass() {
	double density, radius, mass;
	const double pi = atan(1) * 4;

	cout << "Density (kg/m3) = ";
	cin >> density;
	cout << "Radius (m) = ";
	cin >> radius;

	mass = 4.0 / 3 * density * pi * pow(radius, 3);

	cout << "Mass (kg) = " << mass << endl;
}

void Topic1::solveLinEqSys() {
	float a, b, c, d, e, f, x, y, wronskian;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "d = ";
	cin >> d;
	cout << "e = ";
	cin >> e;
	cout << "f = ";
	cin >> f;

	wronskian = a * e - b * d;

	if (wronskian != 0) {
		x = (c * e - b * f) / wronskian;
		y = (a * f - c * d) / wronskian;

		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	else
		cout << "No solution.\n";
}

void Topic1::sumTimes() {
	int h1, m1, s1, h2, m2, s2, dsum, hsum, msum, ssum;

	cout << "Tempo 1 (horas minutos segundos): ";
	cin >> h1 >> m1 >> s1;
	cout << "Tempo 2 (horas minutos segundos): ";
	cin >> h2 >> m2 >> s2;

	ssum = (s1 + s2) % 60;
	msum = (m1 + m2 + (s1 + s2) / 60) % 60;
	hsum = (h1 + h2 + (m1 + m2 + (s1 + s2) / 60) / 60) % 24;
	dsum = (h1 + h2 + (m1 + m2 + (s1 + s2) / 60) / 60) / 24;

	cout << "Soma dos tempos: " << dsum << " dia(s), " << hsum << " hora(s), " << msum << " minuto(s), " << ssum << " segundo(s).\n";
}

void Topic1::heronTriangleArea() {
	float x1, y1, x2, y2, x3, y3, side1, side2, side3, sperim, area;

	//User input
	cout << "Vertice 1 (x, y): ";
	cin >> x1 >> y1;
	cout << "Vertice 2 (x, y): ";
	cin >> x2 >> y2;
	cout << "Vertice 3 (x, y): ";
	cin >> x3 >> y3;

	//Calculations
	side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	side3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

	sperim = (side1 + side2 + side3) / 2;
	area = sqrt(sperim * (sperim - side1) * (sperim - side2) * (sperim - side3));

	//Outputs result
	cout << "Area: " << area << endl;
}