#include <array>
#include <iostream>

#include "HeaderFiles/header.h"	// Cool

using namespace std;
// Didn't quite understand what this class does, but apparently it's the same as the normal arrays defined by the brackets, except that
// it gives some extra functions

void main(void) {
	SimpleStruct example = { 1, "string" };
	Child child = Child();
	cout << child.var;

	int len;
	std::cout << "Length please: ";
	std::cin >> len;
	int* ptr;
	ptr = new int[len];	// Allows dynamic memory allocation which otherwise would have been impossible.

	std::cout << "Another length please: ";
	std::cin >> len;
	int* ptr2;
	ptr = new (std::nothrow) int[len];	// Allows dynamic memory allocation which otherwise would have been impossible.

	if (ptr != nullptr) {
		std::cout << "Pointer was allocated";
	}

}