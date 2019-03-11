#include "Topic2.h"

void Topic2::selectExercise() {
	cout << "Enter exercise number: ";
	cin >> exercise;

	switch (exercise) {
		case 1:
			cout << "\n[EXERCISE 2.1]\n";
			betterLinEqSys();
			break;
		case 2:
			cout << "\n[EXERCISE 2.2]\n";
			testTriangle();
			break;
		case 3:
			cout << "\n[EXERCISE 2.3]\n";
			basicCalculator();
			break;
		case 4:
			cout << "\n[EXERCISE 2.4]\n";
			float weight;
			cout << "Merchandise weight (in grams): ";
			cin >> weight;
			cout << "Cost of transportation: " << merchTransportCost(weight) << " euros\n";
			break;
		case 6:
			cout << "\n[EXERCISE 2.6]\n";
			checkPrime();
			break;
		case 7:
			cout << "\n[EXERCISE 2.7]\n";
			trigTable();
			break;
		case 9:
			cout << "\n[EXERCISE 2.9]\n";
			intSequence();
		default:
			break;
	}
}

void Topic2::betterLinEqSys() {

}

void Topic2::testTriangle() {
	double n1, n2, n3, ord1, ord2, ord3;
	bool triangle;

	cout << "Enter 3 numbers: ";
	cin >> n1 >> n2 >> n3;

	if (n1 >= n2) {
		if (n1 >= n3) {
			ord1 = n1;
			if (n2 >= n3) {
				ord2 = n2;
				ord3 = n3;
			}
			else {
				ord2 = n3;
				ord3 = n2;
			}
		}
		else {
			ord1 = n3;
			ord2 = n1;
			ord3 = n2;
		}
			
	}
	else if (n2 >= n3){
		ord1 = n2;
		if (n1 >= n3) {
			ord2 = n1;
			ord3 = n3;
		}
		else {
			ord2 = n3;
			ord3 = n1;
		}
	}
	else {
		ord1 = n3;
		ord2 = n2;
		ord3 = n1;
	}

	triangle = (ord2 + ord3) > ord1;

	cout << "Biggest number: " << ord1 << "\nSmallest number: " << ord3 << endl;
	cout << "Ordered from biggest to smallest: " << ord1 << ", " << ord2 << ", " << ord3 << endl;
	
	if (triangle) {
		cout << "The numbers can be the length of the sides of a triangle.\n";
	}
	else {
		cout << "The numbers cannot be the length of the sides of a triangle.\n";
	}
}

void Topic2::basicCalculator() {
	double n1, n2, result;
	char op;

	cout << "Enter an operation (num op num): ";
	cin >> n1 >> op >> n2;

	switch (op) {
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case '*':
			result = n1 * n2;
			break;
		case '/':
			result = n1 / n2;
			break;
	}

	cout << n1 << " " << op << " " << n2 << " = " << result << endl;
}

float Topic2::merchTransportCost(float weight) {
	float adWeight; // Additional weight
	int ad; // Times to add cost

	if (weight < 500)
		return 5;
	else if (weight <= 1000) {
		adWeight = weight - 500;
		ad = int(adWeight) / 100;

		if (adWeight - ad * 100 > 0)
			ad++;

		return 5 + 1.5 * ad;
	}
	else {
		adWeight = weight - 1000;
		ad = int(adWeight) / 250;

		if (adWeight - ad * 250 > 0)
			ad++;

		return 12.5 + 5 * ad;
	}
}

bool isPrime(int num) {
	if (num <= 1) {
		return false;
	}
	else {
		for (int i = 2; i <= int(sqrt(num)); i++) {
			if (num % i == 0) {
				return false;
			}
		}
		return true;
	}
}

void Topic2::checkPrime() {
	int userNum;

	cout << "Enter a positive integer: ";
	cin >> userNum;

	if (isPrime(userNum))
		cout << "The number is prime.\n";
	else
		cout << "The number is not a prime.\n";

	int counter = 1;
	int num = 2;

	//Prints the first 100 primes
	while (counter <= 100) {
		if (isPrime(num)) {
			cout << num << " ";
			counter++;
		}
		num++;
	}

	cout << "\n\n\n";

	// Prints all primes up to 10000
	for (int i = 2; i < 10000; i++) {
		if (isPrime(i)) {
			cout << i << " ";
		}
	}
}

void Topic2::trigTable() {
	double pi = atan(1) * 4;
	double lowerBound, upperBound, step, angle, sine, cosine, tangent;
	bool xAxis, yAxis;
	
	cout << "Enter lower bound, upper bound and step: ";
	cin >> lowerBound >> upperBound >> step;

	angle = lowerBound;

	cout << "\nang\tsen\t\tcos\t\ttan\n";

	while (angle <= upperBound) {
		xAxis = (angle / 180) == int(angle / 180); // Angle is of form (k * 180)
		yAxis = ((angle - 90) / 180) == int((angle - 90) / 180); // Angle is of form (90 + k * 180)

		if (xAxis)
			sine = 0;
		else
			sine = sin(angle * pi / 180);

		if (yAxis)
			cosine = 0;
		else
			cosine = cos(angle * pi / 180);

		cout << defaultfloat << angle << "\t";
		cout << fixed << setprecision(6) << sine << "\t" << cosine << "\t";
		
		if (xAxis) { 
			tangent = 0;
			cout << tangent << endl;
		}
		else if (yAxis)
			cout << "infinite\n";
		else {
			tangent = tan(angle * pi / 180);
			cout << tangent << endl;
		}

		angle += step;
	}
}

void Topic2::intSequence() {

	int num, sum = 0, length = 0;
	int smallest = numeric_limits<int>::max();
	int biggest = numeric_limits<int>::min();
	float average;
	
	while (true) {
		cout << "Enter an integer (CTRL Z to end): ";
		cin >> num;
		
		if (cin.fail()) {
			if (cin.eof())
				break;
			else {
				cout << "\n Invalid input. Please enter an integer.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else {
			sum += num;
			
			if (num < smallest)
				smallest = num;
			if (num > biggest)
				biggest = num;

			length++;
		}
	}

	if (length > 0)
		average = float(sum) / length;
	else
		average = 0;

	cout << "Sum: " << sum << "\nAverage: " << average << "\nBiggest: " << biggest << "\nSmallest: " << smallest << endl;
}

double heronSquareRoot(double num, double delta, int maxIters) {
	int numIters = 0;
	double diff;
	double est = num / 2;

	while (true) {
		diff = abs(num - pow(est, 2));

		if (diff < delta || numIters > maxIters)
			return est;
		else {
			est = (est + num / est) / 2;
			numIters++;
		}
	}
}

void Topic2::heronSqrtUser() {
	double num, delta;
	int maxIters;

	cout << "Number, delta, max iterations: ";
	cin >> num >> delta >> maxIters;

	cout << "Heron sqrt: " << heronSquareRoot(num, delta, maxIters);
}