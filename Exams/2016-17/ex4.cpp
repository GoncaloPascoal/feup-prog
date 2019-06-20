// 4A
int readNumber(string msg) {
	// ...
	cout << msg; cin >> number;
	// ...
}

int grade = readNumber("Grade ? ");

float readNumber(string msg) {
	// ...
	cout << msg; cin >> number;
	// ...
}

float grade = readNumber("Grade ? ");

/* 4B

Since the Date constructor has default values for its parameters, we can make the declaration Date date1;
In this case, since we didn't specify any values for the parameters, the object would have the default values 
y = 1, m = 1 and d = 1.

*/

/* 4C

We could use int** img to represent the image. This would effectively be a pointer an array of int pointers, each
of which would be pointing to an array of ints. In short, this represents a two-dimensional integer array. In the
Image constructor we would have to allocate memory for nLins integer arrays and in each of those arrays allocate memory
for nCols ints (for example, using new).

We would also have to create a destructor to free the memory we allocated when the object is destroyed, otherwise
the two-dimensional array would remain on the heap - we would have a memory leak.

*/

// 4D
Image::Image(size_t nLins = 0, size_t nCols = 0, int pixVal = 0) {
	img = new int*[nLins];
	
	for(size_t i = 0; i < nLins; i++) {
		img[i] = new int[nCols];
		for (size_t j = 0; j < nCols; j++) {
			img[i][j] = pixVal;
		}
	}
}

/* 4E

We can see in the template of the STL sort function that it requires RandomAccessIterators (meaning iterators
that can be used to access any element of the container, for example it + 4 or it - 3). The list container doesn't
support this type of iterators which means it can't be sorted using the STL sort function.

*/

/* 4F

Declaring a virtual function as equal to 0 makes it a pure virtual function. This means the function must
be overridden in every subclass that is derived from the Shape class. This makes sense in the context of
the problem, since it's impossible to draw a shape without knowing if it's a rectangle, triangle, circle, etc.

*/