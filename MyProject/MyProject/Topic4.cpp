#include "Topic4.h"
#include <iostream>

void Topic4::selectExercise() {
	char c[] = "NaOH";
	string cpp = "NaOH";
	cout << "Cstring\tC++ string\n";
	cout << isHydroxide(c) << "\t" << isHydroxide(cpp) << endl;
}

bool Topic4::isHydroxide(char compound[]) {
	int length = strlen(compound);
	return (compound[length - 2] == 'O' && compound[length - 1] == 'H');
}

bool Topic4::isHydroxide(string compound) {
	return compound.substr(compound.length() - 2) == "OH";
}