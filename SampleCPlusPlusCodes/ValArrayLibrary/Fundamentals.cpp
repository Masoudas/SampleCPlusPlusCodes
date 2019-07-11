#include <iostream>
#include <valarray>
using namespace std;
// This library can be used to generate arrays on which we can perform several mathematical operations.

void Fundamentals(void) {
	int arr[4] = { 10, 20, 30, 40 };
	
	valarray<int> myArray;
	valarray<int> first;                             // (empty)
	valarray<int> second(5);                        // 0 0 0 0 0
	valarray<int> third(10, 3);                      // 10 10 10
	valarray<int> fourth(init, 4);                   // 10 20 30 40
	valarray<int> fifth(fourth);                    // 10 20 30 40
	valarray<int> sixth(fifth[std::slice(1, 2, 1)]);  // 20 30

	cout << sixth.max();
	cout << sixth.sum();

	cout << cos(sixth);
}