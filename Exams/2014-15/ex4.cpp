/* 4A

Static
int p[100];

average(p, 100);

Dynamic
int* p = new int[100];

average(p, 100);

*/

/* 4B

We can throw an exception when we encounter an error inside a constructor using the throw keyword. We
can also include a message to describe the error. This way, when we create an object inside a try-catch block, that 
exception will be caught and we can then handle it however necessary. The file <stdexcept> contains several types of 
exceptions that we can use.

*/

/* 4C

When we allocate memory dynamically in a class (using malloc or new), we must free the memory once the object is
destroyed to avoid a memory leak and allow the program to use that section of memory again. We can do this in the 
destructor, which is called whenever the object is destroyed.

*/

/* 4D

The << operator returns a reference to the operand to its left (commonly an istream) so that we can chain the operator
like so:
cout << first << second << third;
Evaluating from left to right, the first variable is printed, then the << operator returns a reference to cout, so that
the second variable can be printed (cout << second << third) and so forth.

*/

/* 4E

Declaring the < operator in the header as a friend function, we have:
bool operator<(const Student &left, const Student &right) {
	return left.name < right.name;
}

Then we can call sort like so:
sort(studProg.begin(), studProg.end());

*/

/* 4F

We could use vector<Shape*>, since rectangles, triangles and circles are derived from the Shape class.
Assuming the function used to draw the shapes is virtual, we can rely on polymorphism to call the correct
function based on the type of shape.

*/