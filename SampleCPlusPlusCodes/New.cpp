#include <iostream>

// Using the new keyword allows memory allocation during run-time.
// If no memory exists, it throws an exception. The memory is allocated from the heap.

void UsingNew(void) {
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

	delete[] ptr;	// Delete the memory. Note that delete is ONLY FOR DELETING DYNAMICALLY ASSIGNED OBJECTs, OTHERWISE YOU GET AN ERROR.
	// delete ptr;	// Delete the memory of a single element.
}