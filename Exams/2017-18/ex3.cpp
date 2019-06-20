/*
	DISCLAIMER: This is a solution to an exam exercise and is not meant to be run as source code.
*/

// 3A1
float average(const int grades[], int numStudents) {
	int sum = 0;
	for(int i = 0; i < numStudents; i++) {
		sum += grades[i];
	}
	return (float)sum / (float)numStudents;
}

// 3A2
int main() {
	int numStudents;
	
	cout << "Enter the number of students: ";
	cin >> numStudents;
	
	int* grades = new int[numStudents];
	readGrades(grades, numStudents);
	
	cout << "Average: " << average(grades, numStudents) << endl;
	return 0;
}

/* 3B
The find function returns iterator v.end() if the value was not found. If the value was found, 
it returns an iterator pointing to the first occurrence of the value.
*/

if (find(v.begin(), v.end(), "31") != v.end()) {
	cout << "Element was found.\n";
}
else{
	cout << "Element was not found.\n";
}

/* 3C
Sets are a data type that is automatically ordered. Since Position is a data structure that we defined,
the computer doesn't know how to sort the set. To fix this, we could make Position a class and overload
the < operator, specifying how the set should be sorted.
*/

/* 3D (not sure about this question)
The program outputs:
2 3
2
2 3

If virtual was removed, the output would be:
2 3
2
2

Protected means the method or variable can be accessed within the class and all subclasses that are
derived from it while private means the method or variable can only be accessed within that class.
Because of this, if protected in the Base class was replaced with private, the derived class could
no longer access the variable _a, which would cause an error when it tried to print its value.
*/
