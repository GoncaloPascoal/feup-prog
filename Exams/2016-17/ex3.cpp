
// 3A
int Image::getPixel(size_t lin, size_t col);

// 3B
Image Image::getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) {
	Image region(nLins, nCols);
	
	for (size_t i = 0; i < nLins; i++) {
		for (size_t j = 0; j < nCols; j++) {
			region.setPixel(i, j, img.getPixel(i + lin, j + col));
		}
	}
	
	return region;
}

/* 3C

Because we want to efficiently access images from a certain date, we should use
a multimap<Date, Image>. This allows association of several images to a date and since
the dates are the keys in this multimap, we can efficiently access the images that
correspond to a certain date.

*/

// 3D
#include <map>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
	Date d;
	multimap<Date, Image> images;

	cout << "Enter a date: ";
	try {
		cin >> d
	} catch (runtime_error &error) {
		cout << error.what();
		exit(1);
	}
	
	Image img;
	string filename;
	cout << "Enter a filename (empty string to stop)." << endl;
	while (true) {
		cin >> filename;
		if (filename.empty()) {
			break;
		}
		else {
			img.read(filename);
			images.insert(make_pair(d, img));
		}
	}

	return 0;
}

/* 3E

Add template<typename T> at the start of the class

Replace the lines:
	Image(size_t nLins = 0, size_t nCols = 0, int pixVal = 0);
	void setPixel(size_t lin, size_t col, int pixVal);
	int getPixel(size_t lin, size_t col);
	vector<vector<int>> img;
with:
	Image(size_t nLins = 0, size_t nCols = 0, T pixVal = 0);
	void setPixel(size_t lin, size_t col, T pixVal);
	T getPixel(size_t lin, size_t col);
	vector<vector<T>> img;

*/