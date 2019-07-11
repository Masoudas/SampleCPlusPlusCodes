#include <iostream>

void PointerIncrement(void) {
	/* When we augment a pointer, depending on how many bites it has, it will increase 1, or 2 or more.
	Conclusion, pointers are augmented as a multiple of bytes.*/
	int x = 1;
	short w = 1;
	char c = 1;
	long l = 10;

	int* int1 = &x;
	short* s = &w;
	char* ch = &c;
	long* lon1 = &l;

	std::cout << (int)ch << "\n";
	std::cout << "augmenting char " << (int) ++ch << "\n";

	std::cout << s << "\n";
	std::cout << "augmenting short " << ++s << "\n";

	std::cout << int1 << "\n";
	std::cout << "augmenting int " << ++int1 << "\n";

	std::cout << lon1 << "\n";
	std::cout << "augmenting long" << ++lon1 << "\n";

	
	
	/* Another fascinating point: You can't arbitrarily increase and decrease pointers and then assign to them.
	Because when you increase or decrease the pointer, it will go to another location in the memory, so you cannot access it!
	Note that here we are talking about a memory space that has not been assigned before hand. If the memory is assigned 
	before hand (using for example an array) then there's no issue!*/
	int x1 = 10;
	int y = 20;

	int* ptr;
	ptr = &x1;
	std::cout << ptr << "\n";
	std::cout << *ptr << "\n";

	// Suppose we now increased the pointer to go to another location and store the y
	++ptr = &y;	// Now, ptr = ptr + 1. 
	std::cout << ptr << "\n";
	std::cout << *ptr << "\n";

	// Now intrestingly, if we say --ptr, we won't go back to the same location in the memory. The machine allocates a
	// a new location in the memory for this, and does not go back to the old location! And the next line returns an error.
	// So don't play with pointers once you define them!
	std::cout << --ptr << "\n";
	std::cout << *ptr << "\n";

	// The following however is correct.
	int arr[2] = { 1, 1 };
	int* ptr1 = arr;

	for (int i = 0; i < 2; i++) std::cout << *(ptr1 + i);
}