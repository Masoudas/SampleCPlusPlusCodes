#include <stdio.h>
#include <iostream>

void lvaluesAndrvalues(void) {
	/* An lvalue(locator value) represents an object that occupies some identifiable location in memory (i.e.has an address).
		rvalues are defined by exclusion, by saying that every expression is either an lvalue or an rvalue.
		Therefore, from the above definition of lvalue, an rvalue is an expression that does not represent
		an object occupying some identifiable location in memory */

		// 4 = var; This is incorrect, because var is not defined (rvalue) and so is 4 in this particular case!
		// (var + 1) = 4; // ERROR! Because var+1 does not occupy a place in memory.

		// We can use the dereference operator to turn and rvalue into an lvalue.
	int arr[] = { 1, 2 };
	int* p = &arr[0];
	*(p + 1) = 10;   // OK: p + 1 is an rvalue, but *(p + 1) is an lvalue

	// Conversely, the unary address - of operator '&' takes an lvalue argument and produces an rvalue :
	int var = 10;
	//int* bad_addr = &(var + 1); // ERROR: lvalue required as unary '&' operand. Right side is now an rvalue.
}

int staticVar; 
void FundamentalTypes(void) {
	/*  A variable defined outside is a static, its value remains in the memory throughout the execution time of the code.
		The following are auto variables, meaning they are defined inside a block of code. Auto variables are not
		automatically initialized, they have to be initialized. Static variables (variables that are defined outside a function) are
		always initialized to zero.
		The size of all basic types (except for char which is always 1 byte in every machine) is at least the size
		that we know they have. For example int is at least 4 bytes. This is to allow flexibility over different machines.
		Repetition of declaration is not allowed.*/


	char ch = 'a'; // Remember that it will always return the pointer to string.
	
	const char* ch2 = "String";
	char* ch3;
	//ch3 = "string"; For some reason, this does not work either.
	auto ch4 = "a";	// Using auto for automatic type inference.
	char string[] = "why like this?";

	//string = "Like this too?"; Does not work either
	//ch2 = 's';

	
	
	char ch1;
	// std::cout << ch1; Does not allow printing!

	short b;
	// std::cout << b; No uninitialized prining
	// b += 1; or àjoutation

	int x=5;
	unsigned int y=10;

	long w=10;
	long long w1=20;

	double w2 = 10.2;

	w = w + x;	// Promotion happens
	w2 = w2 + w; // Promotion
	w = w + w2;
}


#include <string>
using namespace std;
void stringManipulation(void) {
	/* Can use string type to manipulate strings. It's in the std namespace*/
	std::string str1 = "My string";
	string str2 = "My other string";

	str2 = str1 + str2;

	// Notice the difference!!! Why?
	int x[2] = { 1, 2 };
	cout << x[0] << 'a ' << x[1] << endl;
	cout << x[0] << "a" << x[1] << endl;

}