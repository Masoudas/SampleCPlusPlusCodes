#include <iostream>
using namespace std;

void swap(int&, int&);
void swapRef(int*&, int*&);

void Fundamentals(void) {
	/* Reference types, as opposed to pointers, carry the address to their own memory space. Hence, they don't have the extra indirection.*/
	int var = 10;
	int& ref = var;	// var is stored in some part of  the memory. ref now carries the address of that memory part. Pointers on the other hand,
					// carry the address of anothe variable.

	// While dereferencing, reference types don't need a dereferencing operator.
	cout << ref << endl;
	
	ref = ref + 1;
	cout << ref << endl;

	// Here's an interesting example, creating a foreach type loop, where we can manipulate each element.
	int x[2] = { 1, 2 };
	for (int& y : x) {
		y = y * 2;
	}
	cout << x[0] << "and " << x[1] << endl;

	int var2 = 10;
	int var3 = 5;
	cout << "Before swap " << var2 << "and " << var3 << endl;
	swap(var2, var3);
	cout << "After swap " << var2 << "and " << var3 << endl;

	// A pointer to a reference does not make sense. This is because &y is just an alias for the address of a variable.
	// Hence a pointer to an alias does not make sense apparently. reference to a pointer does make sense though. It will behave like a
	// pointer to pointer basically.

	// Question: Why is it int *&ptr and not &*ptr? Well, apparently, the alias here has to be attached to the variable. This now reads
	// the address of the pointer, not the reference to a pointer. For & to be interpreted as alias for a reference variable, we need to
	// attach it to the variable. Hence, int *&ptr is interpreted as reference to a pointer, not pointer to a reference.
	int* ptr2 = &var2;
	int* ptr3 = &var3;
	
	int*& ref2 = ptr2;
	int*& ref3 = ptr3;
	
	cout << "Before swap " << ref2 << "and " << ref3 << endl;
	swapRef(ptr2, ptr3);
	cout << "After swap " << var2 << "and " << var3 << endl;

}

void swap(int& x, int& y) {
	// When passing reference types as arguments, the address is passes, so the content is affected. Not passed by just value.
	int w;
	w = x;
	x = y;
	y = w;
}

void swapRef(int*& x, int*& y) {
	// What is the use? Because this a reference to a pointer, we can actually change the pointers.
	// This is the same as using pointers to pointers.
	int*& z = x;
	x = y;
	y = z;

}