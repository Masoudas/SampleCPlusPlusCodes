#include <iostream>

void PointerToPointer1(void) {
	/* First, create an array of pointers. Then, assign an array to each pointer. Finally, you can use a
	pointer to pointer to move the thing around. Dynamic on one columns only*/

	// Danger: We don't know how many elements each column holds.
	int(**ptr);
	int* arr[2];

	int arr1[3] = { 1, 2, 4 };
	int arr2[2] = { 1, 2 };

	arr[0] = arr1;
	arr[1] = arr2;

	ptr = arr;

	std::cout << **ptr << "\n"; // First element of the first array.
	std::cout << *(*(ptr++) + 1) << "\n"; // Second element of the second array.

}

