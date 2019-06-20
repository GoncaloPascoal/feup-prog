// 3A
Pluviosity::Pluviosity(int year) {
	vector<vector<int>> tempPluv(12);
	
	for (size_t i = 0; i < tempPluv.size(); i++) {
		int days = numDaysOfMonth(i + 1, year);
		vector<int> tempMonth(days, 0);
		tempPluv[i] = tempMonth;
	}
	
	pluv = tempPluv;
}

// 3B
int Pluviosity::maxPluv() {
	int max = 0;
	
	for (vector<vector<int>>::iterator it1 = pluv.begin(); it1 != pluv.end(); it1++) {
		for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
			if (*it2 > max) {
				max = *it2;
			}
		}
	}
	
	return max;
}

/* 3C

Assuming the localities are objects of a Locality class (otherwise we could simply use a string for the locality name):
multimap<Locality, Pluviosity> pluvs;

The multimap data structure allows for fast access to the values that correspond to a certain key (there is no need to
search like in a vector). Also, we can map several values to the same key. This means we can have the Pluviosity of several
years mapped to a Locality.

*/