#include <iostream>
#include <algorithm>


void test(int* a, int b[]) {
	std::cout << sizeof(a) << '\n'; // will print sizeof(int) * array length (20)
	std::cout << sizeof(b) << '\n'; // will print the size of a pointer (4)
}

int compare(const void* arg1, const void* arg2) {
	// Note that this point to constant void, not constant pointer to void.

	int* ar1 = (int*)arg1;
	int* ar2 = (int*)arg2;

	if (*(int*)arg1 < *(int*)arg2) return -1;
	if (*(int*)arg1 == *(int*)arg2) return 0;
	if (*(int*)arg1 > * (int*)arg2) return 1;

};

void foo11(int x[], unsigned int row) {}; // So we get an array of an arbitrary size.
void foo12(int(*x)[4]) { // We make sure to give the address to an array of 4 integers.
	for (int i = 0; i < 4; i++) std::cout << "Element " << i << " of 1D array is " << *(*x + i) << std::endl;

};

void foo21(int x[][2]) {};
void foo22(int(*x)[2], int row) {};

void foo23(int* x[4], int column) {};
void foo24(int* x, int row, int column) {};
void foo25(int** x) {};
void foo26(int x[4][2]) {};	// What happens when you give a first dimension? It does not enforce the first dimension, just the second. Why? I think
							// it has historical reason.
void foo27(int(*x)[4][2]) {
	// So because x is a pointer, then *x is the first level of dereferencing. After that, we have a 2D array at our hand, so do whatever
	// you want with *x.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << "Element (" << i << "," << j << ") " << " of 2D array is " << *(*(*x + i) + j) << std::endl;
		}
	}
};


void Fundamentals(void) {
	int* x = 0; // pointers can be initialized to zero or null pointer.
	char* ch1 = nullptr;

	//*x = 5; // This assignment is wrong, because we are yet to assign a memory location to the pointer. Hence, we need to declare a variable or array.
		// This is not true for string literals.
	//*++ch1 = *++ch; // The plus takes precedence on either side over star, so avant ajoutant, et apres assignment de val.


	int intVar = 10;
	int *const constPtr = &intVar;	// This is a constant pointer Note that star is attached to const, hence we know that this a constant pointer.

	char str3[] = "Constant string returning pointer";  // This is allowed, because it is a form of initialization.
	
	char const *str = "Constant string returning pointer";  // Comme toujours, a string literal returns a pointer, and because strings are constant
					// literals in memory, voilà. char const * is a pointer to constant, so is char const*, but char* const str, is constant pointer.
					// const char *const is constant pointer to constant.
	std::cout << str;

	char const *str1 = "Constant string returning pointer";
	
	//constPtr++; This is impossible.
}


void increase(void* data, int psize)
{
	if (psize == sizeof(char))
	{
		char* pchar; pchar = (char*)data; ++(*pchar);
	}
	else if (psize == sizeof(int))
	{
		int* pint; pint = (int*)data; ++(*pint);
	}
}

void VoidPointers(void) {
	/* Allow pointer definition without assigning a type, though for access, we need to define a pointer of a proper type.*/
	int x = 10;

	increase(&x, sizeof(int));

	std::cout << x;

	// Now read pointer increment

}

