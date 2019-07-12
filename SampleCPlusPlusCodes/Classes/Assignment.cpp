#include "Fundamentals.h"
#include <iostream>

// When two classes are assigned by an equal sign, a shallow copy of the content happens. it means that if there's a pointer, 
// only the pointer is moved, and it will be shared among the two classes.
using namespace std;
void assignmentTest(void) {
	MyClass myClass{};
	MyClass myClass1{};

	myClass1 = myClass;

	myClass.arr[0] = 5;
	myClass.str = "Another day";
	*(myClass.ptr) = 100;

	cout << "Class results" << endl;
	std::cout << myClass.arr[0] << endl;
	std::cout << myClass.str << endl;
	std::cout << *(myClass.ptr) << "This is pointer based" << endl;

	cout << "Class1 results" << endl;
	std::cout << myClass1.arr[0] << endl;
	std::cout << myClass1.str << endl;
	std::cout << *(myClass1.ptr) << "It is the same here too" << endl;
	

	// To perform a deepcopy, one must overload the = operator. In there, we can use the memcopy to acually copy a variable.
}

