Date::Date(int y = 1, int m = 1, int d = 1) {
	this->y = y;
	this->m = m;
	this->d = d;
}

bool operator<(const Date& left, const Date& right) {
	string s1 = left.y.to_str() + left.m.to_str() + left.d.to_str();
	string s2 = right.y.to_str() + right.m.to_str() + right.d.to_str();
	return (s1 < s2);
}

istream & operator>>(istream & f, Date & date) {
	vector<string> elems;
	string input, elem;
	
	getline(f, input);
	istringstream iss(input);
	
	while(!iss.eof()) {
		getline(iss, elem, '-');
		elems.push_back(elem);
	}
	
	if(elems.size() == 3) {
		date.y = stoi(elems[0])
		date.m = stoi(elems[1])
		date.d = stoi(elems[2])
		if (date.y <= 0 || date.m <= 0 || date.d <= 0) {
			throw runtime_error("invalid Date");
		}
	}
	else{
		throw runtime_error("invalid Date");
	}
	
	return f;
}

int main() {
	Date d1, d2;
	
	cout << "Enter first date: ";
	try {
		cin >> d1;
	} catch (runtime_error &error) {
		cout << error.what();
		exit(1);
	}
	
	cout << "Enter second date: ";
	try {
		cin >> d2;
	} catch (runtime_error &error) {
		cout << error.what();
		exit(1);
	}
	
	if (d1 < d2) {
		cout << d1 << " is before " << d2 << endl;
	}
	else if (d1 == d2) {
		cout << d1 << " is equal to " << d2 << endl;
	}
	else {
		cout << d1 << " is after " << d2 << endl;
	}
	
	return 0;
}