void PointersAndArrays(void) {
	int y[5] = { 1, 2, 3, 4, 5 };
	int* ptr = y; // Arrays and pointers aren't the same thing. So y is not a pointer. But we can cast them to pointers to integers in the case of 
				 // 1D arrays.

				// Question: What is &y? Note that y is a chunk of 5 integers here in memory. Hence, &y is the address of something that refers to 
				// a chunk of five integers in memory. Hence the following assignment is correct.

	int(*arr5int)[5] = &y;	// As we shall see below, arr5int is a pointer to an array of 5 integers.
							// So this is another view to y, we can use a pointer an array of 5 int.

	int** ptr2D = &ptr; // This is also true. Because ptr is a pointer to integer.

	std::cout << sizeof(y) << '\n'; // will print sizeof(int) * array length (or 20)
	std::cout << sizeof(ptr) << '\n'; // will print the size of a pointer (or 4)

	std::cout << y << '\n'; // Will print the same address as ptr.
	std::cout << ptr << '\n';

	qsort((void*)y, size_t(5), sizeof(int), compare); // size_t is unsigned int

	/* When reading pointers and operators:
		1- () and [] take precedence over * (paranetheses has higher precedence over []).
		2- "go right when you can, go left when you must"

	See this page http://www.unixwiz.net/techtips/reading-cdecl.html.
	Consider the following and note the difference.
		Foo *arr1[2]; // An array of 2 pointers to Foos. In this notation, each element can point to another array.
		Foo (*arr2)[2]; // A pointer to an array of 2 of integers.
		Foo *(*arr3)[2]; // A pointer to an array of 2 pointers to integers arr3=&arr1*/

		// Examples1:
			/*We can use an array of pointers to integers to point to an array to add another level of indirection. Why is this useful? */
	int* z1[5] = { y, y + 1, (y + 2), (y + 3), (y + 4) };

	for (int i = 0; i < 5; i++) {
		std::cout << *(y + i) << "\n";
		std::cout << *(z1[i]) << "\n";
	}

	// Examples2:
		/* Now, we can define a pointer to an array of integers of size 2 */
	int w1[2] = { 1, 2 };
	int(*z2)[2];	// So look, this is fundamental. z2 is a pointer to an array of two intgeres. So I cannot say z2 = w1. Why? because
					// w1 is a pointer to an integer, not a pointer to an array of 2 integers (although it is the beginning of an array). 
					// So what is "a" where a = &w1? Is it a pointer to a pointer to an int? No. it is a pointer toan array of two integers. 
					// But we can cast it like this int *ptr = &w1. Now it's a pointer to an int. Now we can use a pointer to pointer to point to it.

	z2 = &w1; // interesting, and what is the point? well, in this case, we know that x exactly points to two elements. 

	int* ptr2 = w1;	// Now we literally transform it to a pointer to an int.
	int** z3 = &ptr2;

	int w2[3] = { 1, 2, 3 };
	//z2 = &w2; // Obviously this would not work!

		// Example3:

	int w3[2][1] = { {1}, {2} };
	int(*z4)[1];	// z4 is a pointer to to an array of one integer. Hence naturally the following assignment.
	z4 = w3;
	// Of course to be very specific, we can have the following:
	int(*z5)[2][1] = &w3;
	// w3 = *z5; Note that this assignment is wrong again. We cannot indirectly initialize an array of integers. We are just allowed to individually assign
	// variables and stuff.

	/* Now here's a fundamental fact. When we pass an array to a function, the pointer decays one level. Hence for example:
		1- When we pass an array, it decays to an integer pointer (first element of the row).
		2- When we pass a 2D array, it decays to a pointer to a row.
		3- When we pass a 3D array, it decays to a pointer to 2D array.

	So what it comes down to is what do we expect from the function. Say I want to pass any sort of 1D array to a function and perform
	some manipulation on it. In that case, I define foo(int [], unsigned int row), or foo(int* , unsigned int row).
	But let's say I want to make sure that I pass an array of certain size, using only one argument. I'd write foo(int (*)[n]).*/

	int w5[4] = { 1,2,3,4 };
	int w9[5];

	foo11(w9, 5);	// This as we know is normal
	foo12(&w5);
	//foo12(&w9); // Of course this is incorrect.


	/* We have the same story when it comes to 2D arrays. Hence, normally we decay to the pointer an array to a column when we pass it.
		But we can also pass a pointer to pointer (WHICH IS NOT THE ARRAY NAME DIRECTLY), or a pointer to the entire object.*/

	int w6[4][2] = { {1,2}, {3,4}, {5,6}, {7,8} };


	foo21(w6); // It decays to a pointer to an array of two.
	foo22(w6, 4); // It decays to a pointer to an array of two.

	int* w8[4] = { w6[0], w6[1], w6[2], w6[3] };
	foo23(w8, 2); // It decays to a pointer to an array of two.

	int* ptr4 = w6[0];
	foo24(ptr4, 4, 2);

	int** ptr42 = &ptr4;
	foo25(ptr42);

	foo26(w6);
	foo27(&w6);

}