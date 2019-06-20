// 2A
void Student::setGrades(double shortExam, double project, double exam) {
	this->shortExam = shortExam;
	this->project = project;
	this->exam = exam;
	
	double temp = (shortExam * weightShortExam + project * weightProject + exam * weightExam) / 100.0;
	temp += 0.5;
	
	finalGrade = (int)temp;
}

/*

static int weightShortExam = 20, weightProject = 30, weightExam = 50;

The weights of each element will not change from student to student. Because of this, it makes sense to make them
static, since they will only be initialized once and their value will be the same for all students.

*/

// 2B
#include <iostream>
#include <string>

using namespace std;

int main() {
	string code, name;
	double shortExam, project, exam;
	
	cout << "Student code? "; getline(cin, code);
	cout << "Student name? "; getline(cin, name);
	cout << "Short exam grade? "; cin >> shortExam;
	cout << "Project grade? "; cin >> project;
	cout << "Exam grade? "; cin >> exam;
	
	Student s(code, name);
	s.setGrades(shortExam, project, exam);
	
	return 0;
}

// 2C
void showApproved(ostream &out, const vector<Student> &students) {
	int fg;

	for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
		fg = (*it).getFinalGrade();
		if (fg >= 10) {
			out << setw(50) << (*it).getName() << " " << fg << endl;
		}
	}
}
