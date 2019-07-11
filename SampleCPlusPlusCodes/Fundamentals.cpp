#include <iostream>
#include <algorithm>

void test(int* a, int b[]) {
	std::cout << sizeof(a) << '\n'; // will print sizeof(int) * array length (20)
	std::cout << sizeof(b) << '\n'; // will print the size of a pointer (4)
}

int compare(const void* arg1, const void* arg2) {
	int* ar1 = (int*)arg1;
	int* ar2 = (int*)arg2;

	if (*(int*)arg1 < *(int*)arg2) return -1;
	if (*(int*)arg1 == *(int*)arg2) return 0;
	if (*(int*)arg1 > * (int*)arg2) return 1;

};


void foo21(int x[][2]) {}
void foo22(int(*x)[2], int row) {}
void foo23(int* x[4], int column) {}
void foo24(int* x, int row, int column) {}
void foo25(int** x) {}

void foo31(int x[][2][3]) {}
void foo32(int** x[3]) {}
void foo33(int(**x)[3]) {}
void foo34(int* (*x)[3]) {}
void foo35(int*** x) {}

void Fundamentals(void) {
	int* x = 0; // pointers can be initialized to zero or null pointer.
	char* ch1 = nullptr;

	//*x = 5; // This assignment is wrong, because we are yet to assign a memory location to the pointer. Hence, we need to declare a variable or array.
		// This is not true for string literals.
	//*++ch1 = *++ch; // The plus takes precedence on either side over star, so avant ajoutant, et apres assignment de val.


	const char* str = "Constant string returning pointer";  // Comme toujours, a string literal returns a pointer, and because strings are constant
					// literals in memory, voilà.


	std::cout << str;

	int y[5] = { 1, 2, 3, 4, 5 };
	int* ptr = y; // So note that y is a pointer. What does it point to? Well, y is both a pointer to an integer, and so is of course y+1.
				// Now what is &y? It is a pointer to an array of five integers, hence int(*arr5int)[5] = &y.
				
				// Now consider y[3][4]. Now, what is y[3]? It is a pointer to an integer, because *y[3] is an integer! Hence, int *ptr = y[3];
				// What is y? It is a pointer to a pointer to an array of four integers, because 
				

	int** ptr2D = &ptr;
	int(*arr5int)[5] = &y;
				// So, is y a pointer to an integer? Yes. But is &y a pointer to pointer to integer? No. It's a pointer to an array 
				// of five integers.
	
	/*Difference. y is fixed, and size of return the actual sizem where as pointer is usually only 4 bites.
	  A fixed array knows how long the array it is pointing to is. A pointer to the array does not.
	  But when passing them to a function, they are the same, either pass y or ptr, they would only point to the first element.
	  Hence, their size in the function would be the same.*/
	std::cout << sizeof(y) << '\n'; // will print sizeof(int) * array length (20)
	std::cout << sizeof(ptr) << '\n'; // will print the size of a pointer (4)

	std::cout << y << '\n'; // will print sizeof(int) * array length (20)
	std::cout << ptr << '\n'; // will print the size of a pointer (4)

	qsort((void*) y, size_t(5), sizeof(int), compare); // size_t is unsigned int

	/* When reading pointers and operators:
		1- () and [] take precedence over * (paranetheses has higher precedence over []).
		2- "go right when you can, go left when you must"
	See this page http://www.unixwiz.net/techtips/reading-cdecl.html.
	Consider the following and note the difference.
		Foo *arr1[2]; // An array of 2 pointers to Foos. In this notation, each element can point to another array.
		Foo (*arr2)[2]; // A pointer of array of 2 of integers. 
		Foo *(*arr3)[2]; // A pointer of array of 2 of pointers to integers arr3=&arr1*/

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
	int (*z2)[2]; // So look, this is fundamental. z2 is a pointer to an array of two intgeres. So I cannot say z2 = w1. Why? because
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
	int (*z4)[1];

	z4 = w3;

		// Example 4: Is this correct? Of course not, because w4 is pointer to a 2*1 array, and cannot be casted to an integer. 
		// int w4[2][1]; int *z4 = w4;
		// But this is correct: int *z4 = w4[1];

	/* Now here's a fundamental fact. When we pass an array to a function, the pointer decays one level. Hence for example:
		1- When we pass an array, it decays to an integer pointer (first element of the row).
		2- When we pass a 2D array, it decays to a pointer to a row.
		3- When we pass a 3D array, it decays to a pointer to 2D array. 
	Hence, when declaring an array as input to a function, we only have to deal with the pointer of a lower dimension. So we could say:
	1- foo(int x[3]) or foo(int *x, int row), the latter is used when we don't know the specific
	2- foo(int x[][3]) or foo(int (*x)[3], int row) or foo(int *x[3], int column) or foo(int **x, int row, int column), 
		the latter is used when we don't know the specifics
	3- foo(int x[][2][3]) or foo(int **x[3], int column, int third), or foo(int (**x)[3], int column, int third),
		foo(int (**x)[3], int row, int column), foo(int *(*x)[3], int row, int third)
		foo(int ***x, int row, int column, int third), the latter is used when we don't know the specifics
		*/

	int w5[4];
	int w6[4][2];
	int w7[4][2][3];

	foo21(w6); // It decays to a pointer to an array of two.
	foo22(w6, 4); // It decays to a pointer to an array of two.
	
	int* w8[4] = { w6[0], w6[1], w6[2], w6[3]};
	foo23(w8, 2); // It decays to a pointer to an array of two.
	
	int* ptr4 = w6[0];
	foo24(ptr4, 4, 2);

	int** ptr42 = &ptr4;
	foo25(ptr42);
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

