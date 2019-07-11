#include <iostream>

// Because the reference the to the variable exists outside of the local function, it will not be deleted from memory.
int* referenceReturner(void);

int Execute(void) {
	std::cout << *referenceReturner();
	return 0;
}


int* referenceReturner(void) {
	int x = 10;
	return &x;
}
