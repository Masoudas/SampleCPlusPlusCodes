#include <iostream>

// Because the reference the to the variable exists outside of the local function, it will not be deleted from memory.
int* pointerRetuner(void);
int& referenceRetuner(void) {
	int y = 10;
	int& x = y;
	return x;
}

int Execute(void) {
	std::cout << *pointerRetuner();
	*pointerRetuner() = 10;
	referenceRetuner() = 10;
	std::cout << referenceRetuner();
	return 0;
}


int* pointerRetuner(void) {
	int x = 10;
	return &x;
}

