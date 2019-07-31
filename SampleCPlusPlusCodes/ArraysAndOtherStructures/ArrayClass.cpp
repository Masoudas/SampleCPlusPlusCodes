#include <array>

using namespace std;
// Didn't quite understand what this class does, but apparently it's the same as the normal arrays defined by the brackets, except that
// it gives some extra functions

void arrayClass(void) {
	
	array<int, 5> arr = { 1, 2, 3, 4, 5 };
	array<int, 5> arr1(arr);

	array<int, 4> arr2;
	cout << "Size of the array is " << arr2.size() << endl;
	cout << "Size of the array is " << arr2.max_size() << endl;

	for (int i = 1; i < 5; i++) {
		arr2[i - 1] = arr1[i];
	}

	array<int, 4> arr3;
	memcpy(arr3.data(), arr.data() + 1, (arr.size() - 1) * sizeof(int)); // Memcopy copies with respect to number of bytes.

	cout << "Copy of the slice: ";
	array<int, 4>::iterator it0;
	for (it0 = arr3.begin(); it0 != arr3.end(); it0++) {
		cout << *it0 << "\t";	// This is kind of amusing!
	}
	cout << endl;



	// Iteration over array.
	array<int, 5>::iterator it;

	if (!arr.empty()) {
		cout << "Normal iteration: ";
		for (it = arr.begin(); it != arr.end(); it++) {
			(*it)++;
			cout << *it << "\t";	// This is kind of amusing!
		}
		cout << endl;
	}

	cout << "Constant iterator: ";
	array<int, 5>::const_iterator it1;
	for (it1 = arr.cbegin(); it1 != arr.cend(); it1++) {
		// (*it1)++; A constant iterator can only be used for iteration, and not for iteration.
		cout << *it1 << "\t";	// This is kind of amusing!
	}
	cout << endl;

	//cout << "Pointer like access is of course not possible" << *arr;
	const array<int, 5>::const_iterator it2 = arr.cbegin();	// A constant iterator cannot even be iterated
	//it2++; Cannot be augmented,
	cout << *it2;
}