#include "Topic1.h"
#include "Topic2.h"
#include "Topic3.h"
#include "Topic4.h"

using namespace std;

int main() {
	bool isDone = false;
	short choice;

	while (!isDone) {
		cin.clear();
		do {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\x1B[2J\x1B[H"; // Clears the screen
			}
			cout << "Enter category number (0 to exit): ";
			cin >> choice;
		} while (cin.fail());

		switch (choice) {
			case 0:
				isDone = true;
				break;
			case 1:
				Topic1 obj1;
				obj1.selectExercise();
				break;
			case 2:
				Topic2 obj2;
				obj2.selectExercise();
				break;
			case 3:
				Topic3 obj3;
				obj3.selectExercise();
				break;
			case 4:
				Topic4 obj4;
				obj4.selectExercise();
				break;
		}
	}
	return 0;
}